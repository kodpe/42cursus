#include "Server.hpp"

void	Server::show_clients(void)
{
	int	size(30);

	// L1
	px(1,"\u2554"); 
	px(size,"\u2550");
	px(1,"\u2557\n");

	// L2
 	px(1, "\u2551");
	px(size-23, " ");
	std::cerr << "\033[33m clients online \033[0m";
	px(size-23, " ");
	px(1, "\u2551\n");

	// L3
	px(1,"\u2560");
	px(size,"\u2550");
	px(1,"\u2563\n");

	// L4 -> L4 + nb clients
	std::map< int, Client >::iterator	it;
	for (it = _clients.begin(); it != _clients.end(); ++it) {
 		px(1, "\u2551");
		std::cerr << " " << std::left << std::setw(2) << it->second.get_fd();
		std::cerr << " " << std::left << std::setw(12) << it->second.get_nick();
		std::cerr << " " << std::left << std::setw(12) << it->second.get_username();
		px(1, " \u2551\n");
	}

	// L4 no empty
	if (_clients.empty()) {
 		px(1, "\u2551");
		std::cerr << " (empty) ";
		px(size-9, " ");
		px(1, "\u2551\n");
	}

	// L END
	px(1, "\u255A"); px(size, "\u2550"); px(1, "\u255D\n");
}

void	Server::show_channel(Channel & chan)
{
	int	size(62);

	// L1
	px(1,"\u2554"); 
	px(12,"\u2550");
	px(1,"\u2566");
	px(size-25,"\u2550");
	px(1, "\u2566");
	px(11,"\u2550");
	px(1,"\u2557\n");

	// L2
 	px(1, "\u2551");
	std::cerr << std::left << std::setw(21) << "\033[36m "+chan.getName()+" \033[0m";
 	px(1, "\u2551");
 	std::cerr << std::left << std::setw(size - 25) << " \""+chan.getTopic()+"\" ";
 	px(1, "\u2551");
	std::cerr << "\033[36m ";
	std::cerr << std::right << std::setw(4) << chan.getClientNumber();
	std::cerr << "\033[0m/\033[36m";
	std::cerr << std::left << std::setw(4) << chan.getMaxClient();
	std::cerr << " \033[0m";
	px(1, "\u2551\n");

	// L3
	px(1,"\u2560");
	px(12,"\u2550");
	px(1,"\u2569");
	px(size-25,"\u2550");
	px(1, "\u2569");
	px(11,"\u2550");
	px(1,"\u2563\n");

	// L4
 	px(1, "\u2551 password   : ");
	if (chan.getPassword().size()) {
		show_on();
 		std::cerr << " " << std::left << std::setw(size - 16) << "'"+chan.getPassword()+"'";
	}
	else {
		show_off();
		px(size - 15, " ");
	}
	px(1, "\u2551\n");

	// L5
 	px(1, "\u2551 edit_topic : ");
	(chan.getEditTopic()) ? show_on() : show_off();
	px(size - 15, " ");
	px(1, "\u2551\n");

	// L6
 	px(1, "\u2551 invite_only: ");
	(chan.getIsInviteOnly()) ? show_on() : show_off();
	px(size - 15, " ");
	px(1, "\u2551\n");

	// L7
 	px(1, "\u2551 whitelist  : ");
	std::string	clt;
	std::vector < int >	wlist = chan.get_whitelist();

	std::vector< int >::iterator it;
	for (it = wlist.begin() ; it != wlist.end() ; ++it) {
		clt.append(_clients[*it].get_nick());
		clt += " ";
	}
	std::cerr << std::left << std::setw(size - 14) << clt;
	px(1, "\u2551\n");

	// L8
 	px(1, "\u2551 clients    : ");
	std::string	ult;
	std::map< int, bool >	mlist = chan.get_client();

	std::map< int, bool >::iterator it2;
	for (it2 = mlist.begin() ; it2 != mlist.end() ; ++it2) {
		if (it2->second)
			ult.append("@");
		ult.append(_clients[it2->first].get_nick());
		ult += " ";
	}
	std::cerr << std::left << std::setw(size - 14) << ult;
	px(1, "\u2551\n");

	// L9
	px(1, "\u255A"); px(size, "\u2550"); px(1, "\u255D\n");
}

void	Server::show_channels(void)
{
	std::map< std::string, Channel >::iterator	it;

	for (it = _channels.begin(); it != _channels.end(); ++it) {
		show_channel(it->second);
	}
}

void	Server::show_specs(void)
{
	log_nl();

	std::ostringstream	oss;
    oss << "  port: "  		<< "\033[36m" <<_port 			 << "\033[0m"
		<< "  pwd: " 		<< "\033[36m" << _password 		 << "\033[0m"
		<< "  nb_clients: " << "\033[36m" << _clients.size() << "\033[0m";
	log_info(oss.str().c_str());

	show_clients();
	show_channels();
	log_nl();
}

void	Server::show_client_specs(int fd)
{
	if (fd == _serv_socket)
		return ;
	std::cerr << " ............... CLIENT OBJECT CONCERNED ...............\n";
	std::cerr << " fd          : " << _clients[fd].get_fd()				<< "\n";
	std::cerr << " nick        : " << _clients[fd].get_nick()			<< "\n";
	std::cerr << " username    : " << _clients[fd].get_username()		<< "\n";
	std::cerr << " realname    : " << _clients[fd].get_realname()		<< "\n";
	std::cerr << " hostname    : " << _clients[fd].get_hostname()		<< "\n";
	std::cerr << " servname    : " << _clients[fd].get_servname()		<< "\n";
	std::cerr << " password    : " << _clients[fd].get_password()		<< "\n";
	std::cerr << " registered  : " << _clients[fd].is_registered()		<< "\n";
	std::cerr << " nb_chan     : " << _clients[fd].get_nb_chan_join()	<< "\n";
	std::cerr << " serv_op     : " << _clients[fd].get_serv_operator()	<< "\n";
	std::cerr << " to_delete   : " << _clients[fd].get_to_delete()		<< "\n";

	std::string	recv_preview = _clients[fd].get_recv_buffer();
	if (recv_preview.size() > 40)
		recv_preview = recv_preview.substr(0, 40);
	std::cerr << " recv_buffer : |" << recv_preview			<< "...|\n";

	std::string	send_preview = _clients[fd].get_send_buffer();
	if (send_preview.size() > 40)
		send_preview = send_preview.substr(0, 40);
	std::cerr << " send_buffer : |" << send_preview			<< "...|\n";
}

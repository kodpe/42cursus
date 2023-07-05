#include "Server.hpp"

void	Server::add_client(void)
{
	struct sockaddr_in client_address;

	socklen_t	addr_len = sizeof(client_address);


	int client_socket = accept(_serv_socket, (struct sockaddr *) &client_address, &addr_len);
	if (-1 == client_socket) {
		log_fail("accept() : connexion refused");
		return ;
	}

	if (_clients.size() >= IRC_MAX_USER) {
		sc_close(client_socket);
		log_fail("accept() : connexion refused: server is full");
		return ;
	}

	set_non_blocking(client_socket);

	struct epoll_event		event_struct_client = {0, {0}};

	event_struct_client.events = EPOLLIN | EPOLLRDHUP; // LEVEL TRIG
	event_struct_client.data.fd = client_socket;

	if (-1 == epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, client_socket, &event_struct_client)) {
		sc_close(client_socket);
		throw_irc(IRC_STR_EPPOLCTL);
	}

	std::cerr << "client socket " << client_socket << "\n";

	_clients[client_socket] = Client(client_socket);
}

void	Server::del_client(int fd)
{
	log_ok("del_client()");

	if (-1 == epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, fd, NULL))
		throw_irc(IRC_STR_EPPOLCTL);

	std::map< std::string, Channel >::iterator	it;
	std::map< std::string, Channel >::iterator	itrm;

	for (it = _channels.begin(); it != _channels.end(); )
	{
		if (it->second.isInChannel(fd)) {
			it->second.delClient(fd);
			itrm = it;
			++it;
			if (itrm->second.getClientNumber() == 0) {
				_channels.erase(itrm);
			}
		}
		else
			++it;
	}

	_clients.erase(fd);
	sc_close(fd);
}

void	Server::check_clients_to_delete(void)
{
	std::map< int, Client >::iterator	it;

	for (it = _clients.begin(); it != _clients.end(); ) {
		if (it->second.get_to_delete()) {
			int	fd = it->first;
			++it;
			del_client(fd);
		}
		else
			++it;
	}
}

int	Server::nick_to_fd(std::string nickname) const
{
	std::map< int, Client >::const_iterator	it;

	for (it = _clients.begin(); it != _clients.end(); ++it)
	{
		if (cmp_icase(it->second.get_nick() ,nickname))
			return it->second.get_fd();
	}
	return -1;
}

void	Server::welcome(void)
{
	RPL_WELCOME();						// 001
	RPL_YOURHOST();						// 002
	RPL_CREATED();						// 003
	RPL_MYINFO();						// 004
	RPL_ISUPPORT();						// 005
	RPL_LUSERCLIENT();					// 251
	RPL_LUSERUNKNOWN();					// 253
	RPL_LUSERCHANNELS();				// 254
}

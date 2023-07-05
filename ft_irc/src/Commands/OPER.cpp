#include "Server.hpp"

void	Server::OPER(std::string args)
{
	if (args.empty() || std::count(args.begin(), args.end(), ' ' ) != 1)
	{
		log_warn("OPER -> 461 ERR_NEEDMOREPARAMS");
		return ERR_NEEDMOREPARAMS("");
	}

	size_t	pos = args.find(' ');
	if (pos == std::string::npos || args[pos + 1] == '\0')
		return ERR_NEEDMOREPARAMS("");

	std::string	username = args.substr(0,pos);
	std::string	passcode = args.substr(pos + 1);

	if (username != _operator_credentials[0] || passcode != _operator_credentials[1])
	{
		log_warn("OPER -> 464 ERR_PASSWDMISMATCH");
		return ERR_PASSWDMISMATCH();
	}

	_actual_client->set_serv_operator();

	for (std::map< std::string, Channel>::iterator it = _channels.begin(); it != _channels.end(); it++) {
		if (it->second.isInChannel(_actual_client->get_fd())) {
			it->second.setOp(_actual_client->get_fd());
			_actual_cmd_name = "MODE";
			std::string rpl(it->second.getName()+" +o "+_actual_client->get_nick());
			send_cmd_reply(rpl);
			notify_clients_on_channel_nick(it->second.getName(), rpl);
			log_ok("MODE +o");
			_actual_cmd_name = "OPER";
		}
	}

	RPL_YOUREOPER();
}

#include "Server.hpp"

void	Server::PING(std::string args)
{
	log_ok("PING");

	if (args.empty())
		return ERR_NEEDMOREPARAMS("");

	std::string	full("PONG "+args+"\r\n");

	_actual_client->add_to_send_buffer(full);
}

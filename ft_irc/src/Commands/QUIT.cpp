#include "Server.hpp"

void	Server::QUIT(std::string args)
{
	log_ok("QUIT");

	std::string	reason("");

	if (args.size() > 1)
		reason = args.substr(1);

	std::map< std::string, Channel >::iterator	it;

	for (it = _channels.begin(); it != _channels.end(); ++it)
	{
		if (it->second.isInChannel(_actual_client->get_fd()))
			notify_clients_on_channel(it->first, reason);
	}
	send_error("bye bye");
	_actual_client->set_to_delete();
}

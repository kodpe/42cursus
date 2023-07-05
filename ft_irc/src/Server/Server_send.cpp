#include "Server.hpp"

/// UNIQUE SEND TO CLIENT SOCKET FUNCTION

void	Server::sc_send(int fd)
{
	std::string	buffer = _clients[fd].get_send_buffer();
	_clients[fd].set_send_buffer(""); // reset du send buffer du client

	ssize_t	bytes_send = send(fd, buffer.c_str(), buffer.size(), 0);
	if (bytes_send < 0)
		throw_irc(IRC_STR_SEND);

	// size_t	bscheck = bytes_send;
	// assert (bscheck == buffer.size()); // TMP check for unsend chars
}

void	Server::send_all_clients_buffers(void) // DEPRECATED
{
	std::map< int, Client >::iterator	it;
	for (it = _clients.begin(); it != _clients.end(); ++it)
	{
		if (it->second.get_send_buffer().size())
			sc_send(it->second.get_fd());
	}
}

/// FUNCTIONS QUI ECRIVENT DANS LES BUFFERS DES CLIENTS

void	Server::send_error(std::string rpl)
{
	std::string	nick(_actual_client->get_nick());
	std::string	user(_actual_client->get_username());
	std::string	source(":"+nick+"!"+user+"@localhost");
	std::string	full(source+" ERROR :"+rpl+"\r\n");

	_actual_client->add_to_send_buffer(full);
}

void	Server::send_cmd_reply(std::string rpl)
{
	std::string	nick(_actual_client->get_nick());
	std::string	user(_actual_client->get_username());
	std::string	source(":"+nick+"!"+user+"@localhost");
	std::string	full(source+" "+_actual_cmd_name+" "+rpl+"\r\n");

	_actual_client->add_to_send_buffer(full);
}

void	Server::send_cmd_reply(std::string rpl, int fd)
{
	std::string	nick(_actual_client->get_nick());
	std::string	user(_actual_client->get_username());
	std::string	source(":"+nick+"!"+user+"@localhost");
	std::string	full(source+" "+_actual_cmd_name+" "+rpl+"\r\n");

	_clients[fd].add_to_send_buffer(full);
}

void	Server::send_num_reply(const char *num, std::string & rpl)
{
	std::string	servname(IRC_STR_SERVNAME);
	std::string	code(num);
	std::string	full(":"+servname+" "+code+" "+_actual_client->get_nick()+" "+rpl+"\r\n");

	_actual_client->add_to_send_buffer(full);
}

void	Server::notify_clients_on_channel(std::string channel, std::string rpl)
{
	Channel & chan = _channels[channel];

	if(chan._client.size() == 0)
		return ;

	std::string	nick(_actual_client->get_nick());
	std::string	user(_actual_client->get_username());
	std::string	source(":"+nick+"!~"+user+"@localhost");
	std::string	full(source+" "+_actual_cmd_name+" "+channel+" :"+rpl+"\r\n"); // check channel useless ?

	std::map< int, bool >::iterator it;
	for (it = chan._client.begin(); it != chan._client.end(); ++it)
		if (it->first != _actual_client->get_fd())
			_clients[it->first].add_to_send_buffer(full);
}


void	Server::notify_clients_on_channel_nick(std::string channel, std::string rpl)
{
	Channel & chan = _channels[channel];

	if(chan._client.size() == 0)
		return ;

	std::string	nick(_actual_client->get_nick());
	std::string	user(_actual_client->get_username());
	std::string	source(":"+nick+"!~"+user+"@localhost");
	std::string	full(source+" "+_actual_cmd_name+" "+rpl+"\r\n");

	std::map< int, bool >::iterator it;
	for (it = chan._client.begin(); it != chan._client.end(); ++it)
		if (it->first != _actual_client->get_fd())
			_clients[it->first].add_to_send_buffer(full);
}


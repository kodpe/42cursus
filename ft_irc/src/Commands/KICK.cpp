#include "Server.hpp"

// Parameters: <channel> <user> [<comment>]
void	Server::KICK(std::string args)
{
	log_ok("KICK");

	if (args_count(args) < 2) {
		log_warn("KICK -> 461 ERR_NEEDMOREPARAMS");
		ERR_NEEDMOREPARAMS("");				 					// 461
		return ;
	}

	std::string channel_name = get_arg(args, 1);
	std::string nickname = get_arg(args, 2);
	std::string	comment("");
	if (args_count(args) == 3)
		comment = get_arg(args, 3);

	std::map<std::string, Channel>::iterator channel_it;
	channel_it = _channels.find(channel_name);
	if (channel_it == _channels.end())
	{
		log_warn("KICK -> 403 ERR_NOSUCHCHANNEL");
		return ERR_NOSUCHCHANNEL(channel_name);
	}

	Channel &channel = channel_it->second;
	if (!channel.isInChannel(_actual_client->get_fd()))
	{
		log_warn("KICK -> 442 ERR_NOTONCHANNEL");
		return ERR_NOTONCHANNEL(channel.getName());
	}

	if (!channel.isOp(_actual_client->get_fd()))
	{
		log_warn("KICK -> 482 ERR_CHANOPRIVSNEEDED");
		return ERR_CHANOPRIVSNEEDED(channel.getName());
	}

	int	fd = nick_to_fd(nickname);
	if (!channel.isInChannel(fd))
	{
		log_warn("KICK -> 441 ERR_USERNOTINCHANNEL");
		return ERR_USERNOTINCHANNEL(nickname+" "+channel.getName());
	}

	if (_clients[fd].get_serv_operator() == true)
	{
		log_warn("KICK -> 481 ERR_NOPRIVILEGES");
		return ERR_NOPRIVILEGES("You can't kick a server operator");
	}

	channel.delClient(fd);
	if (channel._client.empty())
		_channels.erase(channel.getName());

	std::string	rpl = channel_name+" "+nickname+" "+comment;

	send_cmd_reply(rpl);
	send_cmd_reply(rpl, fd);
	notify_clients_on_channel_nick(channel_name, rpl);
}

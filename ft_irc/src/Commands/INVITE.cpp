#include "Server.hpp"

// /INIVTE <nickname> <channel>
void	Server::INVITE(std::string args)
{
	log_ok("INVITE");

	if (args_count(args) != 2) {
		log_warn("INVITE -> 461 ERR_NEEDMOREPARAMS");
		ERR_NEEDMOREPARAMS("");				 					// 461
		return ;
	}

	std::string nickname = get_arg(args, 1);
	std::string channel_name = get_arg(args, 2);

	int	fd = nick_to_fd(nickname);
	if (fd == -1) {
		log_warn("INVITE -> 401 ERR_NOSUCHNICK");
		return ERR_NOSUCHNICK(nickname);
	}

	std::map<std::string, Channel>::iterator channel_it = _channels.find(channel_name);

	if (channel_it == _channels.end())
	{
		log_warn("INVITE -> 403 ERR_NOSUCHCHANNEL");
		return ERR_NOSUCHCHANNEL(channel_name);
	}
	Channel *channel = & channel_it->second;

	if (!channel->isInChannel(_actual_client->get_fd()))
	{
		log_warn("INVITE -> 442 ERR_NOTONCHANNEL");
		return ERR_NOTONCHANNEL(channel->getName());
	}


	if (channel->isInChannel(fd))
	{
		log_warn("INVITE -> 443 ERR_USERONCHANNEL");
		return ERR_USERONCHANNEL(_clients[fd].get_nick()+" "+channel->getName());
	}

	if (!channel->isOp(_actual_client->get_fd()))
	{
		log_warn("INVITE -> 482 ERR_CHANOPRIVSNEEDED");
		return ERR_CHANOPRIVSNEEDED(channel->getName());
	}
	channel->addWhiteList(fd);
	std::string rpl(_clients[fd].get_nick()+" "+channel->getName());
	send_cmd_reply(rpl, _clients[fd].get_fd());
}

#include "Server.hpp"

// /TOPIC <channel> [<topic>]
void	Server::TOPIC(std::string args)
{
	log_ok("TOPIC");

	if (args_count(args) == 0) {
		log_warn("INVITE -> 461 ERR_NEEDMOREPARAMS");
		ERR_NEEDMOREPARAMS("");				 					// 461
		return ;
	}

	std::string	topic("");
	std::string	channel_name = get_arg(args, 1);
	if (args_count(args) == 2)
		topic = get_arg(args, 2);

	std::string	fixreal = topic;
	if (fixreal[0] == ':' && fixreal.size() > 1)
		topic = fixreal.substr(1);

	std::map<std::string, Channel>::iterator channel_it = _channels.find(channel_name);

	if (channel_it == _channels.end())
	{
		log_warn("MODE -> 403 ERR_NOSUCHCHANNEL");
		return ERR_NOSUCHCHANNEL(channel_name);
	}
	Channel & channel = channel_it->second;

	if (!channel.isInChannel(_actual_client->get_fd()))
	{
		log_warn("MODE -> 442 ERR_NOTONCHANNEL");
		return ERR_NOTONCHANNEL(channel.getName());
	}

	if (topic.empty())
	{
		if (channel.getTopic().empty())
			return RPL_NOTOPIC(channel.getName());
		return RPL_TOPIC(channel.getName());
	}

	if (!channel.getEditTopic() && !channel.isOp(_actual_client->get_fd()))
	{
		log_warn("MODE -> 482 ERR_CHANOPRIVSNEEDED");
		return ERR_CHANOPRIVSNEEDED(channel.getName());
	}

	channel.setTopic(topic);
	std::string rpl(channel.getName()+" "+topic);
	send_cmd_reply(rpl);
	notify_clients_on_channel(channel.getName(), topic);
}

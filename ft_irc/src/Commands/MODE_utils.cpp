#include "Server.hpp"

bool	Server::invalid_client(Channel & channel)
{
	if (!channel.isInChannel(_actual_client->get_fd()))
	{
		log_warn("MODE -> 442 ERR_NOTONCHANNEL");
		ERR_NOTONCHANNEL(channel.getName());
		return 1;
	}

	if (!channel.isOp(_actual_client->get_fd()))
	{
		log_warn("MODE -> 482 ERR_CHANOPRIVSNEEDED");
		ERR_CHANOPRIVSNEEDED(channel.getName());
		return 1;
	}
	return 0;
}

void	Server::mode_l(Channel & channel, std::string opt, std::string user_limit)
{
	if (invalid_client(channel))
		return ;

	if (user_limit.empty() && opt[0] == '+')
	{
		log_warn("MODE_l -> 461 ERR_NEEDMOREPARAMS");
		return ERR_NEEDMOREPARAMS(" +l");
	}

	if (opt[0] == '-' && channel.getMaxClient())
	{
		channel.setMaxClient(IRC_CHAN_MAX_USER);
		std::string rpl(channel.getName()+" -l");
		send_cmd_reply(rpl);
		notify_clients_on_channel_nick(channel.getName(), rpl);
		log_ok("MODE -l");
	}
	else if (opt[0] == '+' && std::atoll(user_limit.c_str()) > 0 && std::atoll(user_limit.c_str()) <= 2147483647)
	{
		channel.setMaxClient(std::atoi(user_limit.c_str()));
		if (channel.getMaxClient() < 0 || channel.getMaxClient() >= IRC_CHAN_MAX_USER)
			channel.setMaxClient(IRC_CHAN_MAX_USER - 1);
		std::string rpl(channel.getName()+" +l "+user_limit);
		send_cmd_reply(rpl);
		notify_clients_on_channel_nick(channel.getName(), rpl);
		log_ok("MODE +l");
	}
	else
		log_warn("execute MODE -/+ l useless");
}

void	Server::mode_o(Channel & channel, std::string opt, std::string nickname)
{
	if (invalid_client(channel))
		return ;

	if (nickname.empty())
	{
		log_warn("MODE_o -> 461 ERR_NEEDMOREPARAMS");
		return ERR_NEEDMOREPARAMS(" "+opt);
	}
	int	fd = nick_to_fd(nickname);

	if (!channel.isInChannel(fd))
	{
		log_warn("MODE_o -> 401 ERR_NOSUCHNICK");
		return ERR_NOSUCHNICK(nickname);
	}

	if (opt[0] == '-' && channel.isOp(fd) && _clients[fd].get_serv_operator() == false)
	{
		channel.unsetOp(fd);
		std::string rpl(channel.getName()+" -o "+_clients[fd].get_nick());
		send_cmd_reply(rpl);
		notify_clients_on_channel_nick(channel.getName(), rpl);
		log_ok("MODE -o");
	}
	else if (opt[0] == '+' && !channel.isOp(fd))
	{
		channel.setOp(fd);
		std::string rpl(channel.getName()+" +o "+_clients[fd].get_nick());
		send_cmd_reply(rpl);
		notify_clients_on_channel_nick(channel.getName(), rpl);
		log_ok("MODE +o");
	}
	else
		log_warn("execute MODE -/+ o useless");
}

void	Server::mode_k(Channel & channel, std::string opt, std::string pwd)
{
	if (invalid_client(channel))
		return ;

	if (pwd.empty())
	{
		log_warn("MODE_k -> 461 ERR_NEEDMOREPARAMS");
		return ERR_NEEDMOREPARAMS(" "+opt);
	}

	if (opt[0] == '+' && !channel.isPassword())
	{
		channel.setPassword(pwd);
		std::string rpl(channel.getName()+" +k");
		send_cmd_reply(rpl);
		notify_clients_on_channel_nick(channel.getName(), rpl);
		log_ok("MODE +k");
	}
	else if (opt[0] == '-' && channel.isPassword() && channel.getPassword() == pwd)
	{
		channel.setPassword("");
		std::string rpl(channel.getName()+" -k");
		send_cmd_reply(rpl);
		notify_clients_on_channel_nick(channel.getName(), rpl);
		log_ok("MODE -k");
	}
	else
	{
		log_warn("MODE_k -> 467 ERR_KEYSET");
		ERR_KEYSET(channel.getName());
	}
}

void	Server::mode_tt(Channel & channel, std::string opt)
{
	if (invalid_client(channel))
		return ;

	if (opt[0] == '-' && channel.getEditTopic())
	{
		channel.setEditTopic(false);
		std::string rpl(channel.getName()+" -t");
		send_cmd_reply(rpl);
		notify_clients_on_channel_nick(channel.getName(), rpl);
		log_ok("MODE -t");
	}
	else if (opt[0] == '+' && !channel.getEditTopic())
	{
		channel.setEditTopic(true);
		std::string rpl(channel.getName()+" +t");
		send_cmd_reply(rpl);
		notify_clients_on_channel_nick(channel.getName(), rpl);
		log_ok("MODE +t");
	}
	else
		log_warn("execute MODE -/+ t useless");
}

void	Server::mode_i(Channel & channel, std::string opt)
{
	if (invalid_client(channel))
		return ;

	if (opt[0] == '-' && channel.getIsInviteOnly())
	{
		channel.setIsInviteOnly(false);
		std::string rpl(channel.getName()+" -i");
		send_cmd_reply(rpl);
		notify_clients_on_channel_nick(channel.getName(), rpl);
		log_ok("MODE -i");
	}
	else if (opt[0] == '+' && !channel.getIsInviteOnly())
	{
		channel.setIsInviteOnly(true);
		std::string rpl(channel.getName()+" +i");
		send_cmd_reply(rpl);
		notify_clients_on_channel_nick(channel.getName(), rpl);
		log_ok("MODE +i");
	}
	else
		log_warn("execute MODE -/+ i useless");
}


#include "Channel.hpp"

void	Channel::setName(std::string name)
{
	_name = name;
}

void	Channel::setPassword(std::string pwd)
{
	_password = pwd;
}

void	Channel::setTopic(std::string topic)
{
	_topic = topic;
}

void	Channel::setMaxClient(int max_client)
{
	_max_client = max_client;
}

void	Channel::setEditTopic(bool edit_topic)
{
	_edit_topic = edit_topic;
}

void	Channel::setIsInviteOnly(bool is_invite_only)
{
	_is_invite_only = is_invite_only;
}

void	Channel::setOp(int fd)
{
	_client[fd] = true;
}

void	Channel::unsetOp(int fd)
{
	_client[fd] = false;
}

void	Channel::addClient(int fd)
{
	_client.insert(std::pair< int, bool >(fd, 0));
}

void	Channel::delClient(int fd)
{
	_client.erase(fd);
}

void	Channel::addWhiteList(int fd)
{
	_whitelist.push_back(fd);
}

void	Channel::delWhiteList(int fd)
{
	if (find(_whitelist.begin(), _whitelist.end(), fd) != _whitelist.end())
		_whitelist.erase(find(_whitelist.begin(), _whitelist.end(), fd));
}

#include "Channel.hpp"

std::string	Channel::getName(void) const
{
	return _name;
}

std::string	Channel::getPassword(void) const
{
	return _password;
}

std::string	Channel::getTopic(void) const
{
	return _topic;
}

int		Channel::getMaxClient(void) const
{
	return _max_client;
}

bool	Channel::getEditTopic(void) const
{
	return _edit_topic;
}

bool	Channel::getIsInviteOnly(void) const
{
	return _is_invite_only;
}

int	Channel::getClientNumber(void) const
{
	return _client.size();
}

bool	Channel::isPassword(void)
{
	if (_password.empty())
		return false;
	return true;
}

bool	Channel::isOp(int fd)
{
	return _client[fd];
}

bool	Channel::isInChannel(int fd)
{
	return _client.find(fd) != _client.end();
}

bool	Channel::isWhiteListed(int fd)
{
	std::vector< int >::iterator it = find(_whitelist.begin(), _whitelist.end(), fd);
	if (it == _whitelist.end())
		return false;
	return true;
}

std::vector< int >	Channel::get_whitelist(void) const
{
	return _whitelist;
}

std::map< int, bool >	Channel::get_client(void) const
{
	return _client;
}

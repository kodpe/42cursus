#include "Channel.hpp"

Channel::Channel() :
	_name("default_chan_name"),
	_password(""),
	_topic(""),
	_max_client(IRC_CHAN_MAX_USER),
	_edit_topic(false),
	_is_invite_only(false),
	_whitelist(),
	_client()
{}

Channel::~Channel()
{}

Channel::Channel(const Channel &other)
{
	*this = other;
}

Channel	&Channel::operator=(const Channel &other)
{
	_name 			= other._name;
	_password 		= other._password;
	_topic 			= other._topic;
	_max_client 	= other._max_client;
	_edit_topic 	= other._edit_topic;
	_is_invite_only = other._is_invite_only;
	_whitelist 		= other._whitelist;
	_client 		= other._client;
	return *this;
}

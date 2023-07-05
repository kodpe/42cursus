#include "Client.hpp"

int	Client::get_fd(void) const
{
	return _fd;
}

const std::string & Client::get_nick(void) const
{
	return _nick;
}

const std::string & Client::get_username(void) const
{
	return _username;
}

const std::string & Client::get_realname(void) const
{
	return _realname;
}

const std::string & Client::get_hostname(void) const
{
	return _hostname;
}

const std::string & Client::get_servname(void) const
{
	return _servname;
}

const std::string & Client::get_password(void) const
{
	return _password;
}

bool	Client::is_registered(void) const
{
	return _registered;
}

const std::string & Client::get_recv_buffer(void) const
{
	return _recv_buffer;
}

const std::string & Client::get_send_buffer(void) const
{
	return _send_buffer;
}

std::string Client::extract_next_command(void)
{
	std::string	full_cmd;

	if (_recv_buffer.size() == 0)
		return "";

	size_t	pos = _recv_buffer.find("\r\n");
	if (pos == std::string::npos)
		return "";

	full_cmd = _recv_buffer.substr(0, pos);
	_recv_buffer = _recv_buffer.substr(pos + 2);

	return full_cmd;
}

int	Client::get_nb_chan_join(void) const
{
	return _nb_chan_join;
}

bool	Client::get_serv_operator(void) const
{
	return _serv_operator;
}

bool	Client::get_to_delete(void) const
{
	return _to_delete;
}

#include "Client.hpp"

void	Client::set_fd(int fd)
{
	_fd = fd;
}

void	Client::set_nick(std::string nick)
{
	_nick = nick;
}

void	Client::set_username(std::string username)
{
	_username = username;
}

void	Client::set_realname(std::string realname)
{
	_realname = realname;
}

void	Client::set_hostname(std::string hostname)
{
	_hostname = hostname;
}

void	Client::set_servname(std::string servname)
{
	_servname = servname;
}

void	Client::set_password(std::string password)
{
	_password = password;
}

void	Client::set_registered(void)
{
	_registered = true;
}

void	Client::set_recv_buffer(std::string recv_buffer)
{
	_recv_buffer = recv_buffer;
}

void	Client::set_send_buffer(std::string send_buffer)
{
	_send_buffer = send_buffer;
}

void	Client::add_to_send_buffer(std::string content)
{
	// assert(content.size() > 2);
	// assert(content[content.size() - 1] == '\n');
	// assert(content[content.size() - 2] == '\r');

	_send_buffer.append(content);
}

int	Client::recv_append_to_buffer(void)
{
	char	buf[IRC_RECV_BUF_SIZE + 1];
	ssize_t bytes_read = 0;

	bytes_read = recv(_fd, buf, IRC_RECV_BUF_SIZE, 0);
	if (bytes_read < 0)
		return 0;
	if (bytes_read == 0)
		return 0 ;

	buf[bytes_read] = 0;
	_recv_buffer.append(buf);

	return bytes_read;
}

void	Client::set_nb_chan_join(int nb_chan_join)
{
	_nb_chan_join = nb_chan_join;
}

void	Client::set_serv_operator(void)
{
	_serv_operator = true;
}

void	Client::set_to_delete(void)
{
	_to_delete = true;
}

void	Client::set_register_data(int data)
{
	if (data == IRC_REG_PASS)
		_reg.pass = true;

	if (data == IRC_REG_NICK)
		_reg.nick = true;

	if (data == IRC_REG_USER)
		_reg.user = true;

	if (_reg.pass && _reg.nick && _reg.user)
		_registered = true;
}

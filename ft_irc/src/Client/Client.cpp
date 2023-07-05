#include "Client.hpp"

Client::Client() :
	_fd(-11),
	_nick("df_nick"),
	_username("df_user"),
	_realname("df_real"),
	_hostname("df_host"),
	_servname("df_serv"),
	_password(""),
	_registered(false),
	_recv_buffer(""),
	_send_buffer(""),
	_nb_chan_join(0),
	_serv_operator(0),
	_to_delete(false)
{}

Client::Client(int fd) :
	_fd(fd),
	_nick("df_nick"),
	_username("df_user"),
	_realname("df_real"),
	_hostname("df_host"),
	_servname("df_serv"),
	_password(""),
	_registered(false),
	_recv_buffer(""),
	_send_buffer(""),
	_nb_chan_join(0),
	_serv_operator(0),
	_to_delete(false)
{}

Client::Client(const Client &other)
{
	*this = other;
}

Client::~Client()
{}

Client &Client::operator=(const Client &other)
{
	_fd = other._fd;
	_nick = other._nick;
	_username = other._username;
	_realname = other._realname;
	_hostname = other._hostname;
	_servname = other._servname;
	_password = other._password;
	_registered = other._registered;
	_recv_buffer = other._recv_buffer;
	_send_buffer = other._send_buffer;
	_nb_chan_join = other._nb_chan_join;
	_serv_operator = other._serv_operator;
	_to_delete = other._to_delete;
	_reg.pass = other._reg.pass;
	_reg.nick = other._reg.nick;
	_reg.user = other._reg.user;
	return *this;
}

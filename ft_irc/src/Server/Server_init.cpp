#include "Server.hpp"

void	Server::init_addr(void)
{
	_serv_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == _serv_socket)
		throw_irc(IRC_STR_SOCKET);

	set_non_blocking(_serv_socket);

	_addr_server_struct.sin_family = AF_INET;
	_addr_server_struct.sin_addr.s_addr = INADDR_ANY;
	_addr_server_struct.sin_port = htons(_port);

	if (-1 == bind(_serv_socket, (struct sockaddr *)&_addr_server_struct, sizeof(_addr_server_struct))) {
		sc_close(_serv_socket);
		log_ok("close _serv_socket");
		throw_irc(IRC_STR_BIND);
	}

	if (-1 == listen(_serv_socket, 3)) {
		sc_close(_serv_socket);
		log_ok("close _serv_socket");
		throw_irc(IRC_STR_LISTEN);
	}
}

void	Server::init_epoll(void)
{
	_epoll_fd = epoll_create1(0);
	if (-1 == _epoll_fd) {
		sc_close(_epoll_fd);
		sc_close(_serv_socket);
		throw_irc(IRC_STR_EPPOLCREATE);
	}

	set_non_blocking(_epoll_fd);

	struct epoll_event		event_struct_serv = {0, {0}};

	event_struct_serv.events = EPOLLIN; // LEVEL TRIG
	event_struct_serv.data.fd = _serv_socket;

	if (-1 == epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, _serv_socket, &event_struct_serv)) {
		sc_close(_epoll_fd);
		sc_close(_serv_socket);
		throw_irc(IRC_STR_EPPOLCTL);
	}
}

void	Server::init_commands_map(void)
{
	_cmdMap["PASS"]		= &Server::PASS;
	_cmdMap["NICK"]		= &Server::NICK;
	_cmdMap["USER"]		= &Server::USER;
	_cmdMap["JOIN"]		= &Server::JOIN;
	_cmdMap["PART"]		= &Server::PART;
	_cmdMap["PRIVMSG"]	= &Server::PRIVMSG;
	_cmdMap["NOTICE"]	= &Server::NOTICE;
	_cmdMap["PING"]		= &Server::PING;
	_cmdMap["MODE"]		= &Server::MODE;
	_cmdMap["TOPIC"]	= &Server::TOPIC;
	_cmdMap["INVITE"]	= &Server::INVITE;
	_cmdMap["KICK"]		= &Server::KICK;
	_cmdMap["LIST"]		= &Server::LIST;
	_cmdMap["WHO"]		= &Server::WHO;
	_cmdMap["QUIT"]		= &Server::QUIT;
	_cmdMap["OPER"]		= &Server::OPER;
}

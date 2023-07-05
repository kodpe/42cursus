#include "Server.hpp"

Server::Server(int port, const char *password) :
		_password(password),
		_port(port),
		_serv_socket(-1),
		_epoll_fd(-1),
		_actual_client(NULL)
{
	_operator_credentials[0] = "bob";
	_operator_credentials[1] = "123456";
	signal(SIGHUP, Server::sighandler);		// 1
	signal(SIGINT, Server::sighandler);		// 2
	signal(SIGQUIT, Server::sighandler);	// 3
	signal(SIGTERM, Server::sighandler);	// 15
	log_ok("init signal handler");

	init_addr();
	log_ok("init server address");

	init_epoll();
	log_ok("init server epoll");

	init_commands_map();
	log_ok("init command map");

	log_ok("starting routine");
	routine();
}

Server::~Server()
{
	std::map< int, Client >::iterator	it;

	for (it = _clients.begin(); it != _clients.end(); ++it) {

		if (-1 == epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, it->first, NULL))
			throw_irc(IRC_STR_EPPOLCTL);
		sc_close(it->first);
		log_ok("close client socket");
	}
	_clients.clear();
	log_ok("clear _clients objects");

	sc_close(_epoll_fd);
	sc_close(_serv_socket);
	log_ok("close _epoll_fd");
	log_ok("close _serv_socket");
}


#include "Server.hpp"

bool	g_run = 1;

void	Server::sighandler(int signum)
{
	(void)signum;
	g_run = 0;
}

bool	Server::events_errors_handler(uint32_t ev)
{
	if (ev & EPOLLHUP) {
		log_warn("EPOLLHUP EVENT");
		switch_EPPOLOUT();
		return true;
	}
	if (ev & EPOLLERR) {
		log_warn("EPOLLERR EVENT");
		switch_EPPOLOUT();
		return true;
	}
	if (ev & EPOLLRDHUP) {
		log_warn("EPOLLRDHUP EVENT");
		switch_EPPOLOUT();
		return true;
	}
	return false;
}

void	Server::routine(void)
{
	int	nb_events;

	while (g_run)
	{
		show_specs();
		nb_events = epoll_wait(_epoll_fd, _tab_events, IRC_MAX_EVENTS, 10000);
		if (g_run == 0) {
			log_warn("^C after epoll_wait()");
			return ;
		}

		for (int i = 0; i < nb_events; ++i)
		{
			int			fd = _tab_events[i].data.fd;
			uint32_t	ev = _tab_events[i].events;
			// show_epoll_specs(ev);
			// show_client_specs(fd);

			if (fd == _serv_socket && ev & EPOLLIN) {
				add_client();
			}
			else if (events_errors_handler(ev)) {
				del_client(fd);
			}
			else if (ev & EPOLLIN) {
				if (!_clients[fd].recv_append_to_buffer())
					del_client(fd);
				command_handler(fd);
				switch_EPPOLOUT();
			}
			else if (ev & EPOLLOUT) {
				switch_EPPOLIN(fd);
				check_clients_to_delete();
			}
		}
	}
}

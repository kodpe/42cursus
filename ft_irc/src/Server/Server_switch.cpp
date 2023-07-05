#include "Server.hpp"

void	Server::switch_EPPOLOUT(void)
{
	struct epoll_event	s_ev;
	s_ev.events = EPOLLIN | EPOLLOUT | EPOLLRDHUP;

	std::map< int, Client >::iterator	it;

	for (it = _clients.begin(); it != _clients.end(); ++it)
	{
		if (it->second.get_send_buffer().empty())
			continue ;

		s_ev.data.fd = it->second.get_fd();

		if (-1 == epoll_ctl(_epoll_fd, EPOLL_CTL_MOD, it->second.get_fd(), &s_ev))
			throw_irc(IRC_STR_EPPOLCTL);
	}

}

void	Server::switch_EPPOLIN(int fd)
{
	if (_clients[fd].get_send_buffer().empty())
		return ;

	sc_send(fd);

	struct epoll_event	s_ev;
	s_ev.events = EPOLLIN | EPOLLRDHUP;
	s_ev.data.fd = fd;

	if (-1 == epoll_ctl(_epoll_fd, EPOLL_CTL_MOD, fd, &s_ev))
		throw_irc(IRC_STR_EPPOLCTL);

	if (_clients[fd].get_to_delete())
		del_client(fd);
}

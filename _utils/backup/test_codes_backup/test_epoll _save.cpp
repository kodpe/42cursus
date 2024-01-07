/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_epoll.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:27:14 by sloquet           #+#    #+#             */
/*   Updated: 2023/05/05 20:45:26 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

#define MAX_EVENTS	10


int	setnonblocking(int fd)
{
	int	result;
	int	flags;

	flags = fcntl(fd, F_GETFL, 0);
	if (-1 == flags)
		return -1;
	flags |= O_NONBLOCK;
	result = fcntl(fd, F_SETFL, flags);
	return result;
}

void	do_use_fd(int fd)
{
	//write read
	char	buffer[256];
	bzero(buffer, sizeof(buffer));

	int n = read(fd, buffer, 255);
	if (n == -1)
		LOGAB
	std::cout << "read() buffer: " << buffer << "\n";

	n = write(fd, "ok\n", 3);
	if (n == -1)
		LOGAB
}

void	test_epoll(void)
{
	struct epoll_event	events[MAX_EVENTS];

	int	conn_sock;
	int	nfds;
	int	epollfd;

	/* SETUP SOCKET() */
	int	skfd;

	skfd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == skfd)
		LOGAB
	LOG("fd", skfd);

	/* SETUP SOCKADDR BIND() */

	struct sockaddr_in	serv_address;
	serv_address.sin_family = AF_INET;
	serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_address.sin_port = htons(4243);



	if (-1 == bind(skfd, (struct sockaddr *) &serv_address, sizeof(serv_address)))
		LOGAB
	if (-1 == listen(skfd, 3))
		LOGAB

	/* EPOLL() + ACCEPT() */

	epollfd = epoll_create1(0);
	if (-1 == epollfd)
		LOGAB

	struct epoll_event	ev;

	ev.events = EPOLLIN;
	ev.data.fd = skfd;

	if (-1 == epoll_ctl(epollfd, EPOLL_CTL_ADD, skfd, &ev))
		LOGAB


	while (1) {
		nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
		if (-1 == nfds)
			LOGAB

		for (int n = 0; n < nfds; ++n) {
			// si server event (=) nouveau client
			if (events[n].data.fd == skfd) {
				// pourquoi server event = forcement nouveau client ???

				struct sockaddr_in	client_address;
				socklen_t	clilen = sizeof(client_address);

				conn_sock = accept(skfd, (struct sockaddr *) &client_address, &clilen);
				if (-1 == conn_sock)
					LOGAB
				if (-1 == setnonblocking(conn_sock))
					LOGAB
				ev.events = EPOLLIN | EPOLLET;
				ev.data.fd = conn_sock;

				if (-1 == epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev))
					LOGAB
			}
			// sinon client event
			else
				do_use_fd(events[n].data.fd);

		}

	}
	if (-1 == close(epollfd))
		LOGAB
	if (-1 == close(conn_sock))
		LOGAB
	if (-1 == close(skfd))
		LOGAB
}

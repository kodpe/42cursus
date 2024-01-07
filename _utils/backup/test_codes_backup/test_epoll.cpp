/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_epoll.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:27:14 by sloquet           #+#    #+#             */
/*   Updated: 2023/05/05 22:28:53by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

int	set_non_blocking(int fd)
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

void	get_client_message(int fd)
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

struct sockaddr_in new_addr_struct(const char * ip_addr, int port)
{
	struct sockaddr_in	addr_server_struct;

	addr_server_struct.sin_family = AF_INET;
	addr_server_struct.sin_addr.s_addr = inet_addr(ip_addr); //sc
	addr_server_struct.sin_port = htons(port); //sc

	return (addr_server_struct);
}

int		server_init(int * serv_sock, int * epoll_fd)
{
	/* SIGNAL HANDLER */
	signal(SIGQUIT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN); // tmp

	//int serv_sock;

	*serv_sock = socket(AF_INET, SOCK_STREAM, 0);
	// check parametre 3 protocole , pourquoi 0 (automatique)
	if (-1 == *serv_sock)
		LOGAB

	struct sockaddr_in addr_server_struct;

	addr_server_struct = new_addr_struct(IP_ADDR, PORT);

	if (-1 == bind(*serv_sock, (struct sockaddr *)&addr_server_struct, sizeof(addr_server_struct)))
		LOGAB

	if (-1 == listen(*serv_sock, 3)) //check param 2
		LOGAB

	//int	epoll_fd;

	*epoll_fd = epoll_create1(0); //check param
	if (-1 == *epoll_fd)
		LOGAB

	struct	epoll_event event_struct_serv;
	event_struct_serv.events = EPOLLIN; //check more
	event_struct_serv.data.fd = *serv_sock;

	if (-1 == epoll_ctl(*epoll_fd, EPOLL_CTL_ADD, *serv_sock, &event_struct_serv))
		LOGAB

	return (0);
}

int	add_new_client(int serv_sock, int epoll_fd)
{
	struct sockaddr_in client_address;

	socklen_t	addr_len = sizeof(client_address);

	int	client_sock;

	client_sock = accept(serv_sock, (struct sockaddr *) &client_address, &addr_len);
	if (-1 == client_sock)
		LOGAB

	if (-1 == set_non_blocking(client_sock))
		LOGAB

	struct epoll_event event_struct_client;
	event_struct_client.events = EPOLLIN | EPOLLET; //check more
	event_struct_client.data.fd = client_sock;

	if (-1 == epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_sock, &event_struct_client))
		LOGAB

	return (0);
}

int	server_routine(int serv_sock, int epoll_fd)
{
	int	nb_events;

	struct epoll_event	tab_events[MAX_EVENTS];

	while (1)
	{
		nb_events = epoll_wait(epoll_fd, tab_events, MAX_EVENTS, -1); //add timeout
		if (-1 == nb_events)
			LOGAB

		for (int i = 0; i < nb_events; ++i)
		{
			// si server event (=) nouveau client
			if (tab_events[i].data.fd == serv_sock) // pourquoi server event = forcement nouveau client ???
				add_new_client(serv_sock, epoll_fd);
			else
				get_client_message(tab_events[i].data.fd);
		}
	}
}

int	server_exit(int serv_sock, int epoll_fd)
{

	//if (-1 == close(conn_sock)) //check fd leak

	if (-1 == close(epoll_fd))
		LOGAB

	if (-1 == close(serv_sock))
		LOGAB

	return (0);
}

void test_epoll(void)
{
	int serv_sock;
	int	epoll_fd;

	server_init(&serv_sock, &epoll_fd);

	server_routine(serv_sock, epoll_fd);

	server_exit(serv_sock, epoll_fd);

}

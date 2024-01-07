/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:43:31 by sloquet           #+#    #+#             */
/*   Updated: 2023/05/04 17:00:06 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

void	test_epoll(void);

int	main(int ac, char **argv, char **env)
{
	test_epoll();
	return 0;

	int	skfd;


	skfd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == skfd)
		LOGAB

	std::cerr << "fd : " << skfd << "\n";


	struct sockaddr_in	serv_address;
	struct sockaddr_in	client_address;

	serv_address.sin_family = AF_INET;
	serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_address.sin_port = htons(4244);

	if (-1 == bind(skfd, (struct sockaddr *)&serv_address, sizeof(serv_address)))
		LOGAB
	if (-1 == listen(skfd, 3))
		LOGAB

	socklen_t	clilen = sizeof(client_address);
	int	new_skfd = accept(skfd, (struct sockaddr *) &client_address, &clilen);
	if (-1 == new_skfd)
		LOGAB

	struct sockaddr_in	client_address2;
	socklen_t	clilen2 = sizeof(client_address2);
	int	new_skfd2 = accept(skfd, (struct sockaddr *) &client_address2, &clilen2);
	if (-1 == new_skfd)
		LOGAB

	char	buffer[256];

	while (1)
	{
		bzero(buffer, sizeof(buffer));

		int n = read(new_skfd, buffer, 255);
		if (n == -1)
			LOGAB
		std::cout << "buffer: " << buffer << "\n";
		n = write(new_skfd, "ok\n", 3);
		if (n == -1)
			LOGAB

		bzero(buffer, sizeof(buffer));
		n = read(new_skfd2, buffer, 255);
		if (n == -1)
			LOGAB
		std::cout << "buffer: " << buffer << "\n";
		n = write(new_skfd2, "ok\n", 3);
		if (n == -1)
			LOGAB
	}


	if (-1 == close(new_skfd))
		LOGAB
	if (-1 == close(skfd))
		LOGAB





#if 0
	int	epfd;

	epfd = epoll_create(2);

	std::cerr << "fd : " << epfd << "\n";

	struct epoll_event	events;

	write(epfd, "chupacabra", 11);

	int ret = epoll_wait(epfd, &events, 5, -1);
	std::cerr << "ret : " << ret << "\n";



	if (-1 == close(epfd))
		LOGAB
#endif
	return 0;
	(void)ac;
	(void)argv;
	(void)env;
}

/*
socket, 
setsockopt, 

bind, 

getsockname,

connect, 

listen, 
accept,

send,
recv,

getprotobyname, 
struct protoent {
               char  *p_name;       // official protocol name
               char **p_aliases;    // alias list 
               int    p_proto;      // protocol number
           }




poll 
close, 

gethostbyname, 

getaddrinfo,
freeaddrinfo, 


// convert values between host and network byte order
htons
htonl
ntohs
ntohl

// internet address manipulation routine
inet_addr,
inet_ntoa,

signal

// files i/o
lseek,
fstat,
fcntl,


*/

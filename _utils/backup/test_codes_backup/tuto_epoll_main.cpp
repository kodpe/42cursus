#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_EVENTS 5
#define READ_SIZE 100


int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	
	int running = 1;
	int event_count;
	int i;
	size_t bytes_read;
	char read_buffer[READ_SIZE + 1];

	struct epoll_event tab_events[MAX_EVENTS];

	struct epoll_event event;

	int epoll_fd = epoll_create1(0);

	if (epoll_fd == -1)
		abort();

	int tab[2];
	pipe(tab);


	event.events = EPOLLIN;
	event.data.fd = tab[0];


	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, tab[0], &event))
		abort();

	
	//
	int tab2[2];
	pipe(tab2);

	struct epoll_event event2;
	event2.events = EPOLLIN;
	event2.data.fd = tab2[0];

	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, tab2[0], &event2))
		abort();

    int pid2 = fork();

	if (pid2 == 0)
	{
		usleep(1000000);
		std::cout << "SENDED 2" << std::endl;

		write(tab2[1], "fjiojgoirjgoijroijoijgoijoi", 28);

		write(tab2[1], "fjord", 6);

		close(tab2[1]);
		close(tab2[0]);

		std::cout << "Child 2 quit" << std::endl;
		return 0;
	}

	//

    int pid = fork();

	if (pid == 0)
	{
		usleep(1000000);
		std::cout << "SENDED" << std::endl;

		write(tab[1], "123456789123456789", 16);

		write(tab[1], "abc", 3);
		//usleep(5000000);

		close(tab[1]);
		close(tab[0]);

		std::cout << "Child quit" << std::endl;
		return 0;
	}

	// wait(NULL);
	// wait(NULL);

/*
	close(tab[1]);
	wait(NULL);

	char str[100];
	read(tab[0], str, 100);
	std::cout << "ON A [" << str << std::endl;
	return 0;
*/

	while (running)
	{

		std::cout << "En attente d'un input" << std::endl;
		event_count = epoll_wait(epoll_fd, tab_events, MAX_EVENTS, 30000);

		std::cout << std::endl
				  << "-------------------------------------------------------";
		std::cout << std::endl
				  << "epoll_wait OK, " << event_count << " ready events" << std::endl;

		for (i = 0; i < event_count; i++)
		{
			std::cout << "\nReading file descriptor " << tab_events[i].data.fd << std::endl;

			bytes_read = read(tab_events[i].data.fd, read_buffer, READ_SIZE);
			read_buffer[bytes_read] = '\0';
			std::cout << read_buffer << std::endl;
			std::cout << bytes_read << " bytes read" << std::endl;

			if (!strncmp(read_buffer, "stop\n", 5))
			{
				std::cout << "Stop reached" << std::endl;
				running = 0;
			}
		}
	}

	if (close(epoll_fd))
		abort();
	return 0;
}

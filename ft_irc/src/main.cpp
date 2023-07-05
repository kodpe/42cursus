#include "IRC.hpp"
#include "Server.hpp"

#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "Bad number of arguments" << std::endl;
		std::cerr << "usage: /ircserv <port> <password>" << std::endl;
		return 1;
	}

	long long nb(0);

	if (-1 == sc_strtoll(argv[1], &nb, 0) || nb < 1024 || nb > 65535)
	{
		std::cerr << "Bad port number" << std::endl;
		if (nb < 1024 || nb > 65535)
			std::cerr << "please use a port between 1024 and 65535" << std::endl;
		return 1;
	}

	try {
		Server	serv((int)nb, argv[2]);
	}
	catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}

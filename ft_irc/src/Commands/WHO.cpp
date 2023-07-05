#include "Server.hpp"

void	Server::WHO(std::string nickchan)
{
	log_ok("WHO");

	if (nickchan.empty()) {
		RPL_ENDOFWHO(nickchan);
		return ;
	}

	if (nickchan[0] != '#') {
		int fd = nick_to_fd(nickchan);
		if (fd != -1)
			RPL_WHOREPLY(fd);
		RPL_ENDOFWHO(nickchan);
		return ;
	}

	if (_channels.find(nickchan) == _channels.end()) {
		RPL_ENDOFWHO(nickchan);
		return;
	}

	std::map< int, bool >			clt = _channels[nickchan]._client;
	std::map< int, bool >::iterator	it;
	for (it = clt.begin(); it != clt.end(); ++it)
		RPL_WHOREPLY(it->first);

	RPL_ENDOFWHO(nickchan);
}

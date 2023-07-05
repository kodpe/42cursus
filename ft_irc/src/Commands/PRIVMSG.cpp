#include "Server.hpp"

void	Server::PRIVMSG(std::string args)
{
	log_ok("PRIVMSG");

	if (args.empty()) {
		log_warn("PRIVMSG -> 411 ERR_NORECIPIENT");
		return ERR_NORECIPIENT();							// 411
	}

	std::string	msg(args);
	remove_first_word(msg);
	if (msg.size() == args.size() || msg.size() < 2) { 		// pas de message, il y a que des destinataires nick/chan
		log_warn("PRIVMSG -> 412 ERR_NOTEXTTOSEND");
		return ERR_NOTEXTTOSEND();							// 412
	}

	std::string nickchanlist = str_tolower(get_first_word(args));

	// on parcours nickchanlist pour check chaque nick/chan et leurs envoyer a chacun le msg
	std::string	nickchan;

	while (1) {
		if (nickchanlist.empty())				// nickchanlist est vide, fin de privmsg
			break ;

		size_t	pos = nickchanlist.find(',');
		if (pos == std::string::npos) { 		// si pas de ',' : nickchanlist contient un seul mot
			nickchan = nickchanlist;
			nickchanlist.erase();
		}
		else {
			nickchan = nickchanlist.substr(0, pos);
			nickchanlist.erase(0, pos + 1);
		}

		// if (nickchan.empty() || nickchan.find(',') != std::string::npos)
			// ABORT;

		std::string nick(_actual_client->get_nick());
		std::string user(_actual_client->get_username());
		std::string source(":"+nick+"!"+user+"@localhost");

		if (nickchan[0] == '#')
		{ 	// IS CHANNEL
			if (_channels.find(nickchan) == _channels.end()) {
				log_warn("PRIVMSG -> 401 ERR_NOSUCHNICK");
				ERR_NOSUCHNICK(nickchan); 			// 401
				continue ;
			}
			std::string full(source+" PRIVMSG "+_channels[nickchan].getName()+" "+msg+"\r\n");

			std::map<int, bool> client_list(_channels[nickchan]._client);
			std::map<int, bool>::iterator it;
			for (it = client_list.begin(); it != client_list.end(); ++it) {
				if (it->first == _actual_client->get_fd())
					continue ;
				_clients[it->first].add_to_send_buffer(full);
			}
		}
		else
		{ 	// IS NICK
			int fd(-1);
			std::map< int, Client >::iterator	it;

			for (it = _clients.begin(); it != _clients.end(); ++it) {
				if (cmp_icase(it->second.get_nick(), nickchan)) {
					fd = it->second.get_fd();
					break ;
				}
			}
			if (fd == -1) {
				log_warn("PRIVMSG -> 401 ERR_NOSUCHNICK");
				ERR_NOSUCHNICK(nickchan); 			// 401
				continue ;
			}
			std::string full(source+" PRIVMSG "+_clients[fd].get_nick()+" "+msg+"\r\n");
			_clients[fd].add_to_send_buffer(full);
		}
	}
}

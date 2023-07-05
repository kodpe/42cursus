#include "Server.hpp"

void	Server::NICK(std::string nickname)
{
	log_ok("NICK");

	bool	not_registered = !_actual_client->is_registered();
	// si le client n'est pas register alors il sera delete si une erreur survient
	// autrement un client deja register conservera son ancien nickname

	if (nickname.empty()) {
		log_warn("NICK -> 431 ERR_NONICKNAMEGIVEN");
		ERR_NONICKNAMEGIVEN();									// 431
		if (not_registered)
			_actual_client->set_to_delete();
		return ;
	}

	// ignores potential [ <hopcount> ] argument
	if (args_count(nickname) > 1)
		nickname = get_arg(nickname, 1);

	// on fais une copie du nickname en tolower pour vérifier sa validité
	std::string check = str_tolower(nickname);

	if (check.find_first_not_of(IRC_VALID_NICKNAME) != std::string::npos
			|| check.size() > 15
			|| std::isdigit(check[0])) {
		log_warn("NICK -> 432 ERR_ERRONEUSNICKNAME");
		ERR_ERRONEUSNICKNAME(nickname);							// 432
		if (not_registered)
			_actual_client->set_to_delete();
		return ;
	}

	// on check si le nickname n'est pas deja utilisé
	std::map < int, Client >::iterator	it;

	for (it = _clients.begin(); it != _clients.end(); ++it)
	{
		std::string	used = it->second.get_nick();
		if (cmp_icase(used, nickname)) {
			log_warn("NICK -> 433 ERR_NICKNAMEINUSE");
			ERR_NICKNAMEINUSE(used);							// 433
			// if (not_registered)
				// _actual_client->set_to_delete();
			return;
		}
	}

	if (not_registered) {
		_actual_client->set_register_data(IRC_REG_NICK);
		_actual_client->set_nick(nickname);
		if (_actual_client->is_registered())
			welcome();
		return ;
	}
	else // prevenir les autres clients qui ont un channel en commun
	{
		send_cmd_reply(nickname);
		std::map< std::string, Channel >::iterator	it;
		for (it = _channels.begin(); it != _channels.end(); ++it)
		{
			if (it->second.isInChannel(_actual_client->get_fd()))
				notify_clients_on_channel_nick(it->first, nickname);
		}
		_actual_client->set_nick(nickname);
	}
}

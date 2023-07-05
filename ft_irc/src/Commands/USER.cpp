#include "Server.hpp"

// /USER arg1 arg2 arg3 :arg4
void	Server::USER(std::string args)
{
	log_ok("USER");

	if (_actual_client->is_registered()) {
		log_warn("USER -> 462 ERR_ALREADYREGISTERED");
		return ERR_ALREADYREGISTERED(); 						// 462
	}

	if (args_count(args) != 4) {
		log_warn("USER -> 461 ERR_NEEDMOREPARAMS");
		ERR_NEEDMOREPARAMS("");				 					// 461
		_actual_client->set_to_delete();
		return ;
	}

	if (_clients.size() > IRC_MAX_USER) {
		log_warn("USER -> ERROR IRC_MAX_USER");
		send_error("The server is full, please try again later");
		_actual_client->set_to_delete();
		return ;
	}

	if (_actual_client->get_password() != _password) {
		if (_actual_client->get_to_delete())
			return ;
		log_warn("PASS -> 464 ERR_PASSWDMISMATCH");
		_actual_client->set_to_delete();
		return ERR_PASSWDMISMATCH(); // 464
	}

	_actual_client->set_username(get_arg(args, 1));
	_actual_client->set_hostname(get_arg(args, 2));
	_actual_client->set_servname(get_arg(args, 3));
	_actual_client->set_realname(get_arg(args, 4));

	std::string	fixreal = _actual_client->get_realname();
	if (fixreal[0] == ':' && fixreal.size() > 1)
		_actual_client->set_realname(fixreal.substr(1));

	_actual_client->set_register_data(IRC_REG_USER);

	if (_actual_client->is_registered())
		welcome();
}

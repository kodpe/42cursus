#include "Server.hpp"

void	Server::PASS(std::string password)
{
	log_ok("PASS");

	if (_actual_client->is_registered()) {
		log_warn("PASS -> 462 ERR_ALREADYREGISTERED");
		return ERR_ALREADYREGISTERED(); 						// 462
	}

	if (password.empty()) {
		log_warn("PASS -> 461 ERR_NEEDMOREPARAMS");
		_actual_client->set_to_delete();
		return ERR_NEEDMOREPARAMS(""); 							// 461
	}

	if (password != _password) {
		if (_actual_client->get_to_delete())
			return ;
		log_warn("PASS -> 464 ERR_PASSWDMISMATCH");
		_actual_client->set_to_delete();
		return ERR_PASSWDMISMATCH(); 							// 464
	}

	_actual_client->set_password(password);
	_actual_client->set_register_data(IRC_REG_PASS);

	if (_actual_client->is_registered())
		welcome();
}

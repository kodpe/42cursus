#include "Server.hpp"

void	Server::command_executor(std::string raw)
{
	// most irc servers limit msg to 512 bytes in length, including the \r\n
	// \r\n not in raw so len max is 510

	if ((raw.size()) > 510) {
		log_warn(("* -> 417 ERR_INPUTTOOLONG: '"+raw+"'").c_str());
		return ERR_INPUTTOOLONG();
	}

	std::string	name = str_toupper(get_first_word(raw));
	_actual_cmd_name = name;

	if (_cmdMap.find(name) == _cmdMap.end()) {
		log_warn(("unknown command: '"+name+"'").c_str());
		if (_actual_client->is_registered()) {
			log_warn("* -> 421 ERR_UNKNOWCOMMAND");
			ERR_UNKNOWNCOMMAND();
		}
		return ;
	}

	if (_actual_client->is_registered() == false) {
		if (name != "PASS" && name != "NICK" && name != "USER") {
			log_warn("* -> 451 ERR_NOTREGISTERED");
			return ERR_NOTREGISTERED();
		}
	}

	if (raw.find(' ') == std::string::npos)
		raw = "";
	else
		remove_first_word(raw);
	(this->*_cmdMap[name])(raw);
}

void	Server::command_handler(int client_socket)
{
	_actual_client	= &_clients[client_socket];

	while (1) {
		std::string	cmd_found = _actual_client->extract_next_command();
		if (cmd_found.empty())
			break ;

		if (VERBOSE) {
			std::string str("execute raw |" + cmd_found + "|");
			log_ok(str.c_str());
			std::cerr << "exec raw size: " << cmd_found.size() << "\n\n";
		}
		command_executor(cmd_found);
	}
	_actual_client = NULL;
}

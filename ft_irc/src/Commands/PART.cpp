#include "Server.hpp"

// check de syntaxe
// la fonction verifie qu il y ai pas de virgules ou d'espaces a un mauvais endroit (ce qui engloble la plupart des erreurs possibles)

static bool	correct_comma_syntax(std::string str)
{
	size_t	pos = 0;

	while (str.find(",", pos) != std::string::npos)
	{
		pos = str.find(",", pos);

		if (pos == 0 || str[pos + 1] == '\0')
			return false;

		if (str[pos - 1] == '#' || str[pos + 1] == ',')
			return false;

		pos++;
	}

	return true;
}

static bool	correct_diese_syntax(std::string str)
{
	size_t	pos = 0;

	while (str.find("#", pos) != std::string::npos)
	{
		pos = str.find("#", pos);

		if (str[pos + 1] == '\0' || str[pos + 1] == '#' || str[pos + 1] == ',')
			return false;

		if (pos > 0 && str[pos - 1] != ',')
			return false;

		pos++;
	}

	return true;
}

static bool	correct_syntax_part(std::string cmd)
{

	//on refuse les espaces
	if (cmd.find(' ') != std::string::npos)
		return false;

	if (std::count(cmd.begin(), cmd.end(), ','))
		if (!correct_comma_syntax(cmd))
			return false;

	if (std::count(cmd.begin(), cmd.end(), '#'))
		if (!correct_diese_syntax(cmd))
			return false;

	return true;

}

static void	fill_it_part(std::vector<std::string> & channels, std::string & cmd)
{
	std::size_t end = 0;
	std::size_t beg = 0;

	// On rentre d abord les channels dans le vecteur (cle vide pour l instant)
	while(cmd[beg] != '\0')
	{
		end = beg;
		while (cmd[end] && cmd[end] != ',')
			end++;
		channels.push_back(cmd.substr(beg, end - beg));
		//qu est ce que ca fait pour un seul char

		if (cmd[end] == ',')
			end++;
		beg = end;
	}
}


static void	add_diese_if_absent(std::vector<std::string> & channels)
{
	std::vector<std::string>::iterator it;

	for (it = channels.begin(); it != channels.end(); it++)
	{
		if (it->at(0) != '#')
			(*it).insert(0,1,'#');
	}
}


void	Server::quit_one_channel(std::string channel_name)
{

	if (_channels.find(channel_name) == _channels.end()) {
		log_warn("PART -> 403 ERR_NOSUCHCHANNEL");
		return ERR_NOSUCHCHANNEL(channel_name);

	}

	Channel & chan = _channels.find(channel_name)->second;

	if (chan.isInChannel(_actual_client->get_fd()) == false) {
		log_warn("PART -> 442 ERR_NOTONCHANNEL");
		return ERR_NOTONCHANNEL(chan.getName());
	}

	//SUCCES
	chan.delClient(_actual_client->get_fd());
	send_cmd_reply(chan.getName());
	notify_clients_on_channel(chan.getName(), "");

	if (chan.getClientNumber() == 0)
		_channels.erase(channel_name);
}


void	Server::PART(std::string cmd)
{
	log_ok("PART");

	if (cmd.empty()) {
		log_warn("PART -> 461 ERR_NEEDMOREPARAMS");
		return ERR_NEEDMOREPARAMS("");
	}

	if (!correct_syntax_part(cmd))
	{
		log_warn("Err bad part syntax");
		return ERR_NEEDMOREPARAMS("");//test
	}

	std::vector<std::string> channels;

	fill_it_part(channels, cmd);

	add_diese_if_absent(channels);

	for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); ++it)
		quit_one_channel(*it);
}

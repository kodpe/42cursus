#include "Server.hpp"

// check de syntaxe
// la fonction verifie qu il y ai pas de virgules ou d'espaces a un mauvais endroit (ce qui engloble la plupart des erreurs possibles)

static bool	correct_comma_syntax(std::string str)
{
	size_t	pos = 0;

	while (str.find(",", pos) != std::string::npos)
	{
		pos = str.find(',', pos);

		if (pos == 0 || str[pos + 1] == '\0')
			return false;

		if (str[pos + 1] == ',' || str[pos + 1] == ' ' || str[pos - 1] == '#')
			return false;

		pos++;
	}

	return true;
}

static bool	correct_diese_syntax(std::string str)
{
	size_t	pos = 0;

	while (str.find('#', pos) != std::string::npos)
	{
		pos = str.find('#', pos);

		if (str[pos + 1] == '\0' || str[pos + 1] == '#' || str[pos + 1] == ',')
			return false;

		if (pos > 0 && str[pos - 1] != ',')
			return false;

		pos++;
	}

	return true;
}

static bool	correct_syntax_list(std::string cmd)
{

	//on refuse les espaces
	if (cmd.find(' ') != std::string::npos)
		return false;

	//check des ,
	if (cmd.find(',') != std::string::npos)
		if (!correct_comma_syntax(cmd))
			return false;

	if (cmd.find('#') != std::string::npos)
		if (!correct_diese_syntax(cmd))
			return false;

	return true;
}

static void	fill_it_list(std::vector<std::string> & channels, std::string & cmd)
{
	std::size_t end = 0;
	std::size_t beg = 0;

	// On rentre d abord les channels dans le vecteur (cle vide pour l instant)
	while(cmd[beg] != '\0')
	{
		end = beg;
		while (cmd[end] && cmd[end] != ',')
			end++;
		if (end > beg)
			channels.push_back(cmd.substr(beg, end - beg));
		//qu est ce que ca fait pour un seul char

		if (cmd[end] == ',')
			end++;
		beg = end;
	}
}

bool	is_channel_private(Channel & chan)
{
	std::string pass = chan.getPassword();

	if (chan.getIsInviteOnly() || pass.empty() == 0)
		return true;

	return false;
}

static void	add_diese_if_absent(std::vector<std::string> & channels)
{
	std::vector<std::string>::iterator	it;

	for (it = channels.begin(); it != channels.end(); it++)
	{
		if (it->at(0) != '#')
			(*it).insert(0,1,'#');
	}
}

void	Server::LIST(std::string cmd)
{
	log_ok("LIST");

	RPL_LISTSTART();

	if (cmd.size())
	{
		if (!correct_syntax_list(cmd))
		{
			log_warn("LIST: bad syntax, envoi de RPL_LISTEND"); //end
			RPL_LISTEND();
			return ;
		}

		std::vector<std::string> channels;

		fill_it_list(channels, cmd);

		add_diese_if_absent(channels);

		for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); ++it)
		{
			if (_channels.find(*it) != _channels.end())
				RPL_LIST(_channels[*it].getName(), false);
		}
	}
	else
	{
		std::map< std::string, Channel >::iterator it;

		for (it = _channels.begin(); it != _channels.end(); it++)
			RPL_LIST(it->first, false);
	}

	RPL_LISTEND();
}

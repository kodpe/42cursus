#include "Server.hpp"

// check de syntaxe
// la fonction verifie qu il y ai pas de virgules ou d'espaces a un mauvais endroit (ce qui engloble la plupart des erreurs possibles)
// Peutetre rajouter un check pour les caracteres interdits dans les noms de channel, approfondir

typedef std::vector<std::pair<std::string, std::string> > strpair;

static bool	correct_comma_syntax(std::string str)
{
	size_t	pos = 0;

	while (str.find(',', pos) != std::string::npos)
	{
		pos = str.find(',', pos);

		if (pos == 0 || str[pos + 1] == '\0')
			return false;

		if (str[pos - 1] == ' ' || str[pos - 1] == '#')
			return false;

		if (str[pos + 1] == ',' || str[pos + 1] == ' ')
			return false;

		if (str.find(' ', pos) != std::string::npos)
			if (str[pos + 1] != '#')
				return false;

		pos++;
	}

	return true;
}

static bool	correct_space_syntax(std::string str)
{
	//on sait qu'il n y a qu'un seul espace
	size_t	pos = 0;
	pos = str.find(' ', pos);

	if (pos == 0 || str[pos + 1] == '\0')
		return false;

	if (str[pos - 1] == ',' || str[pos + 1] == ',')
		return false;

	return true;
}

static bool	correct_diese_syntax(std::string str)
{
	size_t	pos = 0;

	while (str.find('#', pos) != std::string::npos)
	{
		pos = str.find('#', pos);

		if (str[pos + 1] == '\0' || str[pos + 1] == '#'
				|| str[pos + 1] == ' ' || str[pos + 1] == ',')
			return false;

		if (pos > 0 && str[pos - 1] != ',')
			return false;

		pos++;
	}

	return true;
}

static bool	correct_syntax_join(std::string cmd)
{
	if (cmd[0] != '#')
		return false;

	//si il y a des virgules on verifie la syntaxe
	if(std::count(cmd.begin(), cmd.end(), ','))
		if (!correct_comma_syntax(cmd))
			return false;

	int nb_of_spaces = std::count(cmd.begin(), cmd.end(), ' ');

	if (nb_of_spaces > 1)
		return false;

	// check spaces
	if (nb_of_spaces == 1)
		if (!correct_space_syntax(cmd))
			return false;

	//check des #
	if(std::count(cmd.begin(), cmd.end(), '#'))
		if (!correct_diese_syntax(cmd))
			return false;

	return true;
}

static void	fill_it(strpair & chan_keys, std::string & cmd)
{
	std::size_t end = 0;
	std::size_t beg = 0;

	// On rentre d abord les channels dans le vecteur (cle vide pour l instant)
	while(cmd[beg] != ' ' && cmd[beg] != '\0')
	{
		end = beg;
		while (cmd[end] && cmd[end] != ',' && cmd[end] != ' ')
			end++;
		chan_keys.push_back(std::make_pair(cmd.substr(beg, end - beg), ""));
		//qu est ce que ca fait pour un seul char

		if (cmd[end] == ',')
			end++;
		beg = end;
	}

	int count = 0;

	if (cmd[beg] != ' ') // pas de cle
		return ;

	while (cmd[beg] == ' ')
		beg++;

	while(cmd[beg] != '\0')
	{
		if ((size_t)count == chan_keys.size())
			break;

		end = beg;
		while (cmd[end] && cmd[end] != ',')
			end++;

		chan_keys[count].second = cmd.substr(beg, end - beg); // check 25/05 03:11
		count++;
		//qu est ce que ca fait pour un seul char

		if (cmd[end] == ',')
			end++;
		beg = end;
	}


}

void	Server::create_channel(std::string channel_name, std::string channel_key)
{
	// if (channel_name.empty())
		// ABORT;
	// if (_actual_client == NULL)
		// ABORT;

	int nb_chan_joined = _actual_client->get_nb_chan_join();

	if (nb_chan_joined >= IRC_CHAN_PER_USER)
	{
		log_warn("JOIN -> 405 ERR_TOOMANYCHANNELS");
		return ERR_TOOMANYCHANNELS(channel_name);
	}

	if (channel_name.length() > 50)
	{
		log_warn("JOIN -> 471 ERR_NOSUCHCHANNEL");
		return ERR_NOSUCHCHANNEL(channel_name);
	}

	// new channel map key
	_channels[channel_name] = Channel();
	_channels[channel_name].setName(channel_name);

	if (channel_key.size())
		_channels[channel_name].setPassword(channel_key);

	// add client to chan and set operator
	_channels[channel_name].addClient(_actual_client->get_fd());
	_channels[channel_name].setOp(_actual_client->get_fd());

	// increment client nb chan joined
	_actual_client->set_nb_chan_join(++nb_chan_joined);

	// replies
	send_cmd_reply(channel_name);
	RPL_NAMREPLY(channel_name);
	RPL_ENDOFNAMES(channel_name);

	show_clients();
}

void	Server::join_existing_channel(std::string channel_name, std::string channel_key)
{
	Channel & chan = _channels[channel_name];

	if (chan.isInChannel(_actual_client->get_fd()))
	{
		log_warn("JOIN -> 443 ERR_USERONCHANNEL");
		return ERR_USERONCHANNEL(_actual_client->get_nick()+" "+chan.getName());
	}

	if (chan.getClientNumber() >= chan.getMaxClient() )
	{
		log_warn("JOIN -> 471 ERR_CHANNELISFULL");
		return ERR_CHANNELISFULL(chan.getName());
	}

	if (_actual_client->get_serv_operator() == false)
	{
		if (chan.getIsInviteOnly() && false == chan.isWhiteListed(_actual_client->get_fd()))
		{
			log_warn("JOIN -> 473 ERR_INVITEONLYCHAN");
			return ERR_INVITEONLYCHAN(chan.getName());
		}

		if (chan.isPassword() && channel_key != chan.getPassword())
		{
			log_warn("JOIN -> 475 ERR_BADCHANNELKEY");
			return ERR_BADCHANNELKEY(chan.getName());
		}
	}

	if (chan.getIsInviteOnly())
		chan.delWhiteList(_actual_client->get_fd()); //check

	//SUCCESS on ajoute l'utilisateur
	chan.addClient(_actual_client->get_fd());

	if (_actual_client->get_serv_operator() == true)
		_channels[channel_name].setOp(_actual_client->get_fd());

	send_cmd_reply(chan.getName());
	RPL_NAMREPLY(chan.getName());
	RPL_ENDOFNAMES(chan.getName());
	notify_clients_on_channel(chan.getName(), "");
}

void	Server::join_one_channel(std::string channel_name, std::string channel_key)
{
	////	Le Channel n'existe pas encore	////
	if (_channels.find(channel_name) == _channels.end()) {
		return create_channel(channel_name, channel_key);
	}

	////	Le Channel existe deja	////
	join_existing_channel(channel_name, channel_key);
}

void	Server::JOIN(std::string args)
{
	log_ok("JOIN");

	if (args.empty()) {
		log_warn("JOIN -> 461 ERR_NEEDMOREPARAMS");
		return ERR_NEEDMOREPARAMS("");
	}

	if (!correct_syntax_join(args))
	{
		log_warn("JOIN -> 471 ERR_NOSUCHCHANNEL");
		return ERR_NOSUCHCHANNEL(args);
	}

	strpair chan_keys;

	fill_it(chan_keys, args);


	for (strpair::iterator it = chan_keys.begin(); it != chan_keys.end(); ++it)
		join_one_channel(it->first, it->second);

}

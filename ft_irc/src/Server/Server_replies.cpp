#include "Server.hpp"

void	Server::RPL_WELCOME(void)
{
	std::string rpl(":Welcome to the Perceptron Network, "+_actual_client->get_username());
	send_num_reply("001", rpl);
}

#define NUM_RPL_YOURHOST "002"
void	Server::RPL_YOURHOST(void)
{
	std::string	servname(IRC_STR_SERVNAME);
	std::string	version(IRC_STR_VERSION);
	std::string rpl(":Your host is "+servname+", running version "+version);
	send_num_reply("002", rpl);
}

void	Server::RPL_CREATED(void)
{
	std::string rpl(":This server was created Mon May 8 2023 at 04:13:49 PM CEST");
	send_num_reply("003", rpl);
}

void	Server::RPL_MYINFO(void)
{
	std::string	servname(IRC_STR_SERVNAME);
	std::string	version(IRC_STR_VERSION);
	std::string rpl(servname+" "+version);
	send_num_reply("004", rpl);
}

void	Server::RPL_ISUPPORT(void)
{
	std::string rpl("CASEMAPPING=ascii NICKLEN=15 CHANTYPES=# :are supported by this server");
	send_num_reply("005", rpl);
}

void	Server::RPL_LUSERCLIENT(void)
{
	std::ostringstream	nb_clients;
	nb_clients << _clients.size();
	std::string rpl(":There are "+nb_clients.str()+" users on the server");
	send_num_reply("251", rpl);
}

void	Server::RPL_LUSERUNKNOWN(void)
{
	int	unk(0);
	std::map< int, Client >::iterator	it;

	for (it = _clients.begin(); it != _clients.end(); ++it)
	{
		if (it->second.is_registered() == false)
			++unk;
	}
	std::ostringstream	nb_unknown;
	nb_unknown << unk;

	std::string rpl(nb_unknown.str()+" :unknown connection(s)");
	send_num_reply("253", rpl);
}

void	Server::RPL_LUSERCHANNELS(void)
{
	std::ostringstream	nb_channels;
	nb_channels << _channels.size();
	std::string rpl(nb_channels.str()+" :channels formed");
	send_num_reply("254", rpl);
}

void	Server::RPL_ENDOFWHO(std::string str)
{
	std::string rpl(str+" :End of WHO list");
	send_num_reply("315", rpl);
}

void	Server::RPL_LISTSTART(void)
{
	std::string rpl = "Channel :Users  Name";

	send_num_reply("321", rpl);
}

void	Server::RPL_LIST(std::string channel_name, bool is_private)
{
	std::string rpl;

	Channel & chan = _channels[channel_name];

	std::ostringstream oss;
	oss << chan.getClientNumber();

	if (is_private)
		rpl = channel_name + " " + oss.str();
	else
		rpl = channel_name + " " + oss.str() + " :" + chan.getTopic();

	send_num_reply("322", rpl);
}

void	Server::RPL_LISTEND(void)
{
	std::string rpl = ":End of /LIST";

	send_num_reply("323", rpl);
}

void	Server::RPL_CHANNELMODEIS(std::string channel)
{
	std::string opt = "";
	if (_channels[channel].isPassword())
		opt += "k";
	if (_channels[channel].getIsInviteOnly())
		opt += "i";
	if (_channels[channel].getEditTopic())
		opt += "t";
	if (_channels[channel].getMaxClient() != IRC_CHAN_MAX_USER)
		opt += "l";
	
	std::string rpl(channel+" +"+opt);
	send_num_reply("324", rpl);
}

void	Server::RPL_NOTOPIC(std::string channel)
{
	std::string rpl = channel+" No topic is set";
	send_num_reply("331", rpl);
}

void	Server::RPL_TOPIC(std::string channel)
{
	std::string rpl = channel+" "+_channels[channel].getTopic();
	send_num_reply("332", rpl);
}

void	Server::RPL_WHOREPLY(int fd)
{

	// "<client> <channel> <username> <host> <server> <nick> H :1 <realname>"

	std::string	channel("*");
	std::map< std::string, Channel >::iterator	it;
	for (it = _channels.begin(); it != _channels.end(); ++it)
		if (it->second.isInChannel(fd))
			channel = it->first;

	std::string	username 	= _clients[fd].get_username();
	std::string	hostname 	= _clients[fd].get_hostname();
	std::string server		= _clients[fd].get_servname();
	std::string	nick 		= _clients[fd].get_nick();
	std::string	realname 	= _clients[fd].get_realname();

	std::string rpl(channel+" "+username+" "+hostname+" "+server+" "+nick+" H :1 "+realname);
	send_num_reply("352", rpl);
}

void	Server::RPL_NAMREPLY(std::string channel_name)
{
	std::string rpl("= " + channel_name + " :");

	Channel chan = _channels[channel_name];

	std::map<int, bool>::iterator it = chan._client.begin();

	// append all operators
	for (it = chan._client.begin(); it != chan._client.end(); it++) {
		if (it->second == true) // if client is operator
			rpl.append(" @"+ _clients[it->first].get_nick());
	}

	// append others clients
	for (it = chan._client.begin(); it != chan._client.end(); it++) {
		if (it->second == false)
			rpl.append(" "+ _clients[it->first].get_nick());
	}

	send_num_reply("353", rpl);
}

void	Server::RPL_ENDOFNAMES(std::string channel_name)
{
	std::string rpl(channel_name + " :End of NAME list.");

	send_num_reply("366", rpl);
}

void	Server::RPL_YOUREOPER(void)
{
	std::string rpl(" You are now an operator of the server");

	send_num_reply("381", rpl);
}

void	Server::ERR_NOSUCHNICK(std::string nick)
{
	std::string rpl(nick+" :No such nick/channel");
	send_num_reply("401", rpl);
}

void	Server::ERR_NOSUCHCHANNEL(std::string channel)
{
	std::string rpl(channel+" :No such channel");
	send_num_reply("403", rpl);
}

void	Server::ERR_CANNOTSENDTOCHAN(std::string channel)
{
	std::string rpl(channel+" :Cannot send to channel");
	send_num_reply("404", rpl);
}

void	Server::ERR_TOOMANYCHANNELS(std::string channel)
{
	std::string rpl(channel+" :You have joined too many channels");
	send_num_reply("405", rpl);
}

void	Server::ERR_NORECIPIENT(void)
{
	std::string rpl(":No recipient given");
	send_num_reply("411", rpl);
}

void	Server::ERR_NOTEXTTOSEND(void)
{
	std::string rpl(":No text to send");
	send_num_reply("412", rpl);
}

void	Server::ERR_INPUTTOOLONG(void)
{
	std::string rpl(":Input line was too long");
	send_num_reply("417", rpl);
}

void	Server::ERR_UNKNOWNCOMMAND(void)
{
	std::string message(":Unknown command");
	std::string	rpl(_actual_cmd_name+" "+message);
	send_num_reply("421", rpl);
}

void	Server::ERR_NONICKNAMEGIVEN(void)
{
	std::string rpl(":No nickname given");
	send_num_reply("431", rpl);
}

void	Server::ERR_ERRONEUSNICKNAME(std::string nick)
{
	std::string rpl(nick+" :Erroneus nickname");
	send_num_reply("432", rpl);
}

void	Server::ERR_NICKNAMEINUSE(std::string nick)
{
	std::string rpl(nick+" :Nickname is already in use");
	send_num_reply("433", rpl);
}

void	Server::ERR_USERNOTINCHANNEL(std::string nick)
{
	std::string rpl(nick+" :They aren't on that channel");
	send_num_reply("441", rpl);
}

void	Server::ERR_NOTONCHANNEL(std::string channel)
{
	std::string rpl(channel+" :You're not on that channel");
	send_num_reply("442", rpl);
}

void	Server::ERR_USERONCHANNEL(std::string nick)
{
	std::string rpl(nick+" :is already on channel");
	send_num_reply("443", rpl);
}

void	Server::ERR_NOTREGISTERED(void)
{
	std::string rpl(":You have not registered");
	send_num_reply("451", rpl);
}

void	Server::ERR_NEEDMOREPARAMS(std::string opt)
{
	std::string message(":Not enough parameters");
	std::string	rpl(_actual_cmd_name+opt+" "+message);
	send_num_reply("461", rpl);
}

void	Server::ERR_ALREADYREGISTERED(void)
{
	std::string rpl(":You may not reregister");
	send_num_reply("462", rpl);
}

void	Server::ERR_PASSWDMISMATCH(void)
{
	std::string rpl(":Password incorrect");
	send_num_reply("464", rpl);
}

void	Server::ERR_KEYSET(std::string channel)
{
	std::string rpl(channel+" :Channel key already set");
	send_num_reply("467", rpl);
}

void	Server::ERR_CHANNELISFULL(std::string channel)
{
	std::string rpl(channel+" :Cannot join channel (+l)");
	send_num_reply("471", rpl);
}

void	Server::ERR_UNKNOWNMODE(std::string err_char)
{
	std::string rpl(err_char+" :is unknown mode char to me");
	send_num_reply("472", rpl);
}

void	Server::ERR_INVITEONLYCHAN(std::string channel)
{
	std::string rpl(channel+" :Cannot join channel (+i)");
	send_num_reply("473", rpl);
}

void	Server::ERR_BADCHANNELKEY(std::string channel)
{
	std::string rpl(channel+" :Cannot join channel (+k)");
	send_num_reply("475", rpl);
}

void	Server::ERR_NOPRIVILEGES(std::string reason)
{
	std::string rpl(reason);
	send_num_reply("481", rpl);
}

void	Server::ERR_CHANOPRIVSNEEDED(std::string channel)
{
	std::string rpl(channel+" :You're not channel operator");
	send_num_reply("482", rpl);
}

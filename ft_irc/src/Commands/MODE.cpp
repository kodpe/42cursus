#include "Server.hpp"

void	Server::MODE(std::string args)
{
	log_ok("MODE");

	std::vector<std::string> arguments;
	std::string channel_name, options, tmp;
	std::stringstream iss(args);
	char ret;

	if (args.empty())
	{
		log_warn("MODE -> 403 ERR_NOSUCHCHANNEL");
		return ERR_NOSUCHCHANNEL("");
	}

	for (int i = 0; getline(iss, tmp, ' '); ++i)
	{
		switch (i)
		{
			case 0:
				channel_name = tmp;
				break;
			case 1:
				options = tmp;
				break;
			default:
				arguments.push_back(tmp);
		}
	}

	if (channel_name[0] != '#') {
		log_warn("MODE -> 472 ERR_UNKNOWNMODE");
		return ERR_UNKNOWNMODE(tmp);
	}

	std::map<std::string, Channel>::iterator channel_it = _channels.find(channel_name);

	if (channel_it == _channels.end()) {
		log_warn("MODE -> 403 ERR_NOSUCHCHANNEL");
		return ERR_NOSUCHCHANNEL(channel_name);
	}

	if (options.empty()) {
		log_ok("MODE -> 324 RPL_CHANNELMODEIS");
		return RPL_CHANNELMODEIS(channel_it->first);
	}

	for (std::string::iterator it = options.begin(); it != options.end(); ++it)
	{
		if (*it == '-' || *it == '+')
			ret = *it;
		else
		{
			if (arguments.size() == 0)
				arguments.push_back("");
			if (it == options.begin())
			{
				log_warn("MODE -> 472 ERR_UNKNOWNMODE");
				return ERR_UNKNOWNMODE(tmp);
			}
			*(it - 1) = ret;

			std::string	opt = options.substr((it - 1) - options.begin(), 2);

			switch (*it)
			{
				case 'k':
					mode_k(channel_it->second, opt, arguments.front()); // pwd
					arguments.erase(arguments.begin());
					break;

				case 't':
					mode_tt(channel_it->second, opt);
					break;

				case 'i':
					mode_i(channel_it->second, opt);
					break;

				case 'l':
					if (*(it - 1) == '-')
						mode_l(channel_it->second, opt, "no arg");
					else
					{
						mode_l(channel_it->second, opt, arguments.front()); // size
						arguments.erase(arguments.begin());
					}
					break;

				case 'o':
					mode_o(channel_it->second, opt, arguments.front()); // nick
					arguments.erase(arguments.begin());
					break;

				default:
					tmp[0] = *it;
					tmp[1] = 0;
					log_warn("MODE -> 472 ERR_UNKNOWNMODE");
					ERR_UNKNOWNMODE(tmp);
			}
		}
	}
}

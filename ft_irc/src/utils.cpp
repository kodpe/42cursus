#include "IRC.hpp"

int    sc_strtoll(const char *str, long long *nb, char next)
{
    char    *endptr;

    if (str == NULL || !isdigit(*str))
        return -1;
    *nb = strtoll(str, &endptr, 10);
    if ((*nb == 0 && endptr == str) || errno == ERANGE || *endptr != next)
        return -1;
    if (*nb < 1 || *nb > 2147483647)
        return -1;
    return 0;
}

std::string	str_toupper(std::string str)
{
	 transform(str.begin(), str.end(), str.begin(), ::toupper);
	 return str;
}

std::string	str_tolower(std::string str)
{
	 transform(str.begin(), str.end(), str.begin(), ::tolower);
	 return str;
}

bool	cmp_icase(std::string s1, std::string s2)
{
	return (str_tolower(s1) == str_tolower(s2));
}

void	sc_close(int fd)
{
	if (fd < 0) {
		log_fail(IRC_STR_CLOSE);
		return ;
	}
	if (-1 == close(fd))
		throw_irc(IRC_STR_CLOSE)
}

void	set_non_blocking(int fd)
{
	if (fd < 0) {
		log_fail(IRC_STR_FCNTL);
		return ;
	}
	if (-1 == fcntl(fd, F_SETFL, O_NONBLOCK)) {
		sc_close(fd);
		throw_irc(IRC_STR_FCNTL);
	}
}

void	remove_first_word(std::string & str)
{
	size_t	pos;

	pos = str.find(' ');
	if (pos != std::string::npos)
		str.erase(0, pos + 1);
}

std::string	get_first_word(std::string & str)
{
	size_t	pos;

	if (str.empty())
		return "";

	pos	= str.find(' ');
	if (pos == std::string::npos)
		return str;
	return str.substr(0, pos);
}

/*
static bool	check_str_integrity(std::string & str)
{
	// check for multiples ':'
	std::string::iterator	it;
	int						cnt(0);
	for (it = str.begin(); it != str.end(); ++it)
		if (*it == ':')
			++cnt;
	if (cnt > 1)
		return false;
	return true;
}
*/

std::string	get_arg(std::string & str, int index)
{
	// assert(check_str_integrity(str));

	std::string::iterator	it;
	std::string				arg("");
	int						count(0);
	int						i(0);
	int						start(0);
	int						len(0);

	for (it = str.begin(); it != str.end(); ++it)
	{
		if (*it != ' ') {
			++count;
			if (*it == ':') {
				if (count == index)
					arg = str.substr(i);
				break ;
			}
			start = i;
			len = 0;
			while (it != str.end() && *it != ' ') {
				++it;
				++len;
				++i;
			}
			if (count == index) {
				arg = str.substr(start, len);
				break ;
			}
		}
		++i;
	}
	// std::cerr << "get_arg(" << index << ") = |" << arg << "|\n";
	// if (arg[0] != ':')
		// assert(arg.find(' ') == std::string::npos);
	return arg;
}

int	args_count(std::string & str)
{
	// assert(check_str_integrity(str));

	std::string::iterator	it;
	int	count = 0;

	for (it = str.begin(); it != str.end(); ++it) {
		if (*it != ' ') {
			++count;
			if (*it == ':')
				break ;
			while (it != str.end() && *it != ' ')
				++it;
			if (it == str.end())
				break ;
		}
	}
	// std::cerr << "arg_count() |" << str << "|\n";
	// std::cerr << "count = " << count << "\n";
	return count;
}

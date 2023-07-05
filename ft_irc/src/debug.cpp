#include "IRC.hpp"

void	show_on(void)
{
	if (!VERBOSE)
		return;
	std::cerr << "\033[32m+\033[0m";
}

void	show_off(void)
{
	if (!VERBOSE)
		return;
	std::cerr << "\033[31mx\033[0m";
}

void	px(int n, const char *str)
{
	if (!VERBOSE)
		return;
	for (int i = 0; i < n; ++i)
		std::cerr << str;
}

void	show_date(void)
{
	return;
	time_t		curr_time;
	struct tm	*tms;

	curr_time = time(NULL);
	tms = localtime(&curr_time);

	std::cerr.fill('0');
	std::cerr	<< std::setw(2) << tms->tm_hour << ":"
				<< std::setw(2) << tms->tm_min << ":"
				<< std::setw(2) << tms->tm_sec << " ";
	std::cerr.fill(' ');
}

void	log_nl(void) {
	if (!VERBOSE)
		return;
	std::cerr << std::endl;
}

void	log_fail(const char *msg) {
	show_date(); std::cerr << "[\033[31m  FAIL  \033[0m] " << msg << std::endl;
}

void	log_ok(const char *msg) {
	show_date(); std::cerr << "[\033[32m   OK   \033[0m] " << msg << std::endl;
}

void	log_warn(const char *msg) {
	show_date(); std::cerr << "[\033[33m  WARN  \033[0m] " << msg << std::endl;
}

void	log_info(const char *msg) {
	show_date(); std::cerr << "[\033[34m  INFO  \033[0m] " << msg << std::endl;
}

void	log_todo(const char *msg) {
	show_date(); std::cerr << "[\033[35m  TODO  \033[0m] " << msg << std::endl;
}

void	putxnl(int x, const char * str)
{
	if (!VERBOSE)
		return;
	for (int i = 0; i < x; ++i)
		std::cerr << str;
	std::cerr << std::endl;
}

void	show_vector(std::vector<std::string> vec)
{
	if (!VERBOSE)
		return;
	std::vector<std::string>::iterator	it;
	int	n(0);

	for (it = vec.begin(); it != vec.end(); ++it) {
		std::cerr << n << ": ['" << *it << "']" << std::endl;
		++n;
	}
}

void	show_epoll_specs(uint32_t ev)
{
	if (!VERBOSE)
		return;
	std::cerr << " ................ EPOLL EVENTS DETECTED ................\n";
	std::cerr << " EPOLLIN........00000001 (0x1)  : " << EPOLLIN      << "\n";
	std::cerr << " EPOLLOUT.......00000010 (0x2)  : " << EPOLLOUT     << "\n";
	std::cerr << " EPOLLERR.......00000100 (0x4)  : " << EPOLLERR     << "\n";
	std::cerr << " EPOLLHUP.......00001000 (0x8)  : " << EPOLLHUP     << "\n";
	std::cerr << " EPOLLRDHUP.....00010000 (0x10) : " << EPOLLRDHUP   << "\n";

	std::cerr << " event found [" << ev << "] ";
	if (ev & EPOLLIN)
		std::cerr << "EPOLLIN";
	if (ev & EPOLLOUT)
		std::cerr << "EPOLLOUT";
	if (ev & EPOLLERR)
		std::cerr << "EPOLLERR";
	if (ev & EPOLLHUP)
		std::cerr << "EPOLLHUP";
	if (ev & EPOLLRDHUP)
		std::cerr << "EPOLLRDHUP";
	std::cerr << std::endl;
} 

/*
void	put_hex_str(std::string & str)
{
	if (!VERBOSE)
		return;
	fprintf(stderr, "'%s'", str.c_str());
	fprintf(stderr, "hex: ");
	for (int i = 0; str[i]; ++i)
		fprintf(stderr, "%02x ", str[i]);
	fprintf(stderr, "\n");
}

void	show_raw(std::string & str, const char * title)
{
	if (!VERBOSE)
		return;
	std::cerr << "\033[33m-- RAW ---------------------- " << title << "\033[0m\n";
	for (int i = 0; str[i]; ++i) {
		if (str[i] == '\r')
			fprintf(stderr, "\\r");
		else if (str[i] == '\n')
			fprintf(stderr, "\\n\n");
		else
			fprintf(stderr, "%c", str[i]);
	}
	std::cerr << "\033[33m-- RAW END ------------------\033[0m\n\n";
}
*/

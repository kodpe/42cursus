#ifndef IRC_HPP
# define IRC_HPP

#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <cerrno>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <csignal>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

#include "ExceptionIRC.hpp"

#define IRC_STR_SERVNAME	"chupacabra"
#define	IRC_STR_VERSION		"0.7.21"

#define IRC_MAX_USER		100		// nb user max sur le serveur
#define	IRC_RECV_BUF_SIZE	2048	// size max du buffer de recv()
#define IRC_VALID_NICKNAME	"0123456789abcdefghijklmnopqrstuvwxyz_-{}[]\\|"
#define IRC_CHAN_MAX_USER	100		// nb user max sur un channel
#define IRC_CHAN_PER_USER	50		// nb channel max que peut creer un user

#define VERBOSE	1
#define DEBUG	0

// #define	NEWLINE				if (VERBOSE) { std::cerr << std::endl; }
// #define CPNT				if (VERBOSE) { std::cerr << __FILE__ << ":" << __LINE__ << ":"; }
// #define LOG(msg)			if (VERBOSE) { CPNT std::cerr << " " << msg << std::endl; }
// #define LOGV(name, value)	if (VERBOSE) { CPNT std::cerr << "\t\t" << name << " = '" << value << "'" << std::endl; }
// #define PAUSE				if (DEBUG)	 { CPNT std::cerr << "pause()..";getchar(); }
// #define ABORT				if (DEBUG)	 { CPNT perror(__FUNCTION__); std::cerr << "*ABORTED*\n"; abort(); }

#define C_RESET		"\033[0m"
#define C_RED		"\033[31m"
#define C_GREEN		"\033[32m"
#define C_YELLOW	"\033[33m"

#define IRC_REG_PASS 0
#define IRC_REG_NICK 1
#define IRC_REG_USER 2

#define IRC_STR_SOCKET		"Error: socket()"
#define IRC_STR_BIND		"Error: bind()"
#define IRC_STR_LISTEN		"Error: listen()"
#define IRC_STR_GETSOCKNAME	"Error: getsockname()"
#define IRC_STR_EPPOLCREATE	"Error: epoll_create1()"
#define IRC_STR_EPPOLCTL	"Error: epoll_ctl()"
#define IRC_STR_EPPOLWAIT	"Error: epoll_wait()"
#define IRC_STR_FCNTL		"Error: fcntl()"
#define IRC_STR_CLOSE		"Error: close()"
#define IRC_STR_SEND		"Error: send()"

/**
 *	utils.cpp
*/
int    		sc_strtoll(const char *str, long long *nb, char next);
std::string	str_toupper(std::string str);
std::string	str_tolower(std::string str);
bool		cmp_icase(std::string s1, std::string s2);
void		sc_close(int fd);
void		set_non_blocking(int fd);
void		remove_first_word(std::string & str);
std::string	get_first_word(std::string & str);
std::string	get_arg(std::string & str, int index);
int			args_count(std::string & str);

/**
 *	debug.cpp
*/
void		show_on(void);
void		show_off(void);
void		px(int n, const char *str);
void		show_date(void);
void		log_nl(void);
void		log_fail(const char *msg);
void		log_ok(const char *msg);
void		log_warn(const char *msg);
void		log_info(const char *msg);
void		log_todo(const char *msg);
void		putxnl(int x, const char * str);
void		show_vector(std::vector<std::string> vec);
void		show_epoll_specs(uint32_t ev);

#endif /* IRC_HPP */

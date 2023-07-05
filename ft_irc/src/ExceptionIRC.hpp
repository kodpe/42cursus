#ifndef EXCEPTIONIRC_CLASS_HPP
# define EXCEPTIONIRC_CLASS_HPP

#include "IRC.hpp"

#define throw_irc(msg) throw ExceptionIRC(__FILE__, __LINE__, msg);

class ExceptionIRC : public std::exception
{
	public:
    	ExceptionIRC(const char *file, int line, const std::string &arg);
    	~ExceptionIRC() throw();
    	virtual const char *what(void) const throw() {
			return msg.c_str();
		}

	private:
    	std::string msg;
};

#endif /* EXCEPTIONIRC_CLASS_HPP */

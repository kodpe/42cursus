#include "ExceptionIRC.hpp"

ExceptionIRC::ExceptionIRC(const char *file, int line, const std::string &arg)
{
	log_fail("ExceptionIRC");
	std::ostringstream out;
	out << file << ":" << line << ":" << arg;
	msg = out.str();
}

ExceptionIRC::~ExceptionIRC() throw()
{
	// std::cerr << "ExceptionIRC destructor" << std::endl;
}

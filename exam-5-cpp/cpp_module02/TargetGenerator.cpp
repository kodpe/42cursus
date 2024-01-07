#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
	std::map< std::string, ATarget * >::iterator it_begin = sps.begin();
	std::map< std::string, ATarget * >::iterator it_end = sps.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	sps.clear();
}

void TargetGenerator::learnTargetType(ATarget * ptr)
{
	if (ptr)
		sps.insert(std::pair< std::string, ATarget * >(ptr->getType(), ptr->clone()));
}

void TargetGenerator::forgetTargetType(std::string const & name)
{
	std::map< std::string, ATarget * >::iterator it = sps.find(name);
	if (it != sps.end())
		delete it->second;
	sps.erase(name);

}

ATarget * TargetGenerator::createTarget(std::string const & name)
{
	std::map< std::string, ATarget * >::iterator it = sps.find(name);
	if (it != sps.end())
		return sps[name];
	return NULL;
}


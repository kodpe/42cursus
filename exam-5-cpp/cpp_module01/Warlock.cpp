#include "Warlock.hpp"

Warlock::Warlock(std::string const & name, std::string const & title)
{
	this->name = name;
	this->title = title;
	std::cout << name + ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << name + ": My job here is done!\n";
	std::map< std::string, ASpell * >::iterator it_begin = sps.begin();
	std::map< std::string, ASpell * >::iterator it_end = sps.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	sps.clear();
}

std::string const & Warlock::getName() const
{
	return name;
}

std::string const & Warlock::getTitle() const
{
	return title;
}

void Warlock::setTitle(std::string const & title)
{
	this->title = title;
}

void Warlock::introduce() const
{
	std::cout << name+": I am "+name+", "+title+"!\n";
}

void Warlock::learnSpell(ASpell * ptr)
{
	if (ptr)
		sps.insert(std::pair< std::string, ASpell * >(ptr->getName(), ptr->clone()));

}

void Warlock::forgetSpell(std::string name)
{
	std::map< std::string, ASpell * >::iterator it = sps.find(name);
	if (it != sps.end())
		delete it->second;
	sps.erase(name);

}

void Warlock::launchSpell(std::string name, ATarget const & target_ref)
{
	ASpell * sp = sps[name];
	if (sp)
		sp->launch(target_ref);

}

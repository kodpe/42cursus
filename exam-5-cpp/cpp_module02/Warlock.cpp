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
	book.learnSpell(ptr);
}

void Warlock::forgetSpell(std::string name)
{
	book.forgetSpell(name);
}

void Warlock::launchSpell(std::string name, ATarget const & target_ref)
{
	ASpell * sp = book.createSpell(name);
	if (sp)
		sp->launch(target_ref);
}

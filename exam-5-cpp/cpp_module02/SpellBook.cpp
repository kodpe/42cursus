#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
	std::map< std::string, ASpell * >::iterator it_begin = sps.begin();
	std::map< std::string, ASpell * >::iterator it_end = sps.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	sps.clear();
}

void SpellBook::learnSpell(ASpell * ptr)
{
	if (ptr)
		sps.insert(std::pair< std::string, ASpell * >(ptr->getName(), ptr->clone()));

}

void SpellBook::forgetSpell(std::string const & name)
{
	std::map< std::string, ASpell * >::iterator it = sps.find(name);
	if (it != sps.end())
		delete it->second;
	sps.erase(name);

}

ASpell * SpellBook::createSpell(std::string const & name)
{
	std::map< std::string, ASpell * >::iterator it = sps.find(name);
	if (it != sps.end())
		return sps[name];
	return NULL;
}


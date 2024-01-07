#ifndef SL_SpellBook
#define SL_SpellBook

#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:
		std::map< std::string, ASpell * > sps;


		SpellBook(SpellBook const & other);
		SpellBook & operator=(SpellBook const & other);

	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell * aspell_ptr);
		void forgetSpell(std::string const & name);
		ASpell * createSpell(std::string const & name);

};

#endif

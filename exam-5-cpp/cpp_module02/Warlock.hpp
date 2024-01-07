#ifndef SL_WARLOCK
#define SL_WARLOCK

#include <iostream>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		SpellBook book;

		Warlock();
		Warlock(Warlock const & other);
		Warlock & operator=(Warlock const & other);

	public:
		Warlock(std::string const & name, std::string const & title);
		~Warlock();

		std::string const & getName() const;
		std::string const & getTitle() const;
		void setTitle(std::string const & title);
		void introduce() const;

		void learnSpell(ASpell * aspell_ptr);
		void forgetSpell(std::string name);
		void launchSpell(std::string name, ATarget const & target_ref);

};

#endif

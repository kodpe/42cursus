#ifndef SL_Fireball
#define SL_Fireball

#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
		Fireball();
		~Fireball();
		virtual ASpell *clone() const;
};

#endif

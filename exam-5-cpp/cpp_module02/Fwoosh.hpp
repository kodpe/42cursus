#ifndef SL_Fwoosh
#define SL_Fwoosh

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();
		virtual ASpell *clone() const;
};

#endif

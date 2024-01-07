#ifndef SL_Polymorph
#define SL_Polymorph

#include "ASpell.hpp"

class Polymorph : public ASpell
{
	public:
		Polymorph();
		~Polymorph();
		virtual ASpell *clone() const;
};

#endif

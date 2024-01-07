#ifndef SL_Dummy
#define SL_Dummy

#include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();
		virtual ATarget *clone() const;
};

#endif

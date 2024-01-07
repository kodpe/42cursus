#ifndef SL_BrickWall
#define SL_BrickWall

#include "ATarget.hpp"

class BrickWall : public ATarget
{
	public:
		BrickWall();
		~BrickWall();
		virtual ATarget *clone() const;
};

#endif

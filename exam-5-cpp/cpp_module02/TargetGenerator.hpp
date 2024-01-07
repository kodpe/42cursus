#ifndef SL_TargetGenerator
#define SL_TargetGenerator

#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::map< std::string, ATarget * > sps;

		TargetGenerator(TargetGenerator const & other);
		TargetGenerator & operator=(TargetGenerator const & other);

	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget * ATarget_ptr);
		void forgetTargetType(std::string const & name);
		ATarget * createTarget(std::string const & name);

};

#endif

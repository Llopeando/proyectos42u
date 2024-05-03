#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP
#include <map>

class ATarget;

class TargetGenerator {
	public:
		TargetGenerator();
		~TargetGenerator();

		/* Inherited from ATARGET */
		void learnTargetType(ATarget *ref);
		void forgetTargetType(std::string const &targettype);
		ATarget * createTarget(std::string const &targettype);
	private:
		TargetGenerator &operator=(const TargetGenerator &ref);
		std::map<std::string, ATarget *> map;
};

#endif
#ifndef ATARGET_HPP
#include "ATarget.hpp"
#endif
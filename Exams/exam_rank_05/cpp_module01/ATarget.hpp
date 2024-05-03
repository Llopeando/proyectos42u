#ifndef ATARGET_HPP
#define ATARGET_HPP
#include <iostream>

class ASpell;

class ATarget {
	public:
		ATarget(std::string type);
		virtual ~ATarget();

		std::string const &getType() const;
		void getHitBySpell(const ASpell &ref) const;

		virtual ATarget *clone() const = 0;

		ATarget &operator=(const ATarget &ref);
	private:
		std::string _type;
};

#endif
#ifndef ASPELL_HPP
#include "ASpell.hpp"
#endif
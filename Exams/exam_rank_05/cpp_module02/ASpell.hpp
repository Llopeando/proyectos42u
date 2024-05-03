#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>
#include "ATarget.hpp"

class ASpell {
	public:
		ASpell(std::string name, std::string effects);
		virtual ~ASpell();

		std::string getName() const;
		std::string getEffects() const;
		void launch(const ATarget &ref) const;

		virtual ASpell *clone() const = 0;

		ASpell &operator=(const ASpell &ref);
	private:
		std::string _name;
		std::string _effects;
};

#endif
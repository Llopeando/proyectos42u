#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP
#include <map>

class ASpell;

class SpellBook {
	public:
		SpellBook();
		~SpellBook();

		SpellBook &operator=(const SpellBook &ref);

		/* Inherited from ASPELL and ATARGET */
		void learnSpell(ASpell *ref);
		void forgetSpell(std::string const &spellName);
		ASpell* createSpell(std::string const &spellName);
	private:
		std::map<std::string, ASpell *> spellMap;
};

#endif
#ifndef ASPELL_HPP
#include "ASpell.hpp"
#endif
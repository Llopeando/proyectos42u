#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &title);
		void introduce() const;

		/* Inherited from ASPELL and ATARGET */
		void learnSpell(ASpell *ref);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, const ATarget &ref);

		Warlock &operator=(const Warlock &ref);
	private:
		std::string _name;
		std::string _title;

		SpellBook spellbook;
};
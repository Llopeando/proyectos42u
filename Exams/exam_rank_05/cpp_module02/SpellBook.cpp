#include "SpellBook.hpp"

SpellBook::SpellBook() {

}

SpellBook::~SpellBook() {

}

SpellBook &SpellBook::operator=(const SpellBook &ref) {
	this->spellMap = ref.spellMap;
	return (*this);
}


/* Inherited from ASPELL and ATARGET */
void SpellBook::learnSpell(ASpell *ref) {
	spellMap[ref->getName()] = ref->clone();
}

void SpellBook::forgetSpell(std::string const &spellName) {
	std::map<std::string, ASpell *>::iterator it = spellMap.find(spellName);
	if (it != spellMap.end()) {
		delete it->second;
		spellMap.erase(it);
	}
}

ASpell* SpellBook::createSpell(std::string const &spellName) {
	std::map<std::string, ASpell *>::iterator it = spellMap.find(spellName);
	if (it != spellMap.end()) {
		return it->second->clone();
	}
	return NULL;
}

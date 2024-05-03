#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) {
	this->_name = name;
	this->_title =  title;
	std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << getName() << ": My job here is done!" << std::endl;
}

Warlock &Warlock::operator=(const Warlock &ref) {
	this->_name = ref._name;
	this->_title = ref._title;
	return (*this);
}

std::string const &Warlock::getName() const {
	return _name;
}

std::string const &Warlock::getTitle() const {
	return _title;
}

void Warlock::setTitle(std::string const &title) {
	_title = title;
}

void Warlock::introduce() const {
	std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

/* Inherited from ASPELL and ATARGET */
void Warlock::learnSpell(ASpell *ref) {
	if (ref)
		spellMap.insert(std::pair<std::string, ASpell *>(ref->getName(), ref->clone()));
}

void Warlock::forgetSpell(std::string spellName) {
	std::map<std::string, ASpell *>::iterator it = spellMap.find(spellName);
	if (it != spellMap.end()) {
		delete it->second;
		spellMap.erase(it);
	}
}

void Warlock::launchSpell(std::string spellName, const ATarget &ref) {
	std::map<std::string, ASpell *>::iterator it = spellMap.find(spellName);
	if (it != spellMap.end()) {
		it->second->launch(ref);
	}
}
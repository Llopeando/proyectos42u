#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) {
	this->_name = name;
	this->_effects = effects;

}

ASpell::~ASpell() {

}

ASpell &ASpell::operator=(const ASpell &ref) {
	this->_name = ref._name;
	this->_effects = ref._effects;
	return (*this);
}

std::string ASpell::getName() const {
	return _name;
}

std::string ASpell::getEffects() const {
	return _effects;
}

void ASpell::launch(const ATarget &ref) const {
	ref.getHitBySpell(*this);
}
#include "ATarget.hpp"

ATarget::ATarget(std::string type) {
	this->_type = type;
}

ATarget::~ATarget() {

}

ATarget &ATarget::operator=(const ATarget &ref) {
	this->_type = ref._type;
	return (*this);
}

std::string const &ATarget::getType() const {
	return _type;
}

void ATarget::getHitBySpell(const ASpell &ref) const {
	std::cout << getType() << " has been " << ref.getEffects() << "!" << std::endl;
}
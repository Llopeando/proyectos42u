#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &ref) {
	this->map = ref.map;
	return (*this);
}

/* Inherited from ATARGET */
void TargetGenerator::learnTargetType(ATarget *ref) {
	if (ref)
		map[ref->getType()] = ref->clone();
}

void TargetGenerator::forgetTargetType(std::string const &targettype) {
	std::map<std::string, ATarget *>::iterator it = map.find(targettype);
	if (it != map.end()) {
		delete it->second;
		map.erase(targettype);
	}
}

ATarget * TargetGenerator::createTarget(std::string const &targettype) {
	std::map<std::string, ATarget *>::iterator it = map.find(targettype);
	if (it != map.end()) {
		return it->second->clone();
	}
	return nullptr;
}

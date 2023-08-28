#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const &type)
{
	this->type = type;
}

ATarget::~ATarget() {}

ATarget::ATarget(ATarget const &obj)
{
	*this = obj;
}

ATarget &ATarget::operator=(ATarget const &obj)
{
	this->type = obj.type;
	return (*this);
}

std::string const &ATarget::getType() const
{
	return (this->type);
}

void ATarget::getHitBySpell(ASpell const &aspell_ref) const
{
	std::cout << this->type << " has been " << aspell_ref.getEffects() << " !\n";
}

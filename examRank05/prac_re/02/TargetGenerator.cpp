#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it_begin = arr_target.begin();
	std::map<std::string, ATarget *>::iterator it_end = arr_target.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->arr_target.clear();
}

void TargetGenerator::learnTargetType(ATarget* atarget_ptr)
{
	if (atarget_ptr)
		arr_target.insert(std::pair<std::string, ATarget *>(atarget_ptr->getType(), atarget_ptr->clone()));

}

void TargetGenerator::forgetTargetType(std::string const &name)
{
	std::map<std::string, ATarget *>::iterator itr = arr_target.find(name);
	if (itr != arr_target.end())
		delete itr->second;
	arr_target.erase(name);
}

ATarget *TargetGenerator::createTarget(std::string const &name)
{
	std::map<std::string, ATarget *>::iterator itr = arr_target.find(name);
	if (itr != arr_target.end())
		return arr_target[name];
	return NULL;
}

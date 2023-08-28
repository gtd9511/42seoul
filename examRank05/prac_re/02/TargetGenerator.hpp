#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	private:
		std::map<std::string, ATarget *> arr_target;

		TargetGenerator(TargetGenerator const &obj);
		TargetGenerator &operator=(TargetGenerator const &obj);
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget* atarget_ptr);
		void forgetTargetType(std::string const &name);
		ATarget* createTarget(std::string const &name);
};

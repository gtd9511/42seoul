#include "Harl.hpp"
int Harl::min_level = -1;
std::string Harl::comments[4] = {"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!",
 "I cannot believe adding extra bacon costs more money. You didn’t put\
											 enough bacon in my burger! If you did, I wouldn’t be asking for more!",
 "I think I deserve to have some extra bacon for free. I’ve been coming for\
											years whereas you started working here since last month.",
"This is unacceptable! I want to speak to the manager now."};

std::string Harl::log_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl() {};

void Harl::setMinLogLevel(int level){this->min_level = level;}

void Harl::complain(std::string level)
{
	typedef void(Harl::*FP)();
	FP fp[4] =  {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for(int i = 0; i < 4; i++)
	{
		if(level == log_level[i])
		{
			if (min_level <= i)
			{
				std::cout << "[ " << level << " ]\n";
			   (this->*fp[i])();
				std::cout << "\n";
			}
		}
	}
}

void Harl::debug()
{
	std::cout << comments[0];
}

void Harl::info()
{
	std::cout << comments[1];
}

void Harl::warning()
{
	std::cout << comments[2];
}

void Harl::error()
{
	std::cout << comments[3];
}

void Harl::findLogLevel(std::string statement)
{
	for(int i = 0; i < 4; i++)
	{
		if (statement == comments[i])
		{
			std::cout << "[ " << log_level[i] << " ]" << std::endl;
			return ;
		}
	}
	std:: cout << "[ Probably complaining about insignificant problems ]\n";
}

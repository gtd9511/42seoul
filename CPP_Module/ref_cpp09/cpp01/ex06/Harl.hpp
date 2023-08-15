#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class	Harl{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	static int	 min_level;
	static std::string comments[4];
public:
	Harl();
	static std::string log_level[4];
	void complain(std::string level);
	void setMinLogLevel(int level);
	void findLogLevel(std::string statement);
};


#endif
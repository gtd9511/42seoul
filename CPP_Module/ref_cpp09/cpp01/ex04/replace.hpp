#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>

class	Replace
{
private:
	std::string filename;
	std::string s1;
	std::string s2;

public:
	Replace(std::string filename, std::string s1, std::string s2);
	~Replace();
	
	std::string str_replace(std::string);
	void do_replace();
};

#endif
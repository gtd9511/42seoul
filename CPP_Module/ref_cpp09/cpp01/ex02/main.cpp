#include <iostream>

void check()
{
	system("leaks Zombie");
}

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << &str << " " << strPTR << "  " << &strREF << std::endl;

	std::cout << str << " " << *strPTR << " " << strREF << std::endl;

}
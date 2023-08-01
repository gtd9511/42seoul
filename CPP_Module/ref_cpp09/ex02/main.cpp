#include "PmergeMe.hpp"

bool validateInput(std::string s) {
	char *ptr = NULL;
	double value = std::strtod(s.c_str(), &ptr);
	if (value == 0.0 && !std::isdigit(s[0]))
		return false;
	if (*ptr && std::strcmp(ptr, "f"))
		return false;
	if (value < 0)
		return false;
	return (value == static_cast<int>(value));
}

int main(int argc, char **argv) 
{
	PmergeMe P;
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	int i = 1;
	while (i < argc)
	{
		std::string stringTmp(argv[i]);
		if (validateInput(stringTmp) == false) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
		++i;
	}
	P.Pmerge(argc, argv);
	return 0;
}

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Usage: harlFilter <log_level>\n";
		return (1);
	}
	std::string level = argv[1];

	Harl harl;
	
	int min_level = -1;
	for(int i = 0; i < 4; i++)
	{
		if(harl.log_level[i] == level)
		{
			min_level = i;
			break;
		}
	}

	if (min_level != -1)
	{
		harl.setMinLogLevel(min_level);
		harl.complain("DEBUG");
		harl.complain("INFO");	
		harl.complain("WARNING");
		harl.complain("ERROR");
	}
	else
		harl.findLogLevel(level);
	
	

	
}
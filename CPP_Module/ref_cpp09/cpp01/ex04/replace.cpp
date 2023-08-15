#include "replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2)
:filename(filename), s1(s1), s2(s2){};

Replace::~Replace(){};

void Replace::do_replace()
{
	std::ifstream ifs;
	ifs.open(filename);
	std::string new_file = (std::string)filename + ".replace";
	std::ofstream ofs (new_file);
	if (ifs.fail() == true || ofs.fail() == true)
	{
		std::cout << "file open failed.\n";
		return;
	}	
	std::string str;
	while (ifs.eof() == false)
	{
		std::getline(ifs, str);
		if(ifs.eof() == true)
			break;
		ofs << str_replace(str) << "\n";
	}
	ofs.close();
	ifs.close();
}

std::string Replace::str_replace(std::string str)
{
	std::string ret;
	if(str.find(s1) == std::string::npos)
	{
		return str;
	}

	int i = 0;
	int find_pos = str.find(s1, i);
	while (find_pos != std::string::npos)
	{
		ret += str.substr(i, find_pos - i);
		ret += s2;
		i = (find_pos + s1.length());
		find_pos = str.find(s1, i);
	}
	if (find_pos == std::string::npos)
		ret += str.substr(i);
	return ret;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:07:17 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/09 21:02:03 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char *argv[])
{
	std::string		filename;
	std::string		str1;
	std::string		str2;
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		buffer;
	size_t			pos;
//filename, s1, s2
	if (argc != 4)
	{
		std::cout << "Invalid argument" << std::endl
			<< "Please enter in the following format : [FILENAME] [STRING1] [STRING2]" << std::endl;
		return (1);
	}
	str1 = argv[2];
	str2 = argv[3];
	if (str1.empty())
	{
		std::cout << "[STRING1] is empty" << std::endl;
		return (1);
	}
	if (!str1.compare(str2))
	{
		std::cout << "[STRING1] and [STRING2] must be different" << std::endl;
		return (1);
	}
	filename = argv[1];
	ifs.open(filename);
	if (!ifs.is_open())
	{
		std::cout << "Failed to open " << filename << std::endl;
		return (1);
	}
	ofs.open(std::string(filename) + ".replace");
	if (!ofs.is_open())
	{
		std::cout << "Failed to open " << filename << ".replace" << std::endl;
		return (1);
	}

	std::getline(ifs, buffer, '\0');
	pos = 0;
	while (1)
	{
		pos = buffer.find(str1, pos);
		if (pos == std::string::npos)
			break;
		buffer.erase(pos, str1.size());
		buffer.insert(pos, str2);
		pos += str2.size();
	}
	ofs << buffer;

	ifs.close();
	ofs.close();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:39 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/01 22:10:34 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <cctype>
#include <fstream>
#include <string>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	if (this == &obj)
		return ;
	*this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
		this->_data = obj._data;
	return (*this);
}

bool isNumeric(const std::string& str)
{
	bool hasDecimal = false;
	bool hasDigit = false;

	for (size_t i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (std::isdigit(c))
			hasDigit = true;
		else if (c == '.')
		{
			if (hasDecimal)
				return (false);
			hasDecimal = true;
		}
		else
			return (false);
	}
	return (hasDigit);
}

int BitcoinExchange::getData()
{
	std::ifstream csv("data.csv");
	std::string line;
	size_t date_length;

	if (!csv)
	{
		std::cerr << "Error: could not open data file." << std::endl;
		return (1);
	}
	if (getline(csv, line).eof())
	{
		std::cerr << "Error: data file is empty." << std::endl;
		return (1);
	}
	while (getline(csv, line))
	{
		if (line != "date,exchange_rate")
		{
			std::string value;
			date_length = line.find(',');
			value = line.substr(date_length + 1);
			std::cout << "value : " << value << std::endl;
			if (!isNumeric(value))
			{
				std::cerr << "Error: data file contains non-numeric value." << std::endl;
				return(1);
			}
			std::cout << "DEBUG 1 : " << value << std::endl;
			std::cout << "DEBUG 2 : " << std::strtod(value.c_str(), NULL) << std::endl;
			this->_data[line.substr(0, date_length)] = std::strtod(value.c_str(), NULL);
			// this->_data[line.substr(0, date_length)] = std::stof(line.substr(date_length + 1));
			// std::cout << line.substr(0, date_length) << std::endl;
			std::cout << "HERE : " << this->_data[line.substr(0, date_length)] << std::endl;
		}
	}
	return (0);
}

int BitcoinExchange::checkInputFile(char *file)
{
	std::fstream fs;
	std::string line;

	fs.open(file, std::ifstream::in);
	if (!fs.is_open())
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return (1);
	}
	if (getline(fs, line).eof())
	{
		std::cerr << "Error: input file is empty." << std::endl;
		return (1);
	}
	if (line.compare("date | value") != 0)
	{
		std::cerr << "Error: input file is not in the correct format." << std::endl;
		return (1);
	}
	line.erase();
	fs.close();
	return (0);
}

void BitcoinExchange::setData(char *file)
{
	std::ifstream inputfile(file);
	std::string line;

	getline(inputfile, line);
	while (getline(inputfile, line))
		// printResult(line);
		// std::cout << "Debug : " << line << std::endl;
	return ;
}

// void BitcoinExchange::printResult(std::string line)
// {
// 	std:: string date;
// 	float value;
// }

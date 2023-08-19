/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:39 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/19 16:49:26 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

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

bool BitcoinExchange::getData()
{
	std::ifstream csv("data.csv");
	std::string line;
	size_t date_length;

	if (!csv)
	{
		std::cerr << "Error: could not open data file." << std::endl;
		return (true);
	}
	if (getline(csv, line).eof())
	{
		std::cerr << "Error: data file is empty." << std::endl;
		return (true);
	}
	if (line != "date,exchange_rate")
	{
		std::cerr << "Error: data file is not in the correct format." << std::endl;
		return (true);
	}
	while (getline(csv, line))
	{
		if (line != "date,exchange_rate")
		{
			std::string value;
			date_length = line.find(',');
			value = line.substr(date_length + 1);
			if (!isNumeric(value))
			{
				std::cerr << "Error: data file contains non-numeric value." << std::endl;
				return(true);
			}
			this->_data[line.substr(0, date_length)] = std::strtod(value.c_str(), NULL);
		}
	}
	return (false);
}

bool BitcoinExchange::checkInputFile(char *file)
{
	std::fstream fs;
	std::string line;

	fs.open(file, std::ifstream::in);
	if (!fs.is_open())
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return (true);
	}
	if (getline(fs, line).eof())
	{
		std::cerr << "Error: input file is empty." << std::endl;
		return (true);
	}
	if (line.compare("date | value") != 0)
	{
		std::cerr << "Error: input file is not in the correct format." << std::endl;
		return (true);
	}
	fs.close();
	return (false);
}

void BitcoinExchange::setData(char *file)
{
	std::ifstream inputfile(file);
	std::string line;

	getline(inputfile, line);
	while (getline(inputfile, line))
		printResult(line);
	return ;
}

void BitcoinExchange::printResult(std::string line)
{
	std::string date, svalue;
	float fvalue;

	size_t date_length = line.find(" | ");
	if (date_length != 10)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}

	date = line.substr(0, date_length);
	svalue = line.substr(date_length + 3);
	if (!checkDate(date))
	{
		std::cerr << "Error: invalid date. => " << date << std::endl;
		return ;
	}
	if (!isNumeric(svalue))
	{
		std::cerr << "Error: not a positive number. => " << svalue << std::endl;
		return ;
	}
	fvalue = std::strtod(svalue.c_str(), NULL);
	if (fvalue > 1000)
	{
		std::cerr << "Error: too large a number. => " << svalue << std::endl;
		return ;
	}
	printLine(date, fvalue);
	return ;
}

bool BitcoinExchange::checkDate(const std::string& str)
{
	int year, month, day;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
		{
			if (str[i] != '-')
				return (false);
		}
		else if (!std::isdigit(str[i]))
			return (false);
	}
	year = atoi(str.substr(0, 4).c_str());
	month = atoi(str.substr(5, 2).c_str());
	day = atoi(str.substr(8, 2).c_str());
	if (year == 2009 && month == 1 && day == 1)
		return (false);
	if (year < 2009 || year > 2022)
		return (false);
	if (month > 12 || month < 1)
		return (false);
	if (day > 31 || day < 1)
		return (false);
	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		return (false);
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
	{
		if (day > 29 && month == 2)
			return (false);
	}
	else if (day > 28 && month == 2)
		return (false);
	return (true);
}

void BitcoinExchange::printLine(const std::string& date, float value)
{
	std::map<std::string, float>::iterator iter;
	float total_value;

	total_value = 0;
	iter = _data.find(date);
	if (iter != _data.end())
		total_value = (iter->second) * value;
	else
	{
		iter = _data.lower_bound(date);
		--iter;
		total_value = (iter->second) * value;
	}
	// std::cout << date << " => " << value << " = " << total_value << std::endl;
	if (static_cast<int>(total_value * 100) % 10 == 0)
		std::cout << date << " => " << value << " = " << total_value << std::endl;
	else
		std::cout << date << " => " << value << " = " << std::fixed << std:: setprecision(2) << total_value << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

bool BitcoinExchange::isNumeric(const std::string& str)
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

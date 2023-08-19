/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:37 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/02 16:50:44 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange &operator=(BitcoinExchange const &);
		bool getData();
		bool checkInputFile(char *file);
		void setData(char *file);

		bool isNumeric(const std::string& str);
		bool checkDate(const std::string& str);
		bool checkValue(float value);
		void printResult(std::string line);
		void printLine(const std::string& str, float value);
};

#endif

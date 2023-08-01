/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:37 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/01 21:31:06 by sanghan          ###   ########.fr       */
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
		int getData();
		int checkInputFile(char *file);
		void setData(char *file);
		// void printResult(std::string line);

};

#endif

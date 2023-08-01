/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:37 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/01 16:18:14 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>
# include <exception>

class BitcoinExchange
{
	private:
		std::string _name;
		std::vector<std::string> _currencies;
		std::list<double> _prices;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string name);
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &assign);
		void addCurrency(std::string currency);
		void addPrice(double price);
		void printCurrencies();
		void printPrices();
		void print();
		std::string getName();
		std::vector<std::string> getCurrencies();
		std::list<double> getPrices();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:39 by sanghan           #+#    #+#             */
/*   Updated: 2023/04/14 13:07:10 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/BitcoinExchange.hpp"

/*
BitcoinExchange::BitcoinExchange(void)
{
	this->name = "BitcoinExchange";
	this->balance = 0;
	this->bitcoin = 0;
}

BitcoinExchange::BitcoinExchange(std::string name)
{
	this->name = name;
	this->balance = 0;
	this->bitcoin = 0;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &assign)
{
	this->name = assign.name;
	this->balance = assign.balance;
	this->bitcoin = assign.bitcoin;
	return *this;
}

void BitcoinExchange::addCurrency(std::string currency)
{
	this->currencies.push_back(currency);
}

void BitcoinExchange::addPrice(double price)
{
	this->prices.push_back(price);
}

void BitcoinExchange::printCurrencies()
{
	std::cout << "Currencies: ";
	for (std::vector<std::string>::iterator it = this->currencies.begin(); it != this->currencies.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void BitcoinExchange::printPrices()
{
	std::cout << "Prices: ";
	for (std::list<double>::iterator it = this->prices.begin(); it != this->prices.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void BitcoinExchange::print()
{
	std::cout << "Name: " << this->name << std::endl;
	this->printCurrencies();
	this->printPrices();
	std::cout << "Balance: " << this->balance << std::endl;
	std::cout << "Bitcoin: " << this->bitcoin << std::endl;
}

std::string BitcoinExchange::getName()
{
	return this->name;
}

std::vector<std::string> BitcoinExchange::getCurrencies()
{
	return this->currencies;
}

std::list<double> BitcoinExchange::getPrices()
{
	return this->prices;
}

void BitcoinExchange::buy(std::string currency, double amount)
{
	std::vector<std::string>::iterator it = std::find(this->currencies.begin(), this->currencies.end(), currency);
	if (it == this->currencies.end())
		throw std::exception();
	std::list<double>::iterator it2 = this->prices.begin();
	std::advance(it2, std::distance(this->currencies.begin(), it));
	this->balance -= amount;
	this->bitcoin += amount / *it2;
}

void BitcoinExchange::sell(std::string currency, double amount)
{
	std::vector<std::string>::iterator it = std::find(this->currencies.begin(), this->currencies.end(), currency);
	if (it == this->currencies.end())
		throw std::exception();
	std::list<double>::iterator it2 = this->prices.begin();
	std::advance(it2, std::distance(this->currencies.begin(), it));
	this->balance += amount * *it2;
	this->bitcoin -= amount;
}

void BitcoinExchange::printBalance()
{
	std::cout << "Balance: " << this->balance << std::endl;
}

void BitcoinExchange::printBitcoin()
{
	std::cout << "Bitcoin: " << this->bitcoin << std::endl;
}

*/

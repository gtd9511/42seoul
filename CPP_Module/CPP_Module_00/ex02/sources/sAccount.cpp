/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sAccount.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:17:35 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/07 18:58:51 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account( int initial_deposit )
{
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_nbAccounts++;
	this->_totalAmount += this->_amount;

	Account::_displayTimestamp();

	std::cout << " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created"
		<< std::endl;
}

Account::~Account( void )
{
	this->_totalAmount -= this->_amount;
	this->_totalNbDeposits -= this->_nbDeposits;
	this->_totalNbWithdrawals -= this->_nbWithdrawals;

	Account::_displayTimestamp();

	std::cout << " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();

	std::cout << " accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals()
		<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t		rawtime;
	struct tm	*t;

	rawtime = time(NULL);
	t = localtime(&rawtime);
	std::cout << "["
		<< t->tm_year + 1900 << std::setw(2) << std::setfill('0')
		<< t->tm_mon + 1 << std::setw(2)
		<< t->tm_mday << "_" << std::setw(2)
		<< t->tm_hour << std::setw(2)
		<< t->tm_min << std::setw(2)
		<< t->tm_sec << "]";
}

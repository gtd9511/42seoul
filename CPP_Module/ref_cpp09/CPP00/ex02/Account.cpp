#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts + 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts ++;
	_totalAmount += initial_deposit;
}

Account::Account(void)
{

}

Account::~Account(void)
{

}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
	return _totalAmount;
}
int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	std::cout << "******************************Account Info******************************\n";
	std::cout << "number of accounts: " << getNbAccounts() << std::endl;
	std::cout << "total amount:  " << getTotalAmount() << std::endl;
	std::cout << "number of deposits: " << getNbDeposits() << std::endl;
	std::cout << "number of withdrawals: " << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	(this->_nbDeposits++);
	_totalNbDeposits++;
	_totalAmount+= deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount - withdrawal >= 0)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		_totalAmount-= withdrawal;

		return true;
 	}
	else
	{
		return false;
	}
}

int Account::checkAmount(void)const
{
	return Account::_totalAmount;
}

void Account::displayStatus(void) const
{

	std::string prints[4] = {"Account" , "Amount ", "nb_Deposits", "nb_Withdrawals"};
	std::cout <<"******************************Account status******************************\n";
	std::cout.width(10); 
	std::cout << prints[0] << "|";
	std::cout.width(10); 
	std::cout << prints[1] << "|";
	std::cout.width(10); 
	std::cout << prints[2] << "|";
	std::cout.width(10); 
	std::cout << prints[3] << "\n";
	std::cout.width(11); 
	std::cout << this->_accountIndex;
	std::cout.width(11);		
	std::cout << this->_amount;
	std::cout.width(11);		
	std::cout << this->_nbDeposits;
	std::cout.width(11);		
	std::cout << this->_nbWithdrawals;
	std::cout << std::endl;
}
	 #include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts + 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts ++;
	_totalAmount += initial_deposit;
}

Account::Account(void)
{

}

Account::~Account(void)
{

}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
	return _totalAmount;
}
int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	std::cout << "******************************Account Info******************************\n";
	std::cout << "number of accounts: " << getNbAccounts() << std::endl;
	std::cout << "total amount:  " << getTotalAmount() << std::endl;
	std::cout << "number of deposits: " << getNbDeposits() << std::endl;
	std::cout << "number of withdrawals: " << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	(this->_nbDeposits++);
	_totalNbDeposits++;
	_totalAmount+= deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount - withdrawal >= 0)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		_totalAmount-= withdrawal;

		return true;
 	}
	else
	{
		return false;
	}
}

int Account::checkAmount(void)const
{
	return Account::_totalAmount;
}

void Account::displayStatus(void) const
{

	std::string prints[4] = {"Account" , "Amount ", "nb_Deposits", "nb_Withdrawals"};
	std::cout <<"******************************Account status******************************\n";
	std::cout.width(10); 
	std::cout << prints[0] << "|";
	std::cout.width(10); 
	std::cout << prints[1] << "|";
	std::cout.width(10); 
	std::cout << prints[2] << "|";
	std::cout.width(10); 
	std::cout << prints[3] << "\n";
	std::cout.width(11); 
	std::cout << this->_accountIndex;
	std::cout.width(11);		
	std::cout << this->_amount;
	std::cout.width(11);		
	std::cout << this->_nbDeposits;
	std::cout.width(11);		
	std::cout << this->_nbWithdrawals;
	std::cout << std::endl;
}
	 

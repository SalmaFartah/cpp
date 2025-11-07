#include "Account.hpp"
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
	std::tm *fullDate = std::localtime(&now);
	
	char myTime[19];
	std::strftime(myTime, sizeof(myTime), "[%Y%m%d_%H%M%S] ", fullDate);
	std::cout << myTime;
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
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
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" \
	<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() 
	<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int old_amount = _amount;
	//add the deposit value to the amount and total amount
	_amount += deposit;
	_totalAmount += deposit;

	//increment deposits number for each account and increment total deposits number by 1
	_nbDeposits++;
	_totalNbDeposits++;

	// display deposit info
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << old_amount << ";deposit:" 
	<< deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:";
	if (_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

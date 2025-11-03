#include "Account.hpp"

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_totalAmount += _amount;
}
#include "Account.hpp"
#include <iostream>
#include <time.h>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ){
	_nbAccounts++;
	this->_accountIndex = (_nbAccounts - 1);
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
	return ;
}

Account::~Account( void ){
	_nbAccounts--;
	_totalAmount -= this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	return ;
}

void Account::makeDeposit( int deposit ){
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount \
	<< ";deposit:" << deposit << ";amount" << (this->_amount + deposit) << ";nb_deposits:" << this->_nbDeposits <<std::endl;
	this->_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal ){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal <= this->_amount )
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << withdrawal << ";nb_withdrawals: " << this->_nbWithdrawals << std::endl;
		return (1);
	}
	else
		std::cout << "refused!" << std::endl; 
		return (0);
}

int Account::checkAmount( void ) const{
	return this->_nbDeposits;
}

void Account::_displayTimestamp( void ){
	time_t rawtime;
	struct tm *timeinfo;
	time (&rawtime);
	timeinfo = localtime ( &rawtime );
	std::cout << "[" << timeinfo->tm_year << timeinfo->tm_mon << timeinfo->tm_mday \
	<< "_" << timeinfo->tm_hour << timeinfo->tm_min << timeinfo->tm_sec << "] ";
}

int	Account::getNbAccounts( void ){
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ){
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ){
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << \
	";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;  
}

void	Account::displayStatus( void ) const{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount\
	<< ";deposits" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
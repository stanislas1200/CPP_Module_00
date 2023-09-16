#include "../include/Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
	std::cout << "[19920104_091532] ";
}

// Constructor
Account::Account(int initial_deposit) {
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << " " << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";" << "created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
}

// Destructor
Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << " " << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";" << "closed" << std::endl;
}

// Get Data Functions
int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << " " << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

// Member Functions
void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << " " << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

// bool Account::makeWithdrawal(int withdrawal) {
// }

// int Account::checkAmount(void) const {
// }
void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << " " << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

// // Private Functions
// void Account::_displayTimestamp(void) {
// }
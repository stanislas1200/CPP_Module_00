/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgodin <sgodin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:55:13 by sgodin            #+#    #+#             */
/*   Updated: 2023/09/23 16:55:13 by sgodin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Account.hpp"
#include <iostream>
#include <ctime>
#include <fstream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
	std::time_t time = std::time(nullptr);
	char buf[16];
	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", std::localtime(&time));
	std::cout << "[" << buf << "] ";
}

Account::Account(int initial_deposit) {
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";" << "created" << std::endl;
	t::_nbAccounts++;
	t::_totalAmount += this->_amount;
}

Account::~Account(void) {
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";" << "closed" << std::endl;
}

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

int Account::checkAmount(void) const {
	return this->_amount;
}

void Account::makeDeposit(int deposit) {
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	t::_totalAmount += deposit;
	t::_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal > this->_amount) 
		return (std::cout << "refused" << std::endl, false);
	std::cout << withdrawal << ";";
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	t::_totalAmount -= withdrawal;
	t::_totalNbWithdrawals++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

void Account::displayAccountsInfos(void) {
	t::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << t::getTotalAmount() << ";";
	std::cout << "deposits:" << t::getNbDeposits() << ";";
	std::cout << "withdrawals:" << t::getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

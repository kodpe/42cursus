/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:28:07 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/23 13:32:07by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

#define COLOR	0
#define RED		if(COLOR){std::cout <<"\033[31m";}
#define GREEN	if(COLOR){std::cout <<"\033[32m";}
#define YELLOW	if(COLOR){std::cout <<"\033[33m";}
#define BLUE	if(COLOR){std::cout <<"\033[34m";}
#define PURPLE	if(COLOR){std::cout <<"\033[35m";}
#define CYAN	if(COLOR){std::cout <<"\033[36m";}
#define RESET	if(COLOR){std::cout <<"\033[0m";}

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	time_t		timer;
	char		buff[18];

	time(&timer);
	strftime(buff, 18, "[%Y%m%d_%H%M%S]", localtime(&timer));
	std::cout << buff;
}

void	Account::displayStatus(void) const
{
	BLUE
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos(void)
{
	CYAN
    _displayTimestamp();
    std::cout   << " accounts:" << getNbAccounts()
                << ";total:" << getTotalAmount()
                << ";deposits:" << getNbDeposits()
                << ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;

	_amount = initial_deposit;
	_totalAmount += initial_deposit;

	GREEN
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

Account::~Account(void)
{
	RED
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
	RESET
}

void	Account::makeDeposit(int deposit)
{
	PURPLE
	_displayTimestamp();
	std::cout 	<< " index:" << _accountIndex
				<< ";p_amount:" << _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout 	<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	YELLOW
	_displayTimestamp();
	std::cout 	<< " index:" << _accountIndex
				<< ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout 	<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

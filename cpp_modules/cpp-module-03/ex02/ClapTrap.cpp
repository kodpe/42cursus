/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:34:19 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/03 22:03:19 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	_name("default"),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
{
	std::cout	<< "Claptrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
	_name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
{
	std::cout	<< "Claptrap constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout	<< "Claptrap copy constructor" << std::endl;
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout	<< "Claptrap assignation" << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout	<< "Claptrap destructor" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout	<< "Claptrap ";
	if (_hit_points == 0)
	{
		std::cout 	<< _name << " can't attack, is dead!" << std::endl;
		return ;
	}
	if (_energy_points == 0)
	{
		std::cout 	<< _name << " can't attack, 0 energy" << std::endl;
		return ;
	}
	--_energy_points;
	std::cout 	<< _name << " attacks " << target << ", causing "
				<< _attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout	<< "Claptrap ";
	if (_hit_points == 0)
	{
		std::cout 	<< _name << " is already dead!" << std::endl;
		return ;
	}

	unsigned int	real_amount = amount;

	if (real_amount > _hit_points)
		real_amount = _hit_points;

	_hit_points -= real_amount;
	std::cout 	<< _name << " takes " << real_amount
				<< "/" << amount << " points of damage ";
	if (_hit_points == 0)
		std::cout 	<< "and dies!" << std::endl;
	else
		std::cout 	<< "and stays alive with " << _hit_points << " hit points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout	<< "Claptrap ";
	if (_hit_points == 0)
	{
		std::cout 	<< _name << " can't be repair, is dead!" << std::endl;
		return ;
	}
	if (_energy_points == 0)
	{
		std::cout 	<< _name << " can't be repair, 0 energy" << std::endl;
		return ;
	}
	--_energy_points;
	this->_hit_points += amount;
	std::cout	<< _name << " repaired with " << amount << " hit points!"
				<< std::endl;
}


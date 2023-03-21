/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:25:09 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/03 22:19:32 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout	<< "Scavtrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout	<< "Scavtrap constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap()
{
	std::cout	<< "Scavtrap copy constructor" << std::endl;
	*this = other;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout	<< "Scavtrap assignation operator" << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout	<< "Scavtrap destructor" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap ";
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

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap ";
	if (_hit_points == 0)
	{
		std::cout 	<< _name << " can't activate Gate keeper mode, is dead!" << std::endl;
		return ;
	}
	std::cout	<< _name << " has entered Gate keeper mode." << std::endl;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:25:09 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/03 22:19:58 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout	<< "Fragtrap default constructor" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout	<< "Fragtrap constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap()
{
	std::cout	<< "Fragtrap copy constructor" << std::endl;
	*this = other;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout	<< "Fragtrap assignation operator" << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout	<< "Fragtrap destructor" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap ";
	if (_hit_points == 0)
	{
		std::cout 	<< _name << " can't request a high fives , is dead!" << std::endl;
		return ;
	}
	std::cout	<< _name << " requires a high fives." << std::endl;
}

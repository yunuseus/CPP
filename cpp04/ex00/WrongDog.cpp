/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:20:55 by yalp              #+#    #+#             */
/*   Updated: 2025/09/18 15:21:11 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog()
{
	this->type = "WrongDog";
	std::cout << "WrongDog constructor called" << std::endl;
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog destructor called" << std::endl;
}

WrongDog::WrongDog(WrongDog& other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog& WrongDog::operator=(WrongDog& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << "WrongDog assignment operator called" << std::endl;
	return *this;
}

void WrongDog::makeSound() const
{
	std::cout << "WrongWoof" << std::endl;
}
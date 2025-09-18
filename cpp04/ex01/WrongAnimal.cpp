/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:21:33 by yalp              #+#    #+#             */
/*   Updated: 2025/09/18 15:54:09 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal& other) : type(other.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(WrongAnimal& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	return *this;
}
const std::string WrongAnimal::getType() const
{
	return type;
}
void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:04:33 by yalp              #+#    #+#             */
/*   Updated: 2025/09/18 15:04:33 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
Animal::Animal() : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
Animal::Animal(Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal& Animal::operator=(Animal& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Animal assignment operator called" << std::endl;
	return *this;
}
const std::string Animal::getType() const
{
	return type;
}
void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
void Animal::setType(std::string type)
{
	this->type = type;
}
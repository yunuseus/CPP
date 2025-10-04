/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:04:47 by yalp              #+#    #+#             */
/*   Updated: 2025/10/04 14:47:07 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}


Dog::Dog(const Dog& other) : Animal(other)
{
	this->brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}


Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
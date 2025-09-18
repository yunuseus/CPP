/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:19:13 by yalp              #+#    #+#             */
/*   Updated: 2025/09/18 15:42:01 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat& other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << "WrongCat assignment operator called" << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongMeow" << std::endl;
}
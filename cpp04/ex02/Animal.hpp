/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:04:39 by yalp              #+#    #+#             */
/*   Updated: 2025/09/24 15:23:58 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>
class Animal
{
	protected:
	std::string type;
	public:
	Animal();
	virtual ~Animal();
	Animal(Animal& other);
	Animal& operator=(Animal& other);
	const std::string getType() const;
	virtual void makeSound() const = 0;
};
#endif
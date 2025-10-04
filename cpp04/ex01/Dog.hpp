/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:04:50 by yalp              #+#    #+#             */
/*   Updated: 2025/10/04 14:47:07 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
	private:
		Brain* brain;
	public:
	Dog();
	~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	void makeSound() const;
};
#endif
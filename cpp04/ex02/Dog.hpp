/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:04:50 by yalp              #+#    #+#             */
/*   Updated: 2025/09/19 16:25:19 by yalp             ###   ########.fr       */
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
	Dog(Dog& other);
	Dog& operator=(Dog& other);
	void makeSound() const;
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:08:06 by yalp              #+#    #+#             */
/*   Updated: 2025/09/18 15:52:54 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>
#include <iostream>
class WrongAnimal
{
	protected:
	std::string type;
	public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(WrongAnimal& other);
	WrongAnimal& operator=(WrongAnimal& other);
	void makeSound() const;
	const std::string getType() const;
};

#endif

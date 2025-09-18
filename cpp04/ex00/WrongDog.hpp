/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:08:23 by yalp              #+#    #+#             */
/*   Updated: 2025/09/18 15:17:40 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP
#include "WrongAnimal.hpp"
class WrongDog : public WrongAnimal
{
	protected:
	std::string type;
	public:
	WrongDog();
	~WrongDog();
	WrongDog(WrongDog& other);
	WrongDog& operator=(WrongDog& other);
	void makeSound() const;
	void setType(std::string type);
	std::string getType();
};

#endif

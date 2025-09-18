/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:08:14 by yalp              #+#    #+#             */
/*   Updated: 2025/09/18 15:17:20 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal
{
	protected:
	std::string type;
	public:
	WrongCat();
	~WrongCat();
	WrongCat(WrongCat& other);
	WrongCat& operator=(WrongCat& other);
	void makeSound() const;
	void setType(std::string type);
	std::string getType();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:08:14 by yalp              #+#    #+#             */
/*   Updated: 2025/09/18 15:53:43 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal
{
	public:
	WrongCat();
	~WrongCat();
	WrongCat(WrongCat& other);
	WrongCat& operator=(WrongCat& other);
	void makeSound() const;
};

#endif
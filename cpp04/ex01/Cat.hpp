/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:04:44 by yalp              #+#    #+#             */
/*   Updated: 2025/09/19 16:25:19 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
	private:
		Brain* brain;
	public:
	Cat();
	virtual ~Cat();
	Cat(Cat& other);
	Cat& operator=(Cat& other);
	void makeSound() const;
};
#endif
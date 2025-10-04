/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:04:52 by yalp              #+#    #+#             */
/*   Updated: 2025/10/04 15:08:13 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
const Animal* animals[100];
for (int i = 0; i < 100; i++)
{
    if (i >= 50)
        animals[i] = new Dog();
    else
        animals[i] = new Cat();
}
for (int i = 0; i < 100; i++)
{
    delete animals[i];
}

Dog basic;
{
Dog tmp = basic;
}

return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:04:52 by yalp              #+#    #+#             */
/*   Updated: 2025/09/18 15:40:12 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* WrongMeta = new WrongAnimal();
const WrongAnimal* wrongcat = new WrongCat();
const WrongAnimal* wrongdog = new WrongDog();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();
std::cout << wrongdog->getType() << " " << std::endl;
std::cout << wrongcat->getType() << " " << std::endl;
wrongcat->makeSound();
wrongdog->makeSound();
WrongMeta->makeSound();
delete meta;
delete i;
delete j;
delete WrongMeta;
delete wrongcat;
delete wrongdog;
return 0;
}

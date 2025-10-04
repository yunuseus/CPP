/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:04:52 by yalp              #+#    #+#             */
/*   Updated: 2025/10/04 15:58:57 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
	std::cout << "--- Polymorphic Array Test ---" << std::endl;
	const int size = 4;
	Animal* animals[size];
	for (int i = 0; i < size; ++i) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < size; ++i) {
		animals[i]->makeSound();
	}
	for (int i = 0; i < size; ++i) {
		delete animals[i];
	}

	std::cout << "\n--- Deep Copy Test (Dog) ---" << std::endl;
	Dog dog1;
	dog1.makeSound();
	Dog dog2 = dog1;
	dog2.makeSound();

	std::cout << "\n--- Deep Copy Test (Cat) ---" << std::endl;
	Cat cat1;
	cat1.makeSound();
	Cat cat2;
	cat2 = cat1;
	cat2.makeSound();

	std::cout << "\n--- WrongAnimal Polymorphism Test ---" << std::endl;
	WrongAnimal* wcat = new WrongCat();
	WrongAnimal* wdog = new WrongDog();
	wcat->makeSound();
	wdog->makeSound();
	delete wcat;
	delete wdog;

	return 0;
}

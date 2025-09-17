#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : Animal
{
	public:
	Dog();
	~Dog();
	Dog(Dog& other);
	Dog& operator=(Dog& other);
};
#endif
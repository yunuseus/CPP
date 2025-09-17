#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>
class Animal
{
	protected:
	std::string type;
	public:
	Animal();
	~Animal();
	Animal(Animal& other);
	Animal& operator=(Animal& other);
	std::string getType();
	void makeSound();
	void setType(std::string type);
};

#endif
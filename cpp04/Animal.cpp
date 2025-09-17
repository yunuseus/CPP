#include "Animal.hpp"
Animal::Animal() : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
Animal::Animal(Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal& Animal::operator=(Animal& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Animal assignment operator called" << std::endl;
	return *this;
}
std::string Animal::getType()
{
	return type;
}
void Animal::makeSound()
{
	std::cout << "Animal sound" << std::endl;
}
void Animal::setType(std::string type)
{
	this->type = type;
}
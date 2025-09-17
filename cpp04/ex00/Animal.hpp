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
	const std::string getType() const;
	virtual void makeSound() const;
	void setType(std::string type);
};

#endif
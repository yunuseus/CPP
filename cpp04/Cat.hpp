#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : Animal
{
	public:
	Cat();
	~Cat();
	Cat(Cat& other);
	Cat& operator=(Cat& other);
};
#endif
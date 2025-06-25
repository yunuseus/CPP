#include "phonebook.hpp"
#include <iostream>

int main()
{
	PhoneBook book;
	Contact contacs;
	contacs.setter("yunus", 0);
	std:: string select;
	std:: cout << contacs.getter(0);
	while (1)
	{
	
		std:: cout << ""<< std::endl;
		std:: cin >> select;
		std:: cout << "girdiğiniz select" << select << std:: endl;
	}
}
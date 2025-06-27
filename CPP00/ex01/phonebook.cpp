#include "phonebook.hpp"
#include <iostream>
#include <stdlib.h>



void create_contact()
{
	Contact cont;
	std:: string str;
	std:: cout << "FIRST NAME:";
	std::getline(std:: cin, str);
	if(str.empty())
		exit(1);
	cont.setter(str, 0);
	std:: cout << "LAST NAME:";
	std:: cin >> str;
	std:: cout << std:: endl;
	if(str.empty())
		exit(1);
	cont.setter(str, 1);
	std:: cout << "NICK NAME:";
	std:: cin >> str;
	std:: cout << std:: endl;

	if(str.empty())
		exit(1);
	cont.setter(str, 2);
	std:: cout << "PHONE NUMBER:";
	std:: cin >> str;
	std:: cout << std:: endl;
	if(str.empty())
		exit(1);
	cont.setter(str, 3);
		std:: cout << "DARKEST SECRET:";
	std:: cin >> str;
	std:: cout << std:: endl;
	if(str.empty())
		exit(1);
	cont.setter(str, 4);
	
}

void selection(std:: string select)
{
	if (select =="ADD")
	{
		create_contact();
	}
	if (select=="SEARCH")
	{
		std:: cout << "search yapılıyor" << std:: endl;
	}
	if (select=="EXIT")
	{
		exit(0);
	}
}

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
		std:: getline(std:: cin, select);
		if (!(select=="ADD"||select=="SEARCH"|| select=="EXIT"))
			std:: cout << "PLEASE TYPE A VALID SELECT" << std:: endl;
		selection(select);
	}
}
#include "phonebook.hpp"
#include <iostream>
#include <stdlib.h>

void print_contacts(PhoneBook book)
{
	Contact tmp;
	for (int i = 0; i < 8; i++)
	{
		tmp = book.get_contact(i);
		if (!tmp.getter(0).empty())
		{
			std:: cout << tmp.getter(0) << std:: endl;
		}
		else
			break;
	}
}

void add_contact_book(Contact cont, PhoneBook& book)
{
	Contact tmp;
	for(int i = 0; i <= 8; i++)
	{
		tmp = book.get_contact(i);
		if (tmp.getter(0).empty())
		{
			book.add_contact(cont, i);
			break;
		}
		
		if (i == 8)
		{
			if (book.get_oldest_i() == 8)
				book.set_oldest_i(0);
			book.add_contact(cont, book.get_oldest_i());
			book.set_oldest_i(book.get_oldest_i() + 1);
		}
	}
}

void create_contact(PhoneBook& book)
{
	Contact cont;
	std:: string str;
	std:: cout << "FIRST NAME:";
	std::getline(std:: cin, str);
	if(str.empty())
		std::cin.ignore();
	cont.setter(str, 0);
	std:: cout << "LAST NAME:";
	std::getline(std:: cin, str);
	if(str.empty())
		std::cin.ignore();
	cont.setter(str, 1);
	std:: cout << "NICK NAME:";
	std::getline(std:: cin, str);
	if(str.empty())
		std::cin.ignore();
	cont.setter(str, 2);
	std:: cout << "PHONE NUMBER:";
	std::getline(std:: cin, str);
	if(str.empty())
		std::cin.ignore();
	cont.setter(str, 3);
	std:: cout << "DARKEST SECRET:";
	std::getline(std:: cin, str);
	if(str.empty())
		std::cin.ignore();
	cont.setter(str, 4);
	
	add_contact_book(cont, book);
}

void selection(std:: string select, PhoneBook& book)
{
	if (select =="ADD")
	{
		create_contact(book);
	}
	if (select=="SEARCH")
	{
		print_contacts(book);
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
	book.set_oldest_i(0);
	contacs.setter("yunus", 0);
	std:: string select;
	std:: cout << contacs.getter(0);
	while (1)
	{
		
		std:: cout << ""<< std::endl;
		std:: getline(std:: cin, select);
		if (!(select=="ADD"||select=="SEARCH"|| select=="EXIT"))
			std:: cout << "PLEASE TYPE A VALID SELECT" << std:: endl;
		selection(select, book);
	}
}
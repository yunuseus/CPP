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

void add_contact_book(Contact cont, PhoneBook& book, int *real_i)
{
	Contact tmp;
	
	// Eğer telefon defteri doluysa, en eski kaydın üzerine yaz
	if (*real_i >= 8)
	{
		book.add_contact(cont, *real_i % 8);
		(*real_i)++;
		return;
	}
	
	// Boş yer ara (sadece 0-7 arası indeksler geçerli)
	for(int i = 0; i < 8; i++)
	{
		tmp = book.get_contact(i);
		if (tmp.getter(0).empty())
		{
			book.add_contact(cont, i);
			(*real_i)++;
			break;
		}
	}
}

void create_contact(PhoneBook& book, int *real_i)
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
	
	add_contact_book(cont, book, real_i);
}

void selection(std:: string select, PhoneBook& book, int *real_i)
{
	if (select =="ADD")
	{
		create_contact(book, real_i);
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
	int real_i = 0;
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
		selection(select, book, &real_i);
	}
}
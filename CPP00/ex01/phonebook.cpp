#include "phonebook.hpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>


void print_format(std:: string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0,9) << ".";
	else
		std:: cout << std::setw(10) << std:: left << str;
}

void print_contacts(PhoneBook book)
{
	Contact tmp;
	std:: cout << "---------------------------------------------" << std:: endl;
	std:: cout << "|index     |First Name|Last Name |Nick Name |" << std:: endl;
	std:: cout << "---------------------------------------------" << std:: endl;
	for (int i = 0; i < 8; i++)
	{
		tmp = book.get_contact(i);
		if (!tmp.getter(0).empty())
		{
	
			std:: cout << "|";
			std:: cout << std::setw(10) << std:: left << i;
			std:: cout << "|";
			print_format(tmp.getter(0));
			std:: cout << "|";
			print_format(tmp.getter(1));
			std:: cout << "|";
			print_format(tmp.getter(2));
			std:: cout << "|" << std:: endl;
			std:: cout << "---------------------------------------------" << std:: endl;
		}
		else
			break;
	}
}

void add_contact_book(Contact cont, PhoneBook& book, int *real_i)
{
	Contact tmp;
	
	if (*real_i >= 8)
	{
		book.add_contact(cont, *real_i % 8);
		(*real_i)++;
		return;
	}
	
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
	if (cont.getter(0).empty() || cont.getter(1).empty() || cont.getter(2).empty() || cont.getter(3).empty() || cont.getter(4).empty())
	{
		std:: cerr << "empty attributes";
		return ;
	}
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
			std:: cerr << "PLEASE TYPE A VALID SELECT" << std:: endl;
		selection(select, book, &real_i);
	}
}
#include "phonebook.hpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <sstream>


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
	
	int contact_count = 0;
	for (int i = 0; i < 8; i++)
	{
		tmp = book.get_contact(i);
		if (!tmp.getter(0).empty())
		{
			contact_count++;
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
	
	if (contact_count == 0)
	{
		std:: cout << "No contacts found!" << std:: endl;
		return;
	}
	
	while (true)
	{
		std:: cout << "Enter the index of the contact to display: ";
		std:: string input;
		if (!std::getline(std:: cin, input))
		{
			std:: cout << "\nInput cancelled." << std:: endl;
			return;
		}
		
		std::stringstream ss(input);
		int index;
		if (!(ss >> index) || !ss.eof() || index < 0 || index >= 8)
		{
			std:: cout << "Invalid index! Please try again." << std:: endl;
			continue; 
		}
		
		Contact selected = book.get_contact(index);
		if (selected.getter(0).empty())
		{
			std:: cout << "No contact at index " << index << "! Please try again." << std:: endl;
			continue; 
		}
		
		std:: cout << "First Name: " << selected.getter(0) << std:: endl;
		std:: cout << "Last Name: " << selected.getter(1) << std:: endl;
		std:: cout << "Nick Name: " << selected.getter(2) << std:: endl;
		std:: cout << "Phone Number: " << selected.getter(3) << std:: endl;
		std:: cout << "Darkest Secret: " << selected.getter(4) << std:: endl;
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
	if (!std::getline(std:: cin, str))
		return;
	if(str.empty())
		std::cin.ignore();
	cont.setter(str, 0);
	std:: cout << "LAST NAME:";
	if (!std::getline(std:: cin, str))
		return;
	if(str.empty())
		std::cin.ignore();
	cont.setter(str, 1);
	std:: cout << "NICK NAME:";
	if (!std::getline(std:: cin, str))
		return;
	if(str.empty())
		std::cin.ignore();
	cont.setter(str, 2);
	std:: cout << "PHONE NUMBER:";
	if (!std::getline(std:: cin, str))
		return;
	if(str.empty())
		std::cin.ignore();
	cont.setter(str, 3);
	std:: cout << "DARKEST SECRET:";
	if (!std::getline(std:: cin, str))
		return;
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
		if (!std::getline(std:: cin, select))
		{
			std:: cout << "\nExiting..." << std:: endl;
			break;
		}
		if (!(select=="ADD"||select=="SEARCH"|| select=="EXIT"))
			std:: cerr << "PLEASE TYPE A VALID SELECT" << std:: endl;
		if (select=="EXIT")
		{
			return(0);
		}
		selection(select, book, &real_i);
	}
	return 0;
}
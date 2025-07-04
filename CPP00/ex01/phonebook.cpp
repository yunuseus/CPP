#include "phonebook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>


void print_format(std:: string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0,9) << ".";
	else
		std:: cout << std::setw(10) << std:: left << str;
}

void index_selection(PhoneBook& book)
{
    std::string index;
    int num;
    std::cout << "Enter index (0-7): ";
    
    while (1)
		{
			if (!std::getline(std::cin, index))
			{
				std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
				break;
			}
		
        std::stringstream ss(index);
        if (ss >> num && ss.eof())
        {
            if (num >= 0 && num <= 7)
            {
                Contact tmp = book.get_contact(num);
                if (!tmp.getter(0).empty())
                {
                    std::cout << "First Name: " << tmp.getter(0) << std::endl;
                    std::cout << "Last Name: " << tmp.getter(1) << std::endl;
                    std::cout << "Nick Name: " << tmp.getter(2) << std::endl;
                    std::cout << "Phone Number: " << tmp.getter(3) << std::endl;
                    std::cout << "Darkest Secret: " << tmp.getter(4) << std::endl;
                    break;
                }
                else
                {
                    std::cout << "No contact at this index." << std::endl;
                    break;
                }
            }
            else
            {
                std::cout << "Invalid index. Please enter 0-7: ";
            }
        }
        else
        {
            std::cout << "Invalid input. Please enter a number: ";
        }
    }
}

void print_contacts(PhoneBook& book)
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
	index_selection(book);
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
	std:: cout << "FIRST NAME: ";
	std::getline(std:: cin, str);
	if (str.empty())
	{
		std::cout << "Empty field not allowed!" << std::endl;
		return;
	}
	cont.setter(str, 0);
	
	std::cout << "LAST NAME: ";
	std::getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "Empty field not allowed!" << std::endl;
		return;
	}
	cont.setter(str, 1);
	
	std::cout << "NICK NAME: ";
	std::getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "Empty field not allowed!" << std::endl;
		return;
	}
	cont.setter(str, 2);
	
	std::cout << "PHONE NUMBER: ";
	std::getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "Empty field not allowed!" << std::endl;
		return;
	}
	cont.setter(str, 3);
	
	std::cout << "DARKEST SECRET: ";
	std::getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "Empty field not allowed!" << std::endl;
		return;
	}
	cont.setter(str, 4);
	
	add_contact_book(cont, book, real_i);
	std::cout << "Contact added successfully!" << std::endl;
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
    std::string select;
    int real_i = 0;
    
    while (1)
    {
        std::cout << "Enter command (ADD/SEARCH/EXIT): ";
        
        if (!std::getline(std::cin, select))
        {
            std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
            break;
        }
        
        if (select.empty())
        {
            continue; 
        }
        
        if (select == "ADD" || select == "SEARCH" || select == "EXIT")
        {
			if (select=="EXIT")
			{
				return (0);
			}
            selection(select, book, &real_i);
        }
        else
        {
            std::cerr << "PLEASE TYPE A VALID COMMAND (ADD/SEARCH/EXIT)" << std::endl;
        }
    }
    
    return 0;
}
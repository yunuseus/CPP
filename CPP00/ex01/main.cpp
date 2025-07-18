#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>
#include <cctype>  

int is_only_digits(const std::string str)
{
    if (str.empty())
        return 0;  
    
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (!(std::isdigit(str[i])))
            return 0; 
    }
    return 1;
}

void print_format(std::string str)
{
    if (str.length() > 10)
        std::cout << str.substr(0,9) << ".";
    else
        std::cout << std::setw(10) << std::right << str;
}

void print_contacts(PhoneBook book)
{
    Contact tmp;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     index|First Name| Last Name| Nick Name|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    
    int contact_count = 0;
    for (int i = 0; i < 8; i++)
    {
        tmp = book.get_contact(i);
        if (!tmp.getter(0).empty())
        {
            contact_count++;
            std::cout << "|";
            std::cout << std::setw(10) << std::right << i;
            std::cout << "|";
            print_format(tmp.getter(0));
            std::cout << "|";
            print_format(tmp.getter(1));
            std::cout << "|";
            print_format(tmp.getter(2));
            std::cout << "|" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
        }
        else
            break;
    }
    
    if (contact_count == 0)
    {
        std::cout << "No contacts found!" << std::endl;
        return;
    }
    
    while (true)
    {
        std::cout << "Enter the index of the contact to display: " << std::endl;
        std::string input;
        if (!std::getline(std::cin, input))
        {
            std::cout << "Returning to menu..." << std::endl;
            return;
        }
        
        std::stringstream ss(input);
        int index;
        if (!(ss >> index) || index < 0 || index >= 8)
        {
            std::cout << "Invalid index! Please try again." << std::endl;
            continue; 
        }
        
        Contact selected = book.get_contact(index);
        if (selected.getter(0).empty())
        {
            std::cout << "No contact at index " << index << "! Please try again." << std::endl;
            continue; 
        }
        
        std::cout << "First Name: " << selected.getter(0) << std::endl;
        std::cout << "Last Name: " << selected.getter(1) << std::endl;
        std::cout << "Nick Name: " << selected.getter(2) << std::endl;
        std::cout << "Phone Number: " << selected.getter(3) << std::endl;
        std::cout << "Darkest Secret: " << selected.getter(4) << std::endl;
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
    std::string str;
    
    while (1)
    {
        std::cout << "FIRST NAME: " << std::endl;
        if (!std::getline(std::cin, str))
        {
            std::cout << "\nReturning to menu..." << std::endl;
            return;
        }
        if (!str.empty())
            break;
        std::cout << "Empty field not allowed! Please try again." << std::endl;
    }
    cont.setter(str, 0);
    
    while (1)
    {
        std::cout << "LAST NAME: " << std::endl;
        if (!std::getline(std::cin, str))
        {
            std::cout << "\nReturning to menu..." << std::endl;
            return;
        }
        if (!str.empty())
            break;
        std::cout << "Empty field not allowed! Please try again." << std::endl;
    }
    cont.setter(str, 1);
    
    while (1)
    {
        std::cout << "NICK NAME: " << std::endl ;
        if (!std::getline(std::cin, str))
        {
            std::cout << "\nReturning to menu..." << std::endl;
            return;
        }
        if (!str.empty())
            break;
        std::cout << "Empty field not allowed! Please try again." << std::endl;
    }
    cont.setter(str, 2);
    
    while (1)
    {
        std::cout << "PHONE NUMBER: " << std::endl;
        if (!std::getline(std::cin, str))
        {
            std::cout << "\nReturning to menu..." << std::endl;
            return; 
        }
        if (str.empty())
        {
            std::cout << "Empty field not allowed! Please try again." << std::endl;
            continue;
        }
        if (!is_only_digits(str))
        {
            std::cout << "Phone number must contain only digits! Please try again." << std::endl;
            continue;
        }
        break;
    }
    cont.setter(str, 3);
    
    while (1)
    {
        std::cout << "DARKEST SECRET: " << std::endl;
        if (!std::getline(std::cin, str))
        {
            std::cout << "\nReturning to menu..." << std::endl;
            return;
        }
        if (!str.empty())
            break;
        std::cout << "Empty field not allowed! Please try again." << std::endl;
    }
    cont.setter(str, 4);
    
    add_contact_book(cont, book, real_i);
    std::cout << "Contact added successfully!" << std::endl;
}

void selection(std::string select, PhoneBook& book, int *real_i)
{
    if (select == "ADD")
    {
        create_contact(book, real_i);
    }
    if (select == "SEARCH")
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
        std::cout << "Enter command (ADD/SEARCH/EXIT): " << std::endl;
        if (!std::getline(std::cin, select))
        {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        
        if (select == "EXIT")
        {
            std::cout << "Exiting..." << std::endl;
            break ;
        }
        
        if (select == "ADD" || select == "SEARCH")
        {
            selection(select, book, &real_i);
        }
        else if (!select.empty())
        {
            std::cout << "PLEASE TYPE A VALID COMMAND (ADD/SEARCH/EXIT)" << std::endl;
        }
    }
    return 0;
}

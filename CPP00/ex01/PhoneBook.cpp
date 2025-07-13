#include "PhoneBook.hpp"

void PhoneBook::add_contact(Contact c, int i)
{
	contacts[i] = c;
}
Contact PhoneBook::get_contact(int i)
{
	return contacts[i];
}
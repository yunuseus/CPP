#include "Contact.hpp"

int Contact ::get_index()
{
	return index;
}

void Contact::set_index(int set)
{
			index = set;
}


std::string Contact::getter(int a)
{
	if (a == 0)
		return first_name;
	if (a == 1)
		return last_name;
	if (a == 2)
		return nick_name;
	if (a == 3)
		return phone_number;
	if (a == 4)
		return darkest_secret;
	else
		return NULL;
}

void Contact::setter(std:: string set, int a)
{
	if (a == 0)
		first_name = set;
	if (a == 1)
		last_name = set;
	if (a == 2)
		nick_name = set;
	if (a == 3)
		phone_number = set;
	if (a == 4)
		darkest_secret = set;
}
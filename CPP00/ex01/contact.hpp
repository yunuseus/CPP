#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std:: string first_name;
		std:: string last_name;
		std:: string nick_name;
		std:: string phone_number;
		std:: string darkest_secret;
		int index;
	public:
		int get_index()
		{
			return index;
		}
		void set_index(int set)
		{
			index = set;
		}
		std:: string getter(int a)
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
		void setter(std:: string set, int a)
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
};
#endif

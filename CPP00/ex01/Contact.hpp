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
		int get_index();
		void set_index(int set);
		std:: string getter(int a);
		void setter(std:: string set, int a);
};
#endif

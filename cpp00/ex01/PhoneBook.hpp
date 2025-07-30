#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP

#include "Contact.hpp"

class  PhoneBook
{
	private:
		Contact contacts[8];		
	public:
		void add_contact(Contact c, int i);
		Contact get_contact(int i);
};
#endif

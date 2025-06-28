#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP

#include "contact.hpp"

class  PhoneBook
{
	private:
		Contact contacts[8];
		int oldest_index;
		
	public:
		void add_contact(Contact c, int i)
		{
			contacts[i] = c;
		}
		Contact get_contact(int i)
		{
			return contacts[i];
		}
		void set_oldest_i(int i)
		{
			oldest_index = i;
		}
		int get_oldest_i()
		{
			return oldest_index;
		}

};
#endif

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "include.hpp"
#include "Contact.hpp"

class PhoneBook
{
private:
	int datalen;
	int oldest;
	Contact contacts[8];	

public:

	PhoneBook();
	void AddContact(Contact contact);
	void print_contacts();	
	void print_contact_by_index(int index);	
	~PhoneBook();
	
};

#endif
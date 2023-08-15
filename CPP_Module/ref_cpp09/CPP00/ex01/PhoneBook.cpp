#include "./PhoneBook.hpp"

void PhoneBook::AddContact(Contact contact)
{
	if (datalen < 8)
	{
		this->contacts[datalen] = contact;
		this->datalen++;
	}
	else
	{
			this->contacts[oldest] = contact;
		this->oldest = (this->oldest + 1)%8;
	}
}

void PhoneBook::print_contacts()
{
	std::cout.width(10);
	std::cout << "index" << "|" << "first name" << "|" << "last name " << "|"  << "nick name\n";
	for (int i = 0; i < datalen; i++)
	{
		std::cout.width(10);
		std::cout << i;
		this->contacts[i].print_simple();
		}
}

void PhoneBook::print_contact_by_index(int index)
{
	if (index < 0 || index > this->datalen)
		std::cout << "wrong index\n";
	this->contacts[index].print();
}

PhoneBook::PhoneBook(){
	this->datalen = 0;		
	this->oldest = 0;
};

PhoneBook::~PhoneBook()
{

}

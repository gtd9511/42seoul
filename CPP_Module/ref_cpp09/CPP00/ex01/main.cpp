
#include "include.hpp"
#include "PhoneBook.hpp"

Contact CreateContact()
{
	std::string words[5] = {"first name", "last name", "nick name", "phone number", "darkest secret"};
	std::string inputs[5];
	for(int i = 0; i < 5; i++)
	{
		std::cout << "please input " << words[i] << ": ";
		std::cin >> inputs[i];
	
	}
	Contact contact(inputs[0], inputs[1], inputs[2], inputs[3], inputs[4]);
	return contact;
}

int main()
{
	std::string str;
	PhoneBook phonebook = PhoneBook();
	while (true)
	{
		std::cout << "enter the method : ";
		std::cin >> str;
		if(std::cin.eof() == true)
			return (0);
		if (str == "ADD")
		{
			phonebook.AddContact(CreateContact());
		}
		else if(str == "SEARCH")
		{
			int index;
			phonebook.print_contacts();
			std::cin >> index;
			phonebook.print_contact_by_index(index);
		}
		else if (str == "EXIT")
		{
			return (0);
		}
	}
}
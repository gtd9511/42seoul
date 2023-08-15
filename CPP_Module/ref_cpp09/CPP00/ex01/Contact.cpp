#include "Contact.hpp"

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string darkest_secret)
{
		this->firstname = firstname; 
		this->lastname = lastname;
		this->nickname = nickname;
		this->phonenumber = phonenumber;
		this->darkest_secret = darkest_secret;
}

void Contact::print_simple()
{
	std::cout.width(11);
		if (firstname.length() >= 10)
		std::cout << firstname.substr(0,9) << ".";
	else
		std::cout << firstname;
		std::cout.width(11);
	if (lastname.length() >= 10)
		std::cout << lastname.substr(0, 9) << ".";
	else
		std::cout << lastname;
	std::cout.width(11);
	if (nickname.length() >= 10)
		std::cout << nickname.substr(0, 9) << "." << std::endl;
	else
		std::cout << nickname << std::endl;
}

void	Contact::print()
{
	std::cout.width(10);
	std::cout << "fist name : " << this->firstname << std::endl;
	std::cout << "last name : " << this->lastname << std::endl;
	std::cout << "nick name : " << this->nickname << std::endl;
	std::cout << "phone number : " << this->phonenumber << std::endl;
	std::cout << "darkest secret : " << this->darkest_secret << std::endl;
}

Contact::~Contact(){

};

Contact::Contact()
{
	
};
#include <iostream>

class Contact {
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darkest_secret;
		

public:
	Contact();
	Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string darkest_secret);
	void print_simple();
	void print();	
	~Contact();
};


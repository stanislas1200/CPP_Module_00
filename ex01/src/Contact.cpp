#include "../include/Contact.hpp"

void truncate(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
	{
		std::cout << str;
		for (long unsigned int i = 0; i < 10 - str.length(); i++)
			std::cout << " ";
	}
	// str.length() > 10 ? std::cout << str.substr(0, 9) << "." : std::cout << std::setw(10) << str
}

std::string get_input(std::string message)
{
	std::string data;

	std::cout << BO << message << C;
	std::cin.clear();
	std::cin >> data;
	if (std::cin.eof())
	{
		std::cout << R "EOF" C << std::endl;
		exit(0); //19 bytes in 1 blocks are still reachable in loss record 1 of 1
	}
	return (data);
}

void Contact::add_data()
{
	// CHECK VALID INPUT
	this->firstName = get_input("Enter first name: ");
	this->lastName = get_input("Enter last name: ");
	this->nickName = get_input("Enter nickname: ");
	this->phoneNumber = get_input("Enter phone number: ");
	this->darkestSecret = get_input("Enter darkest secret: ");
	std::cout << G "Contact added." C << std::endl;
}

void Contact::print_contact()
{
	std::cout << BO "First name: " C << this->firstName << std::endl;
	std::cout << BO "Last name: " C << this->lastName << std::endl;
	std::cout << BO "Nickname: " C << this->nickName << std::endl;
	std::cout << BO "Phone number: " C << this->phoneNumber << std::endl;
	std::cout << BO "Darkest Secret: " C << this->darkestSecret << std::endl;

}

void Contact::print_contact_line(int i)
{
	(void)i;
	std::cout << B "   " Y;
	std::cout << i + 1 << "      ";
	std::cout << B "    |" C;
	truncate(this->firstName);
	std::cout << B "|" C;
	truncate(this->lastName);
	std::cout << B "|" C;
	truncate(this->nickName);
	std::cout << C << std::endl;
}

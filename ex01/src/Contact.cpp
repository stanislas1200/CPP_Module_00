/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgodin <sgodin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:46:42 by sgodin            #+#    #+#             */
/*   Updated: 2023/09/23 14:46:42 by sgodin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

std::string get_input(std::string message)
{
	std::string data;

	std::cout << P "▶ " C BO << message << C;
	std::cin.clear();
	std::cin >> data;
	if (std::cin.eof())
	{
		std::cerr << R "EOF" C << std::endl;
		exit(1);
	}
	return (data);
}

bool is_phone_number(const std::string number)
{
	const std::string AllowedChars = "0123456789";
	if (number.length() != 10) return false;
	for(size_t i = -1; i < 9 && i < number.length() - 1; i++)
	{
		if (AllowedChars.find(number[i]))
			return false;
	}
    return true;
}

void Contact::add_data()
{
	this->firstName = get_input("Enter first name: ");
	this->lastName = get_input("Enter last name: ");
	this->nickName = get_input("Enter nickname: ");
	while (this->phoneNumber.empty())
	{
		this->phoneNumber = get_input("Enter phone number: ");
		if (!is_phone_number(this->phoneNumber))
		{
			std::cout << D R "Invalid phone number" C ": " Y << phoneNumber << " " C << std::endl;
			phoneNumber.erase();
		}
	}
	this->darkestSecret = get_input("Enter darkest secret: ");
	std::cout << D G "Contact added." C << std::endl;
}

void Contact::print_contact()
{
	std::cout << B "⮑ " C BO " First name: " C << this->firstName << std::endl;
	std::cout << B "⮑ " C BO " Last name: " C << this->lastName << std::endl;
	std::cout << B "⮑ " C BO " Nickname: " C << this->nickName << std::endl;
	std::cout << B "⮑ " C BO " Phone number: " C << this->phoneNumber << std::endl;
	std::cout << B "⮑ " C BO " Darkest Secret: " C << this->darkestSecret << std::endl;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgodin <sgodin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:46:38 by sgodin            #+#    #+#             */
/*   Updated: 2023/09/23 14:46:38 by sgodin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

void PhoneBook::add_data()
{
	std::cout << D;
	this->contacts[this->i++ % 8].add_data();
}

void PhoneBook::search_data()
{
	int i = 0;

	std::cout << D;
	if (this->i == 0)
	{
		std::cout << Y "No contacts in phonebook." C << std::endl;
		return;
	}
	while (i < 1 || i > 8 || i > this->i)
	{
		std::cout << B "   " BB Y "Index      " B "|" Y "First Name" B "|" Y "Last Name " B "|" Y "Nickname  " C << std::endl;
		for (int i = 0; i < 8 && i < this->i; i++)
			this->contacts[i].print_contact_line(i);
		std::cout << BO "Contact index ?:" C;
		std::cin.clear();
		std::cin >> i;
		if (std::cin.eof())
		{
			std::cerr << R "EOF" C << std::endl;
			exit(1);
		}
		if (i < 1 || i > 8 || i > this->i)
		{
			std::cout << D R "Invalid index" C ": " Y << i << " " C << std::endl;
			if (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore();
			}
		}
	}
	std::cout << D;
	this->contacts[i - 1].print_contact();
}

int main()
{
	std::string cmd;
	PhoneBook phoneBook;

	while (cmd != "EXIT")
	{
		std::cout << C BO U "Enter a command [" G "ADD" C BO U "][" B "SEARCH" C BO U "][" R "EXIT" C BO U "]" C BO ": " C GR;
		std::cin.clear();
		std::cin >> cmd;
		if (std::cin.eof())
			return (std::cerr << R "EOF" C << std::endl, 0);
		else if (cmd == "ADD")
			phoneBook.add_data();
		else if (cmd == "SEARCH")
			phoneBook.search_data();
		else if (cmd != "EXIT")
			std::cout << D R "Invalid command" C ": " Y << cmd << " " C << std::endl;
	}
	return 0;
}
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
#include <cstdlib>

# define C "\x1b[0m"
# define R "\x1b[1;31m"
# define G "\x1b[1;32m"
# define Y "\x1b[1;33m"
# define B "\x1b[1;34m"
# define BB "\x1b[1;44m"
# define P "\x1b[35m"
# define GR "\x1b[37m"
# define D "\x1b[H\x1b[2J"
# define BO "\x1b[1m"
# define U "\x1b[4m"


class Contact
{
	public:
		void add_data();
		void print_contact_line(int);
		void print_contact();
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif
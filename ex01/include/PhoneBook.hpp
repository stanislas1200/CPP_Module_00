#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "./Contact.hpp"

class PhoneBook
{
	private:
		int i;
		Contact contacts[8];
	public:
		PhoneBook() : i(0) {};
		void add_data();
		void search_data();
};

#endif
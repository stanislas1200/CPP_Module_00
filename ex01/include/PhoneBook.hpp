/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgodin <sgodin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:55:31 by sgodin            #+#    #+#             */
/*   Updated: 2023/09/23 16:55:31 by sgodin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
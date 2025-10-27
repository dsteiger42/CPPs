/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:54:54 by dsteiger          #+#    #+#             */
/*   Updated: 2025/08/27 18:39:08 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8];
        int _index;

        bool isValidPhoneNumber(const std::string &number);
        bool isValidInput(const std::string &input);
        std::string promptField(const std::string &label);
        std::string promptPhoneNumber(const std::string &field);
        std::string formatField(const std::string &field);
        void clearContact(int index);

    public:
        PhoneBook();
        ~PhoneBook();
        void addContact();
        void searchContact();

};

#endif
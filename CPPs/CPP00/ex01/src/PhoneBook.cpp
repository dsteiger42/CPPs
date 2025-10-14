/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:55:22 by dsteiger          #+#    #+#             */
/*   Updated: 2025/08/27 18:52:18 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_index = 0;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

bool PhoneBook::isValidInput(const std::string &input)
{
    if (input.empty())
        return false;
    return true;
}

bool PhoneBook::isValidPhoneNumber(const std::string &number)
{
    if (number.empty())
        return false;
    for (size_t i = 0; i < number.length(); ++i)
    {
        char c = number[i];
        if (!std::isdigit(static_cast<unsigned char>(c)))
        {
            if (c == '+')
            {
                if (i != 0)
                return false;
            }
            else
            return false;
        }
    }
    return true;
}

std::string PhoneBook::promptField(const std::string &field)
{
    std::string input;

    std::cout << "Enter " << field << ": ";
    if (!std::getline(std::cin, input))
    {
        std::cout << "\nEOF pressed. Exiting input.\n";
        exit(0);
    }
    while (!isValidInput(input))
    {
        std::cout << "Invalid " << field << ". Try again\n\nEnter " << field << ": ";
        std::getline(std::cin, input);
    }
    return input;
}

std::string PhoneBook::promptPhoneNumber(const std::string &field)
{
    std::string input;

    std::cout << "Enter " << field << ": ";
    if (!std::getline(std::cin, input))
    {
        std::cout << "\nEOF pressed. Exiting input.\n";
        exit(0);
    }
    while (!isValidPhoneNumber(input))
    {
        std::cout << "Invalid " << field << ". Try again\n\nEnter " << field << ": ";
        std::getline(std::cin, input);
    }
    return input;
}

// this stops adding a contact if a field is empty
void PhoneBook::clearContact(int index)
{
    _contacts[index].setFirstName("");
    _contacts[index].setLastName("");
    _contacts[index].setNickName("");
    _contacts[index].setPhoneNumber("");
    _contacts[index].setSecret("");
}

void PhoneBook::addContact(void)
{
    _contacts[_index].setFirstName(promptField("first name"));
    _contacts[_index].setLastName(promptField("last name"));
    _contacts[_index].setNickName(promptField("nick name"));
    _contacts[_index].setPhoneNumber(promptPhoneNumber("phone number"));
    _contacts[_index].setSecret(promptField("darkest secret"));

    std::cout << "\n->Contact added!\n\n";

    _index = (_index + 1) % 8;
}

std::string PhoneBook::formatField(const std::string &field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

void PhoneBook::searchContact(void)
{
    std::string input;
    int idx;

    std::cout << "|" << std::setw(10) << std::right << "Index"
              << "|" << std::setw(10) << std::right << "FirstName"
              << "|" << std::setw(10) << std::right << "LastName"
              << "|" << std::setw(10) << std::right << "Nickname"
              << "|" << std::setw(10) << std::right << "PhoneNum"
              << "|" << std::endl;
    std::cout << std::setfill('-') << std::setw(56) << "-" << std::setfill(' ') << std::endl;
    for (int i = 0; i < 8; i++)
    {
        // if I only add 1 contact, this will detect that the next 7 are empty, so it wont print the entire table
        if (_contacts[i].getFirstName().empty())
            continue;
        std::cout << "|" << std::setw(10) << std::right << i
                  << "|" << std::setw(10) << std::right << formatField(_contacts[i].getFirstName())
                  << "|" << std::setw(10) << std::right << formatField(_contacts[i].getLastName())
                  << "|" << std::setw(10) << std::right << formatField(_contacts[i].getNickName())
                  << "|" << std::setw(10) << std::right << formatField(_contacts[i].getPhoneNumber())
                  << "|" << std::endl;
    }
    while (true)
    {
        std::cout << "\nEnter index of contact to view: ";
        std::getline(std::cin, input);

        if (input.empty() || input.length() != 1 || !isdigit(input[0]))
        {
            std::cout << "Invalid index!" << std::endl;
            continue; // restarts the loop
        }
        idx = input[0] - '0';
        if (_contacts[idx].getFirstName().empty())
        {
            std::cout << "No contact at that index!" << std::endl;
            continue;
        }
        break;
    }
    std::cout << std::endl;
    std::cout << "First Name: " << _contacts[idx].getFirstName() << std::endl;
    std::cout << "Last Name: " << _contacts[idx].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[idx].getNickName() << std::endl;
    std::cout << "Phone Number: " << _contacts[idx].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << _contacts[idx].getSecret() << std::endl;
    std::cout << std::endl;
}

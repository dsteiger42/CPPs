/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:55:15 by dsteiger          #+#    #+#             */
/*   Updated: 2025/08/25 16:29:38 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Contact.hpp"

// Setters
void Contact::setFirstName(const std::string &first)
{
	_first_name = first;
}

void Contact::setLastName(const std::string &last)
{
	_last_name = last;
}

void Contact::setNickName(const std::string &nick)
{
	_nick_name = nick;
}

void Contact::setPhoneNumber(const std::string &phone)
{
	_phone_number = phone;
}

void Contact::setSecret(const std::string &secret)
{
	_darkest_secret = secret;
}

// Getters
std::string Contact::getFirstName() const
{
	return (_first_name);
}

std::string Contact::getLastName() const
{
	return (_last_name);
}

std::string Contact::getNickName() const
{
	return (_nick_name);
}

std::string Contact::getPhoneNumber() const
{
	return (_phone_number);
}

std::string Contact::getSecret() const
{
	return (_darkest_secret);
}

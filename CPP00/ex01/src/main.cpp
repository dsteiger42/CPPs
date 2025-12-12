/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:55:18 by dsteiger          #+#    #+#             */
/*   Updated: 2025/08/27 18:31:27 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/PhoneBook.hpp"

std::string display_prompt()
{
	std::string command;
	std::cout << "Enter one of these commands: ADD | SEARCH | EXIT\n> ";
	if (!std::getline(std::cin, command))
		return ("");
	return (command);
}

void handle_sigint(int)
{
    exit(0);
}

int	main(void)
{
	signal(SIGINT, handle_sigint);
	PhoneBook phone1;
	Contact contact1;
	std::string userInput;

	while (true)
	{
		userInput = display_prompt();
		if (userInput.empty() && std::cin.eof()) {
			std::cout << "\nEOF pressed.\n";
			break ;
		}
		if (userInput == "ADD")
			phone1.addContact();
		else if (userInput == "SEARCH")
            phone1.searchContact();
		else if (userInput == "EXIT")
            break;
		else
			std::cout << "Invalid command. Please choose a valid option.\n\n";
	}
}

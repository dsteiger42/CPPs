/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:01:13 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/14 10:47:48 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	(void)src;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

static std::string trim(const std::string &s)
{
	size_t	start;
	size_t	end;

	start = s.find_first_not_of(" \t");
	end = s.find_last_not_of(" \t");
	if (start == std::string::npos)
		return ("");
	return (s.substr(start, end - start + 1));
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7) // '-' in YYYY-MM-DD
			continue ;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (year < 2009)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31,
		30, 31};

	int maxDay = daysInMonth[month - 1];
	if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
		maxDay = 29;
	return (day >= 1 && day <= maxDay);
}

void BitcoinExchange::processInput(const std::string &filename)
{
	size_t	pipe;

	std::ifstream file(filename.c_str());
	std::string line;
	std::getline(file, line); // header
	while (std::getline(file, line)) {
		pipe = line.find("|");
		if (pipe == std::string::npos) {
			std::cerr << "Error: bad input => " << line << "\n";
			continue ;
		}
		std::string date = line.substr(0, pipe);
		std::string value = line.substr(pipe + 1);
		date = trim(date);
		value = trim(value);
		if (date.empty() || value.empty()) {
    		std::cerr << "Error: bad input => " << line << std::endl;
    		continue;
		}
		if (!isValidDate(date)) {
			std::cerr << "Error1: bad input => " << line << "\n";
			continue ;
		}
		double intValue = atof(value.c_str());
		if(intValue < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		if(intValue > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		std::map<std::string, double>::iterator iter = database.upper_bound(date);
		if(iter == database.begin()) {
			std::cerr << "Error: no exchange rate found for " << date << std::endl;
		}
		--iter;

		double rate = iter->second;
		double result = intValue * rate;
		std::cout << date << "=> " << intValue << " = " << result << std::endl;
	}
}

// ifstream closes the file automatically
void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open database file: " + filename);
    }
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        std::string date = trim(line.substr(0, comma));
        double value = atof(trim(line.substr(comma + 1)).c_str());
        database[date] = value;
    }
}

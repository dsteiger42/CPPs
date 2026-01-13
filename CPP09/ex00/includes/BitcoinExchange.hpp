/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:06:41 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/13 16:44:31 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <map>
#include <algorithm>

class BitcoinExchange
{
    private:
        std::map<std::string, double> database;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange();

        bool isValidDate(const std::string &date) const;
        void processInput(const std::string &filename);
        void loadDatabase(const std::string &filename);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:48:34 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/14 11:59:52 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <sstream>
#include <string>

class RPN
{
    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &src);
        ~RPN();

        bool validateInput(std::string str);
        int calculate(const std::string &input);
};

#endif
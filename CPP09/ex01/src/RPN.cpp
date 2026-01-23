/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:48:52 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/21 18:05:20 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &src)
{
	(void)src;
	return (*this);
}

RPN::~RPN() {}

bool isNumber(const std::string &str)
{
    if(str.empty())
        return false;
    size_t i = 0;
    if(str[i] == '+' || str[i] == '-')
        i++;
    if(i == str.size())
        return false;
    while(i < str.size())
    {
        if(!isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

bool isOperator(const std::string &str)
{
    if(str.size() != 1)
        return false;
    char c = str[0];
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::validateInput(std::string str)
{
	std::string signs = "+-*/";
	for (size_t i = 0; i < str.size(); i++) {
		char c = str[i];
		if (!std::isdigit(static_cast<unsigned char>(c))
			&& signs.find(c) == std::string::npos && c != ' ')
			return (false);
	}
	return (true);
}
//  std::istringstream readInput(str); this already separates tokens by spaces
int RPN::calculate(const std::string &input)
{
    std::stack<int> stk;
    std::istringstream readInput(input);
    std::string token;

    while(readInput >> token) {
        if(isNumber(token))
            stk.push(std::atoi(token.c_str()));
        else if(isOperator(token)) {
            if(stk.size() < 2) {
                std::cerr << "Error: not enough numbers in the stack to calculate" << std::endl;
                return -1;
            }
            int right = stk.top();
            stk.pop();
            int left = stk.top();
            stk.pop();
            if(token == "+")
                stk.push(left + right);
            else if(token == "-")
                stk.push(left - right);
            else if(token == "*")
                stk.push(left * right);
            else if(token == "/")
            {
                if(right == 0)
                {
                    std::cerr << "Error: 0 is not divisible" << std::endl;
                    return -1;
                }
                else
                    stk.push(left / right);
            }
            else{
                std::cerr << "Error: wrong operator input" << std::endl;
                return -1;
            }
        }
    }
    if (stk.size() != 1) {
        std::cerr << "Invalid expression" << std::endl;
        return -1;
    }
    return stk.top();
}

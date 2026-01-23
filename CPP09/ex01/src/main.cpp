/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:48:49 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/21 16:14:26 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char **argv)
{
    if(argc != 2) {
        std::cerr << "Error: Wrong number of arguments" << std::endl;
        return -1;
    }
    RPN rpn;
    if(!rpn.validateInput(argv[1])) {
        std::cerr << "Error: invalid input" << std::endl;
        return -1;
    }
    int result = rpn.calculate(argv[1]);
    if(result == -1)
        return -1;
    std::cout << result << std::endl;
    return 0;
}
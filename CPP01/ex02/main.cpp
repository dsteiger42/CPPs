/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:51:24 by dsteiger          #+#    #+#             */
/*   Updated: 2025/09/01 18:33:43 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str; //stores the adress of a string. &str is the adress of a string
    std::string &stringREF = str; //lets you acess the value of str

    std::cout << &str << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << str << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
    return 0;
}

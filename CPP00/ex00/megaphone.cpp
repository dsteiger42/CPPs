/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:55:01 by dsteiger          #+#    #+#             */
/*   Updated: 2025/08/27 14:52:13 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i = 1;
    int j = 0;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    while (argv[i])
    {
        j = 0;
        while(argv[i][j])
        {
            std::cout << (char)toupper(argv[i][j]);
            j++;
        }
        if (argv[i + 1])
            std::cout << " ";
        i++;
    }
    std::cout << std::endl;
    return (0);
}
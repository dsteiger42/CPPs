/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:47:05 by dsteiger          #+#    #+#             */
/*   Updated: 2025/11/11 19:29:06 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

int main(void)
{
	try
	{
		Array<int> a(5);
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i * 10;

		std::cout << "Array a: ";
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;

		Array<int> b(a);
		std::cout << "Array b (copy): ";
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << b[i] << " ";
		std::cout << std::endl;

		Array<int> c;
		c = a;
		std::cout << "Array c: ";
		for (unsigned int i = 0; i < c.size(); i++)
			std::cout << c[i] << " ";
		std::cout << std::endl;

		b[0] = 999;
		std::cout << "b[0] = " << b[0] << std::endl;

		Array<std::string> s(3);
		s[0] = "Hello";
		s[1] = "World";
		s[2] = "42";

		for (unsigned int i = 0; i < s.size(); i++)
			std::cout << s[i] << " ";
		std::cout << std::endl;
		std::cout << a[a.size()] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}

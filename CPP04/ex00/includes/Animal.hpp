/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:50:11 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/27 15:02:48 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
virtual makes both dog and cat be destroyed,
instead of animal destroyed 3x.
Virtual tells the compiler that a function
might be overriden by the Derived Class.
Doesnt decide at compile time, but at runtime.

Note: you can't make a member function virtual without
making the destructor also virtual.
*/

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
  protected:
	std::string _type;

  public:
	Animal();
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
};

#endif
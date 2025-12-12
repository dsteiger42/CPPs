/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:52:21 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/24 18:19:08 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
  protected:
  	Animal();
  	std::string _type;
  
  public:
 	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
	virtual ~Animal();
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif
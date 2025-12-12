/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:05:54 by dsteiger          #+#    #+#             */
/*   Updated: 2025/09/01 17:24:33 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  private:
	std::string	_name;

  public:
	  Zombie();
	  Zombie(std::string name);
	  ~Zombie();

	  void announce(void);
	  void setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif
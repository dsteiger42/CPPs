/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:02:29 by dsteiger          #+#    #+#             */
/*   Updated: 2025/09/01 13:37:30 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
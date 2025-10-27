/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:16:00 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/20 18:22:55 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

class ScavTrap : public ClapTrap
{
  private:
  public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &copy);
	ScavTrap &operator=(ScavTrap const &copy);
	~ScavTrap();
	void attack(std::string const &target);
	void guardGate();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:16:09 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/20 18:22:51 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

class ClapTrap
{
  protected:
	std::string _Name;
	int _HitPoint;
	int _EnergyPoints;
	int _AttackDamage;

  public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &copy);
	ClapTrap &operator=(ClapTrap const &copy);
	~ClapTrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	int getEnergyPoints() const;
	void setIncreaseAttack(unsigned int amount);
	int getAttackDamage() const;
	int getHitPoints() const;
};

#endif
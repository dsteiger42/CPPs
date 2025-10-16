#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
#include "ClapTrap.hpp"

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

class ScavTrap
{
  private:


  public:
    ScavTrap();
    ScavTrap(ScavTrap const &copy);
	ScavTrap &operator=(ScavTrap const &copy);
	~ScavTrap();
    void guardGate();
};

#endif
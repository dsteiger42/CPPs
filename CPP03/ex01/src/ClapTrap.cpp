#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_Name = "Napolean";
	_HitPoint = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
	std::cout << YELLOW << "Default constructor activated" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	_Name = copy._Name;
	_HitPoint = copy._HitPoint;
	_EnergyPoints = copy._EnergyPoints;
	_AttackDamage = copy._AttackDamage;
	std::cout << GREEN << "Copy constructor activated" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
	if (this != &copy)
	{
		_Name = copy._Name;
		_HitPoint = copy._HitPoint;
		_EnergyPoints = copy._EnergyPoints;
		_AttackDamage = copy._AttackDamage;
	}
	std::cout << BLUE << "Assignment operator activated" << RESET << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "Destructor activated" << RESET << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_HitPoint < 1)
	{
		std::cout << "The enemy is dead\n";
		return ;
	}
	if (_EnergyPoints < 1)
	{
		std::cout << "You have no energy. Try cocaine\n";
		return ;
	}
	_EnergyPoints--;
	std::cout << "ClapTrap " << _Name << " attacks " << target
                << ", causing " << _AttackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoint < 1)
	{
		std::cout << "Claptrap " << _Name << " is dead!" << std::endl;
		return ;
	}
	_HitPoint -= amount;
	std::cout << "ClapTrap " << _Name << " took a hit and lost " << amount << "hp!\n";
	if (_HitPoint < 1)
	{
		std::cout << "ClapTrap " << _Name << " died!" << std::endl;
		_HitPoint = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_HitPoint < 1)
	{
		std::cout << "The enemy is dead\n";
		return ;
	}
	if (_EnergyPoints < 1)
	{
		std::cout << "You have no energy. Try cocaine\n";
		return ;
	}
	_HitPoint++;
	_EnergyPoints--;
	std::cout << "ClapTrap " << _Name << " repairs itself " << amount << "hp!\n";
}

void ClapTrap::increaseAttack(unsigned int amount)
{
	std::cout << "attack damage before boost " << _AttackDamage << std::endl;
	_AttackDamage += amount;
	std::cout << "ClapTrap " << _Name << " improves his attack power by " << amount << " damage!" << std::endl;
	std::cout << "attack damage after boost " << _AttackDamage << std::endl;
}

int ClapTrap::getEnergyPoints() const
{
	return (_EnergyPoints);
}

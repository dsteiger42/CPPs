/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:30:32 by dsteiger          #+#    #+#             */
/*   Updated: 2025/09/01 18:54:08 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
    private:
        std::string _type;

    public:
        Weapon();
        Weapon(const std::string &type);
        ~Weapon();
        std::string getType() const; 
        void setType(const std::string &value);
};

#endif
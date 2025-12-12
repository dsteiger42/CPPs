/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:52:23 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/24 15:52:24 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
  private:
    std::string _ideas[100];
    
  public:
	Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &copy);
	virtual ~Brain();
    void setIdea(int index, std::string idea);
    std::string getIdea(int index) const;
};

#endif
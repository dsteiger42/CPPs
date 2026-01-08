/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:09:00 by dsteiger          #+#    #+#             */
/*   Updated: 2026/01/08 16:09:01 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_HPP
#define MUTANT_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <exception>
#include <limits>
#include <ctime>
#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::deque<T>::iterator iter;
        typedef typename std::deque<T>::const_iterator const_iter;
        typedef typename std::deque<T>::reverse_iterator rev_iter;
        typedef typename std::deque<T>::const_reverse_iterator const_rev_iter;

        MutantStack() : std::stack<T>()
        {
            std::cout << "Default constructor called" << std::endl;
        };
        MutantStack(const MutantStack &copy)
        {
            *this = copy;
        };
        MutantStack &operator=(const MutantStack &src)
        {
            if (this != &src)
                std::stack<T>::operator=(src);
            return (*this);
        };
        ~MutantStack()
        {
            std::cout << "Destructor called" << std::endl;
        };

        iter begin()
        {
            return this->c.begin();
        }

        const_iter begin() const
        {
            return this->c.begin();
        }


        iter end()
        {
            return this->c.end();
        }

        const_iter end() const
        {
            return this->c.end();
        }


        rev_iter rbegin()
        {
            return this->c.rbegin();
        }

        const_rev_iter rbegin() const
        {
            return this->c.rbegin();
        }


        rev_iter rend()
        {
            return this->c.rend();
        }

        const_rev_iter rend() const
        {
            return this->c.rend();
        }
};

#endif
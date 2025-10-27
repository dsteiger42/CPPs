/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:52:04 by dsteiger          #+#    #+#             */
/*   Updated: 2025/10/24 17:59:05 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main(void)
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    j->makeSound();
    i->makeSound();
    delete j;
    delete i;

    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << std::endl;

    int const n = 10;
    Animal *animals[n];

    // Create dogs
    for (int i = 0; i < n / 2; i++)
    {
        Dog *dog = new Dog();
        animals[i] = dog;
        dog->getBrain()->setIdea(0, "Vamos morder o Rafa");
        dog->getBrain()->setIdea(1, "Boa ideia Scooby");
    }
    // Create cats
    for (int i = n / 2; i < n; i++)
    {
        Cat *cat = new Cat();
        animals[i] = cat;
        cat->getBrain()->setIdea(0, "Vamos cagar fora da caixa");
        cat->getBrain()->setIdea(1, "Boa ideia Garfield");
    }
    // Print dog ideas
    for (int i = 0; i < n; i++)
    {
        if (animals[i]->getType() == "Dog")
        {
            Dog *dog = dynamic_cast<Dog *>(animals[i]);
            for (int j = 0; !dog->getBrain()->getIdea(j).empty(); j++)
                std::cout << dog->getBrain()->getIdea(j) << std::endl;
        }
    }
    // Print cat ideas
    for (int i = 0; i < n; i++)
    {
        if (animals[i]->getType() == "Cat")
        {
            Cat *cat = dynamic_cast<Cat *>(animals[i]);
            for (int j = 0; !cat->getBrain()->getIdea(j).empty(); j++)
                std::cout << cat->getBrain()->getIdea(j) << std::endl;
        }
    }
    for (int i = 0; i < n; i++)
        delete animals[i];

    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << std::endl;

    Dog dog;
    dog.getBrain()->setIdea(0, "Lets play fetch.");
    std::cout << dog.getBrain()->getIdea(0) << std::endl;

    return (0);
}

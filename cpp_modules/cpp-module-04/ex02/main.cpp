/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:22:09 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/08 18:08:45 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#if 1

int	main(void)
{
	// Animal	test;
	{
		LOG_TITLE("Animal + Dog + Cat TEST")

		// Animal	*ptr_an1 = new Animal();
		LOG_NEWLINE

		Animal	*ptr_an2 = new Dog();
		LOG_NEWLINE

		Animal	*ptr_an3 = new Cat();
		LOG_NEWLINE

		// animal
		// std::cout << ptr_an1->getType() << " : "; ptr_an1->makeSound();

		// dog
		std::cout << ptr_an2->getType() << " : "; ptr_an2->makeSound();

		// cat
		std::cout << ptr_an3->getType() << " : "; ptr_an3->makeSound();

		LOG_NEWLINE
		// delete ptr_an1;

		LOG_NEWLINE
		delete ptr_an2;

		LOG_NEWLINE
		delete ptr_an3;
	}
	return 0;
}

#elif 1

#define SUBTAB_SIZE	3

int main()
{
	{
		LOG_TITLE("TEST 1")
		Animal *anx[SUBTAB_SIZE * 2];

		for (int i = 0; i < SUBTAB_SIZE; i++)
			anx[i] = new Dog();
		for (int i = SUBTAB_SIZE; i < SUBTAB_SIZE * 2; i++)
			anx[i] = new Cat();

		for (int i = 0; i < SUBTAB_SIZE; i++)
			delete anx[i];
		for (int i = SUBTAB_SIZE; i < SUBTAB_SIZE * 2; i++)
			delete anx[i];
		LOG_NEWLINE
	}
	{
		LOG_TITLE("TEST 2")
		Dog a;

		a.getBrain().setIdea(0, "idea 0 a");
		a.getBrain().setIdea(1, "idea 1 a");
		a.getBrain().setIdea(2, "idea 2 a");
		{
			Dog b(a);
			b.getBrain().setIdea(0, "idea 0 b");
			for (int i = 0; i < 5; i++)
				std::cout	<< "brain[" << i << "] :'" << b.getBrain().getIdea(i) << "'" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			std::cout	<< "brain[" << i << "] :'" << a.getBrain().getIdea(i) << "'" << std::endl;
		LOG_NEWLINE
	}
	{
		LOG_TITLE("TEST 3")
		Dog a;

		a.getBrain().setIdea(0, "idea 0 a");
		a.getBrain().setIdea(1, "idea 1 a");
		a.getBrain().setIdea(2, "idea 2 a");
		{
			Dog b; b = a;
			b.getBrain().setIdea(0, "idea 0 b");
			for (int i = 0; i < 5; i++)
				std::cout	<< "brain[" << i << "] :'" << b.getBrain().getIdea(i) << "'" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			std::cout	<< "brain[" << i << "] :'" << a.getBrain().getIdea(i) << "'" << std::endl;
	}
	{
		LOG_TITLE("TEST 4")
		Cat* a = new Cat();

		a->getBrain().setIdea(0, "idea 0 a");
		a->getBrain().setIdea(1, "idea 1 a");
		a->getBrain().setIdea(2, "idea 2 a");
		for (int i = 0; i < 5; i++)
			std::cout	<< "brain[" << i << "] :'" << a->getBrain().getIdea(i) << "'" << std::endl;
		Dog* b = new Dog();
		
		b->getBrain() = a->getBrain();
		delete a;

		for (int i = 0; i < 5; i++)
			std::cout	<< "brain[" << i << "] :'" << b->getBrain().getIdea(i) << "'" << std::endl;

		delete b;

	}
	return 0;
	return 0;
}

#else

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	return 0;
}

#endif

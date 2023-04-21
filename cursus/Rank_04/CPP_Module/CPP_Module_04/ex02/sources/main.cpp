/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:11:45 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/23 17:57:04 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

int main(void)
{
	std::string	str;

	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	delete j;//should not create a leak
	delete i;

	Animal	*a[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			a[i] = new Cat();
		else
		 	a[i] = new Dog();
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		a[i]->makeSound();
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		delete a[i];
	}

	std::cout << "--------------------------" <<std::endl;

	Dog *dog1 = new Dog();
	Dog *dog2 = new Dog();
	Dog temp = *dog1;
	std::cout << std::endl;
	temp = *dog2;
	std::cout << std::endl;
	str = dog1->getBrain()->getIdeas(0);
	std::cout << "First Dog's first idea is "<< str << std::endl;

	dog1->getBrain()->setIdeas("something", 0);
	str = dog1->getBrain()->getIdeas(0);
	std::cout << "Frist Dog's first idea is "<< str << std::endl;

	std::cout << std::endl;
	*dog2 = *dog1;
	str = dog2->getBrain()->getIdeas(0);
	std::cout << "Second Dog's first idea is "<< str << std::endl;

	std::cout << std::endl;
	delete dog1;
	dog1 = NULL;
	delete dog2;
	dog2 = NULL;

	return (0);
}

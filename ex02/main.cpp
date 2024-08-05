/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:53:41 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/08/05 18:27:44 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>

int main(int ac, char *av[])
{
	if (ac <= 2)
	{
		std::cerr
			<< "Error: PmergeMe takes at least two positive integers as arguments."
			<< std::endl;
		return EXIT_FAILURE;
	}
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j] != '\0'; j++)
		{
			if (!std::isdigit(av[i][j]))
			{
				std::cerr << "Error: not valid positive integer." << std::endl;
				return EXIT_FAILURE;
			}
		}
		if (std::atol(av[i]) > INT_MAX)
		{
			std::cerr << "Error: input outside bounds." << std::endl;
			return EXIT_FAILURE;
		}
	}
	PmergeMe::run(ac, av);
	return 0;
}

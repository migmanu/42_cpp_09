/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:53:41 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/07/24 17:42:06 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (std::strlen(av[i]) > 10 || std::strcmp(av[i], "2147483647") > 0)
		{
			std::cerr << "Error." << std::endl;
			return EXIT_FAILURE;
		}
		for (int j = 0; av[i][j] != '\0'; j++)
		{
			if (!std::isdigit(av[i][j]))
			{
				std::cerr << "Error." << std::endl;
				return EXIT_FAILURE;
			}
		}
	}
	return 0;
}

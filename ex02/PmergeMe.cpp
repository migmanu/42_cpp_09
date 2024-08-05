/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <jmanuelmigoya@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:59:14 by migmanu           #+#    #+#             */
/*   Updated: 2024/08/05 17:56:21 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

void print_list(std::list<int> list)
{
	std::list<int>::iterator it = list.begin();
	for (; it != list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

PmergeMe::~PmergeMe(void)
{
	return;
}

void PmergeMe::PmergeMe_list(int ac, char *av[])
{
	if (arg_check(ac, av))
	{
		clock_t begin_time = clock();
		std::list<int> list = create_list(ac, av);
		std::cout << "Before: ";
		print_list(list);
		if (!PmergeMe::is_list_sorted(list))
		{
			list = sort_list(list);
		}
		std::cout << "After: ";
		print_list(list);
		clock_t end_time = clock();
		double elapsed_secs = double(end_time - begin_time) / CLOCKS_PER_SEC;
		elapsed_secs = elapsed_secs * 1e6;
		std::cout << std::setprecision(5);
		std::cout << "Time to process a range of " << ac - 1
				  << " elements with std::list: " << std::fixed << elapsed_secs
				  << " us" << std::endl;
	}
}

bool PmergeMe::arg_check(int ac, char *av[])
{
	if (ac <= 2)
	{
		std::cerr
			<< "Error: PmergeMe takes at least two positive integers as arguments."
			<< std::endl;
		return false;
	}
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j] != '\0'; j++)
		{
			if (!std::isdigit(av[i][j]))
			{
				std::cerr << "Error: not valid positive integer." << std::endl;
				return false;
			}
		}
		if (std::atol(av[i]) > INT_MAX)
		{
			std::cerr << "Error: input outside bounds." << std::endl;
			return false;
		}
	}
	return true;
}

bool PmergeMe::is_list_sorted(std::list<int> list)
{
	std::list<int> list_cpy = list;
	list_cpy.sort();
	if (list_cpy == list)
		return true;
	return false;
}

std::list<int> PmergeMe::create_list(int ac, char *av[])
{
	std::list<int> list;
	for (int i = 1; i < ac; i++)
	{
		list.insert(list.end(), std::atol(av[i]));
	}
	return list;
}

std::list<int> PmergeMe::sort_list(std::list<int> &list)
{
	if (list.size() <= 1)
	{
		return list;
	}

	std::list<int>::iterator middle = list.begin();
	std::advance(middle, list.size() / 2);

	std::list<int> left_half(list.begin(), middle);
	std::list<int> right_half(middle, list.end());

	left_half = sort_list(left_half);
	right_half = sort_list(right_half);

	left_half.merge(right_half);

	return left_half;
}

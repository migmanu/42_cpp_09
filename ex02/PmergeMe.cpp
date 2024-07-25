/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <jmanuelmigoya@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:59:14 by migmanu           #+#    #+#             */
/*   Updated: 2024/07/25 22:25:26 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void print_list(std::list<int> list)
{
	std::cout << "List: ";
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
	std::list<int> list = create_list(ac, av);
	std::cout << "List size: " << list.size() << std::endl;
	PmergeMe::is_list_sorted(list) ? std::cout << "List sorted" << std::endl
								   : std::cout << "Not sorted" << std::endl;
	if (!PmergeMe::is_list_sorted(list))
	{
		list = sort_list(list);
		print_list(list);
	}
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

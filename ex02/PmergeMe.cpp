/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <jmanuelmigoya@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:59:14 by migmanu           #+#    #+#             */
/*   Updated: 2024/08/05 19:24:10 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::~PmergeMe(void)
{
	return;
}

void print_nbrs(char **av)
{
	for (int i = 1; av[i] != NULL; i++)
	{
		std::cout << " " << av[i];
	}
	std::cout << std::endl;
}

void PmergeMe::run(int ac, char **av)
{
	if (arg_check(ac, av))
	{
		std::cout << "Before: ";
		print_nbrs(av);
		clock_t list_begin = clock();
		std::list<int> list = PmergeMe_list(ac, av);
		clock_t list_end = clock();
		clock_t deque_begin = clock();
		std::deque<int> dq = PmergeMe_deque(ac, av);
		clock_t deque_end = clock();
		std::cout << "After: ";
		print_list(list);
		// print_deque(dq);
        measure_and_print_time(list_begin, list_end, ac, "std::list");
        measure_and_print_time(deque_begin, deque_end, ac, "std::deque");
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

double PmergeMe::measure_and_print_time(clock_t begin, clock_t end, int ac, const std::string& container_type)
{
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    elapsed_secs = elapsed_secs * 1e6;
    std::cout << std::setprecision(5);
    std::cout << "Time to process a range of " << ac - 1
              << " elements with " << container_type << ": " << std::fixed << elapsed_secs
              << " us" << std::endl;
    return elapsed_secs;
}

// STD::LIST

std::list<int> PmergeMe::PmergeMe_list(int ac, char *av[])
{
	std::list<int> list = create_list(ac, av);
	if (!PmergeMe::is_list_sorted(list))
	{
		list = sort_list(list);
	}
	return list;
}

void PmergeMe::print_list(std::list<int> list)
{
	std::list<int>::iterator it = list.begin();
	for (; it != list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
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

// STD::DEQUE

std::deque<int> PmergeMe::PmergeMe_deque(int ac, char *av[])
{
	std::deque<int> dq = create_deque(ac, av);
	if (!PmergeMe::is_deque_sorted(dq))
	{
		dq = sort_deque(dq);
	}
	return dq;
}

void PmergeMe::print_deque(std::deque<int> dq)
{
	std::deque<int>::iterator it = dq.begin();
	for (; it != dq.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

bool PmergeMe::is_deque_sorted(std::deque<int> dq)
{
	for (size_t i = 0; i < dq.size() - 1; i++)
	{
		if (dq[i] > dq[i + 1])
			return false;
	}
	return true;
}

std::deque<int> PmergeMe::create_deque(int ac, char *av[])
{
	std::deque<int> dq;
	for (int i = 1; i < ac; i++)
	{
		dq.insert(dq.end(), std::atol(av[i]));
	}
	return dq;
}

std::deque<int> PmergeMe::sort_deque(std::deque<int> &dq)
{
	if (dq.size() <= 1)
	{
		return dq;
	}

	std::deque<int>::iterator middle = dq.begin();
	std::advance(middle, dq.size() / 2);

	std::deque<int> left_half(dq.begin(), middle);
	std::deque<int> right_half(middle, dq.end());

	left_half = sort_deque(left_half);
	right_half = sort_deque(right_half);

	std::deque<int> result;
	result.resize(left_half.size() + right_half.size());
	std::merge(left_half.begin(), left_half.end(), right_half.begin(),
			   right_half.end(), result.begin());

	return result;
}

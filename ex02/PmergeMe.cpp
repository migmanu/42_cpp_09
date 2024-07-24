#include "PmergeMe.hpp"

PmergeMe::~PmergeMe(void)
{
	return;
}

void PmergeMe::PmergeMe_list(int ac, char *av[])
{
	std::list<int> list = create_list(av);
}

// TODO: this can't be right
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
		for (int j = 0; av[i][j] != '\0'; j++)
		{
		}
	}
}

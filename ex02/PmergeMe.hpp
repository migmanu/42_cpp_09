#include <cstdlib>
#include <iostream>
#include <list>

class PmergeMe
{
  public:
	~PmergeMe(void);
	static void PmergeMe_list(int ac, char *av[]);

  private:
	PmergeMe(void);
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &rhs);

	static std::list<int> sort_list(std::list<int> &list);
	static std::list<int> create_list(int ac, char *av[]);
	static bool is_list_sorted(std::list<int> list);
};

#include <climits>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>

class PmergeMe
{
  public:
	~PmergeMe(void);
	static void run(int ac, char *av[]);

  private:
	PmergeMe(void);
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &rhs);

	static bool arg_check(int ac, char *av[]);
	static double measure_and_print_time(clock_t begin, clock_t end, int ac,
								  const std::string &container_type);

	// STD::LIST
	static std::list<int> PmergeMe_list(int ac, char *av[]);
	static void print_list(std::list<int> list);
	static std::list<int> sort_list(std::list<int> &list);
	static std::list<int> create_list(int ac, char *av[]);
	static bool is_list_sorted(std::list<int> list);

	// STD::DEQUE
	static std::deque<int> PmergeMe_deque(int ac, char *av[]);
	static void print_deque(std::deque<int> dq);
	static std::deque<int> sort_deque(std::deque<int> &dq);
	static std::deque<int> create_deque(int ac, char *av[]);
	static bool is_deque_sorted(std::deque<int> dq);
};

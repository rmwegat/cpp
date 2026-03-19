#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <list>
#include <deque>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <utility>
#include <time.h>
#include <exception>

# define SET_A false
# define SET_B true

struct PendingNode
{
	int value;
	PendingNode(int v) : value(v) {}
};

struct dequePendingNode
{
	int value;
	dequePendingNode(int v) : value(v) {}
};

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &copy);
		~PmergeMe();
		void sortlist(std::string input);
		void sortDeque(std::string input);
		void print_list();
		void print_deque();
		void compare_sorts();
		double	getListTime();
		double	getDequeTime();
		std::list<int>& getList();
		std::deque<int>& getDeque();
	private:
		void sortListPairs();
		void buildListMainChain();
		void insertListPending();

		void sortDequePairs();
		void buildDequeMainChain();
		void insertDequePending();

		std::list<int> list_sort;
		std::deque<int> deque_sort;
		double		list_duration;
		double		deque_duration;
		int			_order;
		int			_last;
		bool		_has_odd_element;
		std::list<int> _new_list;
		std::list<int> _main_chain_list;
		std::list<PendingNode> _pending_list;
		std::list<int> _non_participating_list;
		std::deque<int> _new_deque;
		std::deque<int> _main_chain_deque;
		std::deque<dequePendingNode> _pending_deque;
		std::deque<int> _non_participating_deque;
};

#endif
#include "PmergeMe.hpp"

// *************** Orhodox Canonical Form ***************

PmergeMe::PmergeMe()
{
	this->_order = 1;
	this->_last = 0;
	this->_has_odd_element = false;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	this->list_sort = copy.list_sort;
	this->deque_sort = copy.deque_sort;
	this->_order = copy._order;
	this->_last = copy._last;
	this->_has_odd_element = copy._has_odd_element;
	this->_main_chain_list = copy._main_chain_list;
	this->_pending_list = copy._pending_list;
	this->_non_participating_list = copy._non_participating_list;
	this->_new_list = copy._new_list;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy)
{
	this->list_sort = copy.list_sort;
	this->deque_sort = copy.deque_sort;
	this->_order = copy._order;
	this->_last = copy._last;
	this->_has_odd_element = copy._has_odd_element;
	this->_main_chain_list = copy._main_chain_list;
	this->_pending_list = copy._pending_list;
	this->_non_participating_list = copy._non_participating_list;
	this->_new_list = copy._new_list;
	return (*this);
}

PmergeMe::~PmergeMe() {}


// *************** Populate Containers ***************

static std::list<int>fill_list(std::string input)
{
	std::list<int> list;
	if (input.find_first_not_of("0123456789 ") != std::string::npos){
		throw std::runtime_error("Error: invalid input");
		return list;}
	std::stringstream ss(input);
	std::string token;
	while(std::getline(ss, token, ' '))
		list.push_back(std::atoi(token.c_str()));
	return list;
}

static std::deque<int>fill_deque(std::string input)
{
	std::deque<int> list;
	if (input.find_first_not_of("0123456789 ") != std::string::npos){
		throw std::runtime_error("Error: invalid input");
		return list;}
	std::stringstream ss(input);
	std::string token;
	while(std::getline(ss, token, ' '))
		list.push_back(std::atoi(token.c_str()));
	return list;
}

// n-th pair of pending elements insertet for somehow better chache performance
static int jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return(1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void PmergeMe::sortListPairs()
{
	// Determine number of pairs (double until bigger than half, then half once)
	std::list<int>::iterator it = this->list_sort.begin();
	bool stop = false;
	std::list<int>::iterator next = it;
	next++;
	int first_pair = 0;
	int max_order = 1;
	while(max_order < (int)this->list_sort.size() / 2)
		max_order *= 2;
	if (max_order > (int)(this->list_sort.size() / 2))
		max_order /= 2;
	if (max_order < 2 && this->list_sort.size() >= 2)
		max_order = 2;
	
	// Save last element if uneven size
	if (this->list_sort.size() % 2 != 0)
	{
		this->_last = this->list_sort.back();
		this->_has_odd_element = true;
		this->list_sort.pop_back();
	}
	
	// Iteratively sort pairs with doubling pair sizes and swaping
	while(this->_order < max_order)
	{
		// Initialize for this iteration of sorting
		// pair_size is stored in this->_order
		int pair = 0;
		stop = false;
		first_pair = 0;
		it = this->list_sort.begin();
		next = it;
		std::list<int>::iterator swap_pair_one;
		std::list<int>::iterator swap_pair_two;
		
		// Position 'next' iterator pair_size elements ahead of 'it'
		// This creates the first block of pair_size elements to compare
		for (int j = 1; j <= this->_order && next != this->list_sort.end(); j++)
			next++;
		
		// Process all pairs in the list with current pair_size
		while(it != this->list_sort.end() && next != this->list_sort.end() && stop == false)
		{
			if (it == this->list_sort.end() || next == this->list_sort.end())
				break ;
			
			// Only 2 Elements (2x "pair" of size 1)
			if (this->_order == 1)
			{
				if (next == this->list_sort.end())
					break ;
				if (*it > *next)
				{
					int temp = *it;
					*it = *next;
					*next = temp;
				}
				it++;
				next++;
				if (next == this->list_sort.end())
					break ;
				it++;
				next++;
				pair++;
			}
			// pair_size > 1 (comparing blocks of elements)
			else
			{
				int i = 1;
				pair++;
				swap_pair_one = this->list_sort.begin();
				swap_pair_two = this->list_sort.begin();
				
				// Position iterators to the two blocks being compared
				if (first_pair == 0)
				{
					// First pair: advance to end of first block
					for (; i < this->_order; i++)
					{
						next++;
						it++;
						if (next == this->list_sort.end())
							stop = true;
					}
					first_pair++;
				}
				else
				{
					// Subsequent pairs: advance past both blocks
					for (;i<=this->_order * 2;++i)
					{
						next++;
						it++;
						if (next == this->list_sort.end() || it == this->list_sort.end())
							stop = true;
					}
				}
				if (next == this->list_sort.end())
					stop = true;
				if (stop)
					break ;
				
				// Compare the two blocks by comparing their largest elements
				if (*it > *next)
				{
					swap_pair_one = it;
					swap_pair_two = next;
					
					// Move iterators to start of each block
					for (int count = this->_order; count > 1; count--)
					{
						swap_pair_one--;
						swap_pair_two--;
					}
					
					// Swap all elements in the two blocks
					for (int count = 1; count <= this->_order; count++)
					{
						int temp = *swap_pair_one;
						*swap_pair_one = *swap_pair_two;
						*swap_pair_two = temp;
						swap_pair_one++;
						swap_pair_two++;
						if (swap_pair_two == this->list_sort.end())
							stop = true;
					}
					
					// Advance iterators to next pair of blocks
					if (first_pair == 1)	
					for (int i = 1; i < this->_order; i++){
						swap_pair_two++;
						swap_pair_one++;
						if (swap_pair_two == this->list_sort.end())
						stop = true;
					}
					else
					for (int i = 1; i <this->_order; i++)
					{
						next++;
						it++;
						if (next == this->list_sort.end())
						stop = true;
					}
					if (next == this->list_sort.end())
					stop = true;
				}
			}
		}
		// After comparing all pairs with current pair_size, double the pair_size
		this->_order *= 2;
	}
	//basically now every second element is sorted
}

void PmergeMe::buildListMainChain()
{
	// Identify full groups and non-participating elements
	// • Groups of size _order
	// • Mark incomplete groups as non-participating
	int half = this->_order / 2;
	int full_groups = 0;
	std::list<int>::iterator it;
	for (it = this->_new_list.begin(); it != this->_new_list.end();)
	{
		if (std::distance(it, this->_new_list.end()) < this->_order)
		{
			for (; it != this->_new_list.end(); ++it)
				this->_non_participating_list.push_back(*it);
			break;
		}
		std::advance(it, this->_order);
		full_groups++;
	}
	
	//Split groups into losers (first half) and winners (second half), insert winners
	it = this->_new_list.begin();
	for (int g = 0; g < full_groups; g++)
	{
		std::list<int> loser_values;
		std::list<int> winner_values;
		for (int i = 0; i < half && it != this->_new_list.end(); ++i, ++it)
		loser_values.push_back(*it);
		for (int i = 0; i < half && it != this->_new_list.end(); ++i, ++it)
		winner_values.push_back(*it);
		if (winner_values.empty())
		continue ;
		int key = winner_values.back();
		// binary search for insertion
		std::list<int>::iterator insert_pos = std::upper_bound(this->_main_chain_list.begin(), this->_main_chain_list.end(), key);
		for (std::list<int>::iterator wit = winner_values.begin(); wit != winner_values.end(); ++wit)
		{
			this->_main_chain_list.insert(insert_pos, *wit);
		}
		
		// Create pending list with losers to be inserted later using Jacobsthal order
		for (std::list<int>::iterator l_it = loser_values.begin(); l_it != loser_values.end(); ++l_it)
		{
			this->_pending_list.push_back(PendingNode(*l_it));
		}
	}
}

void PmergeMe::insertListPending() //losers
{
	//Insert first pending element
	int pend_size = (int)this->_pending_list.size();
	if (pend_size > 0)
	{
		auto first_pend = this->_pending_list.begin();
		std::list<int>::iterator pos = std::upper_bound(this->_main_chain_list.begin(), this->_main_chain_list.end(), first_pend->value);
		this->_main_chain_list.insert(pos, first_pend->value);
	}
	
	// Generate insertion order using Jacobsthal sequence
	// Sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341,, ...
	std::list<int> insert_order;
	if (pend_size > 1)
	{
		int jacob_prev = 1;
		int jacob_curr = 3;
		int k = 4;
		while (jacob_prev < pend_size)
		{
			int high = (jacob_curr < pend_size) ? jacob_curr : pend_size;
			for (int i = high; i > jacob_prev; --i)
				insert_order.push_back(i);
			jacob_prev = jacob_curr;
			jacob_curr = jacobsthal(k);
			k++;
		}
	}
	
	// Insert elements in Jacobsthal order
	// track which elements have been inserted
	std::list<bool> inserted;
	for (int i = 0; i < pend_size; ++i)
		inserted.push_back(i == 0);
	for (std::list<int>::iterator ord_it = insert_order.begin(); ord_it != insert_order.end(); ++ord_it)
	{
		int pend_idx = *ord_it; 
		if (pend_idx <= 0 || pend_idx > pend_size)
			continue;
		std::list<bool>::iterator ins_it = inserted.begin();
		std::advance(ins_it, pend_idx -1);
		if (*ins_it)
			continue;
		*ins_it = true;
		auto pend_it = this->_pending_list.begin();
		std::advance(pend_it, pend_idx - 1);
		std::list<int>::iterator pos = std::upper_bound(this->_main_chain_list.begin(), this->_main_chain_list.end(), pend_it->value);
		this->_main_chain_list.insert(pos, pend_it->value);
	}
	
	// Insert remaining pending elements not covered by Jacobsthal
	std::list<bool>::iterator ins_check = inserted.begin();
	for (auto pend_it = this->_pending_list.begin(); pend_it != this->_pending_list.end(); ++pend_it, ++ins_check)
	{
		if (!(*ins_check))
		{
			std::list<int>::iterator pos = std::upper_bound(this->_main_chain_list.begin(), this->_main_chain_list.end(), pend_it->value);
			this->_main_chain_list.insert(pos, pend_it->value);
		}
	}
	
	// Insert non-participating elements
	for (std::list<int>::iterator np_it = this->_non_participating_list.begin(); np_it != this->_non_participating_list.end(); ++np_it)
	{
		std::list<int>::iterator pos = std::upper_bound(this->_main_chain_list.begin(), this->_main_chain_list.end(), *np_it);
		this->_main_chain_list.insert(pos, *np_it);
	}
	//the list is now sorted
}

void PmergeMe::sortlist(std::string input)
{
	this->list_sort = fill_list(input);
	clock_t start = clock();
	this->_order = 1;
	this->_last = 0;
	this->_has_odd_element = false;
	sortListPairs();
	if (this->_has_odd_element)
		this->list_sort.push_back(this->_last);
	this->_new_list.insert(this->_new_list.end(),this->list_sort.begin(), this->list_sort.end());
	while(this->_order > 1)
	{
		buildListMainChain();
		insertListPending();
		this->_new_list.clear();
		this->_new_list.insert(this->_new_list.end(), this->_main_chain_list.begin(), this->_main_chain_list.end());
		this->_main_chain_list.clear();
		this->_pending_list.clear();
		this->_non_participating_list.clear();
		this->_order/=2;
	}
	this->list_sort = this->_new_list;
	clock_t end = clock();
	this->list_duration = double(end - start) / CLOCKS_PER_SEC;
}




// ********************* Same code as before but for Deque *********************



void PmergeMe::sortDequePairs()
{
	std::deque<int>::iterator it = this->deque_sort.begin();
	bool stop = false;
	std::deque<int>::iterator next = it;
	next++;
	int first_pair = 0;
	int max_order = 1;
	while(max_order < (int)this->deque_sort.size() / 2)
		max_order *= 2;
	if (max_order > (int)(this->deque_sort.size() / 2))
		max_order /= 2;
	if (max_order < 2 && this->deque_sort.size() >= 2)
		max_order = 2;
	if (this->deque_sort.size() % 2 != 0)
	{
		this->_last = this->deque_sort.back();
		this->_has_odd_element = true;
		this->deque_sort.pop_back();
	}
	while(this->_order < max_order)
	{
		int pair = 0;
		stop = false;
		first_pair = 0;
		it = this->deque_sort.begin();
		next = it;
		std::deque<int>::iterator swap_pair_one;
		std::deque<int>::iterator swap_pair_two;
		for (int j = 1; j <= this->_order && next != this->deque_sort.end(); j++)
			next++;
		while(it != this->deque_sort.end() && next != this->deque_sort.end() && stop == false)
		{
			if (it == this->deque_sort.end() || next == this->deque_sort.end())
				break ;
			if (this->_order == 1)
			{
				if (next == this->deque_sort.end())
					break ;
				if (*it > *next)
				{
					int temp = *it;
					*it = *next;
					*next = temp;
				}
				it++;
				next++;
				if (next == this->deque_sort.end())
					break ;
				it++;
				next++;
				pair++;
			}
			else
			{
				int i = 1;
				pair++;
				swap_pair_one = this->deque_sort.begin();
				swap_pair_two = this->deque_sort.begin();
				if (first_pair == 0)
				{
					for (; i < this->_order; i++)
					{
						next++;
						it++;
						if (next == this->deque_sort.end())
							stop = true;
					}
					first_pair++;
				}
				else
				{
					for (;i<=this->_order * 2;++i)
					{
						next++;
						it++;
						if (next == this->deque_sort.end() || it == this->deque_sort.end())
							stop = true;
					}
				}
				if (next == this->deque_sort.end())
					stop = true;
				if (stop)
					break ;
				if (*it > *next)
				{
					swap_pair_one = it;
					swap_pair_two = next;
					for (int count = this->_order; count > 1; count--)
					{
						swap_pair_one--;
						swap_pair_two--;
					}
					for (int count = 1; count <= this->_order; count++)
					{
						int temp = *swap_pair_one;
						*swap_pair_one = *swap_pair_two;
						*swap_pair_two = temp;
						swap_pair_one++;
						swap_pair_two++;
						if (swap_pair_two == this->deque_sort.end())
							stop = true;
					}
					if (first_pair == 1)	
					for (int i = 1; i < this->_order; i++){
						swap_pair_two++;
						swap_pair_one++;
						if (swap_pair_two == this->deque_sort.end())
						stop = true;
					}
					else
					for (int i = 1; i <this->_order; i++)
					{
						next++;
						it++;
						if (next == this->deque_sort.end())
						stop = true;
					}
					if (next == this->deque_sort.end())
					stop = true;
				}
			}
		}
		this->_order *= 2;
	}
}

void PmergeMe::buildDequeMainChain()
{
	int half = this->_order / 2;
	int full_groups = 0;
	std::deque<int>::iterator it;
	for (it = this->_new_deque.begin(); it != this->_new_deque.end();)
	{
		if (std::distance(it, this->_new_deque.end()) < this->_order)
		{
			for (; it != this->_new_deque.end(); ++it)
				this->_non_participating_deque.push_back(*it);
			break;
		}
		std::advance(it, this->_order);
		full_groups++;
	}
	it = this->_new_deque.begin();
	for (int g = 0; g < full_groups; g++)
	{
		std::deque<int> loser_values;
		std::deque<int> winner_values;
		for (int i = 0; i < half && it != this->_new_deque.end(); ++i, ++it)
			loser_values.push_back(*it);
		for (int i = 0; i < half && it != this->_new_deque.end(); ++i, ++it)
			winner_values.push_back(*it);
		if (winner_values.empty())
			continue ;
		int key = winner_values.back();
		std::deque<int>::iterator insert_pos = std::upper_bound(this->_main_chain_deque.begin(), this->_main_chain_deque.end(), key);
		size_t insert_idx = std::distance(this->_main_chain_deque.begin(), insert_pos);
		for (std::deque<int>::iterator wit = winner_values.begin(); wit != winner_values.end(); ++wit)
		{
			this->_main_chain_deque.insert(this->_main_chain_deque.begin() + insert_idx, *wit);
			insert_idx++;
		}
		for (std::deque<int>::iterator l_it = loser_values.begin(); l_it != loser_values.end(); ++l_it)
		{
			this->_pending_deque.push_back(dequePendingNode(*l_it));
		}
	}
}

void PmergeMe::insertDequePending()
{
	int pend_size = (int)this->_pending_deque.size();
	if (pend_size > 0)
	{
		std::deque<dequePendingNode>::iterator first_pend = this->_pending_deque.begin();
		std::deque<int>::iterator pos = std::upper_bound(this->_main_chain_deque.begin(), this->_main_chain_deque.end(), first_pend->value);
		this->_main_chain_deque.insert(pos, first_pend->value);
	}
	std::deque<int> insert_order;
	if (pend_size > 1)
	{
		int jacob_prev = 1;
		int jacob_curr = 3;
		int k = 4;
		while (jacob_prev < pend_size)
		{
			int high = (jacob_curr < pend_size) ? jacob_curr : pend_size;
			for (int i = high; i > jacob_prev; --i)
				insert_order.push_back(i);
			jacob_prev = jacob_curr;
			jacob_curr = jacobsthal(k);
			k++;
		}
	}
	std::deque<bool> inserted;
	for (int i = 0; i < pend_size; ++i)
		inserted.push_back(i == 0);
	for (std::deque<int>::iterator ord_it = insert_order.begin(); ord_it != insert_order.end(); ++ord_it)
	{
		int pend_idx = *ord_it;
		if (pend_idx <= 0 || pend_idx > pend_size)
			continue;
		std::deque<bool>::iterator ins_it = inserted.begin();
		std::advance(ins_it, pend_idx - 1);
		if (*ins_it)
			continue;
		*ins_it = true;
		std::deque<dequePendingNode>::iterator pend_it = this->_pending_deque.begin();
		std::advance(pend_it, pend_idx - 1);
		std::deque<int>::iterator pos = std::upper_bound(this->_main_chain_deque.begin(), this->_main_chain_deque.end(), pend_it->value);
		this->_main_chain_deque.insert(pos, pend_it->value);
	}
	std::deque<bool>::iterator ins_check = inserted.begin();
	for (std::deque<dequePendingNode>::iterator pend_it = this->_pending_deque.begin(); pend_it != this->_pending_deque.end(); ++pend_it, ++ins_check)
	{
		if (!(*ins_check))
		{
			std::deque<int>::iterator pos = std::upper_bound(this->_main_chain_deque.begin(), this->_main_chain_deque.end(), pend_it->value);
			this->_main_chain_deque.insert(pos, pend_it->value);
		}
	}
	for (std::deque<int>::iterator np_it = this->_non_participating_deque.begin(); np_it != this->_non_participating_deque.end(); ++np_it)
	{
		std::deque<int>::iterator pos = std::upper_bound(this->_main_chain_deque.begin(), this->_main_chain_deque.end(), *np_it);
		this->_main_chain_deque.insert(pos, *np_it);
	}
}

void PmergeMe::sortDeque(std::string input)
{
	this->deque_sort = fill_deque(input);
	clock_t start = clock();
	this->_order = 1;
	this->_last = 0;
	this->_has_odd_element = false;
	sortDequePairs();
	if (this->_has_odd_element)
		this->deque_sort.push_back(this->_last);
	this->_new_deque.insert(this->_new_deque.end(),this->deque_sort.begin(), this->deque_sort.end());
	while(this->_order > 1)
	{
		buildDequeMainChain();
		insertDequePending();
		this->_new_deque.clear();
		this->_new_deque.insert(this->_new_deque.end(), this->_main_chain_deque.begin(), this->_main_chain_deque.end());
		this->_main_chain_deque.clear();
		this->_pending_deque.clear();
		this->_non_participating_deque.clear();
		this->_order/=2;
	}
	this->deque_sort = this->_new_deque;
	clock_t end = clock();
	this->deque_duration = double(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::print_list()
{
	for (std::list<int>::const_iterator it = this->list_sort.begin(); it != this->list_sort.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::print_deque()
{
	for (std::deque<int>::const_iterator it = this->deque_sort.begin(); it != this->deque_sort.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::compare_sorts()
{
	std::list<int>::iterator l_it = this->list_sort.begin();
	std::deque<int>::iterator d_it = this->deque_sort.begin();
	if (this->list_sort.size() != this->deque_sort.size())
		throw std::runtime_error("Error: list_sort and deque_sort dont contain the same amount of variables");
	while(l_it != this->list_sort.end() && d_it != this->deque_sort.end())
	{
		if (*l_it != *d_it)
			throw std::runtime_error("Error: list_sort and deque_sort contain different values");
		l_it++;
		d_it++;
	}
}

double	PmergeMe::getListTime()
{
	return (this->list_duration);
}

double	PmergeMe::getDequeTime()
{
	return (this->deque_duration);
}
std::list<int>& PmergeMe::getList()
{
	return (this->list_sort);
}

std::deque<int>& PmergeMe::getDeque()
{
	return (this->deque_sort);
}
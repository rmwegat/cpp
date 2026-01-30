#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe: Default Constructor called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	this->list_sort = copy.list_sort;
	this->deque_sort = copy.deque_sort;
	std::cout << "PmergeMe: copy Constructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy)
{
	this->list_sort = copy.list_sort;
	this->deque_sort = copy.deque_sort;
	std::cout << "PmergeMe: Assignment Constructor called" << std::endl;
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe: Default Deconstructor called" << std::endl;
}

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

static int jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return(1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void PmergeMe::sortlist(std::string input)
{
	this->list_sort = fill_list(input);
	clock_t start = clock();
	std::list<int>::iterator it = this->list_sort.begin();
	int first_pair = 0;
	it = this->list_sort.begin();
	bool stop = false;
	std::list<int>::iterator next = it;
	next++;
	int order = 1;
	int last = 0;
	bool has_odd_element = false;
	int max_order = 1;
	while(max_order < (int)this->list_sort.size() / 2)
		max_order *= 2;
	if (max_order > (int)(this->list_sort.size() / 2))
		max_order /= 2;
	if (max_order < 2 && this->list_sort.size() >= 2)
		max_order = 2;
	if (this->list_sort.size() % 2 != 0)
	{
		last = this->list_sort.back();
		has_odd_element = true;
		this->list_sort.pop_back();
	}
	while(order < max_order)
	{
		int pair = 0;
		// if (order > (int)this->list_sort.size() / 2)
		// 	break ;
		stop = false;
		first_pair = 0;
		it = this->list_sort.begin();
		next = it;
		// next++;
		std::list<int>::iterator swap_pair_one;
		std::list<int>::iterator swap_pair_two;
		for (int j = 1; j <= order && next != this->list_sort.end(); j++)
			next++;
		while(it != this->list_sort.end() && next != this->list_sort.end() && stop == false)
		{
			if (it == this->list_sort.end() || next == this->list_sort.end())
				break ;
			if (order == 1)
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
			//sort pairs
			else
			{
				int i = 1;
				pair++;
				swap_pair_one = this->list_sort.begin();
				swap_pair_two = this->list_sort.begin();
				if (first_pair == 0)
				{
					for (; i < order; i++)
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
					for (;i<=order * 2;++i)
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
				if (*it > *next)
				{
					swap_pair_one = it;
					swap_pair_two = next;
					for (int count = order; count > 1; count--)
					{
						swap_pair_one--;
						swap_pair_two--;
					}
					for (int count = 1; count <= order; count++)
					{
						int temp = *swap_pair_one;
						*swap_pair_one = *swap_pair_two;
						*swap_pair_two = temp;
						swap_pair_one++;
						swap_pair_two++;
						if (swap_pair_two == this->list_sort.end())
							stop = true;
					}
					if (first_pair == 1)	
					for (int i = 1; i < order; i++){
						swap_pair_two++;
						swap_pair_one++;
						if (swap_pair_two == this->list_sort.end())
						stop = true;
					}
					else
					for (int i = 1; i <order; i++)
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
			// std::cout << *it << "\t\t" << *next << std::endl;
		}
		order *= 2;
	}
	// Re-add the odd element that was removed at the start
	if (has_odd_element)
		this->list_sort.push_back(last);
	//insertion
	std::list<int> main;
	std::list<PendingNode> pending;
	std::list<int> non_participaring;
	std::list<int> new_list;
	std::list<std::list<int>::iterator> b_group;
	new_list.insert(new_list.end(),this->list_sort.begin(), this->list_sort.end());
	while(order > 1)
	{

		int half = order / 2;
		
		// First, separate out the non-participating elements
		int full_groups = 0;
		for (it = new_list.begin(); it != new_list.end();)
		{
			if (std::distance(it, new_list.end()) < order)
			{
				for (; it != new_list.end(); ++it)
					non_participaring.push_back(*it);
				break;
			}
			std::advance(it, order);
			full_groups++;
		}
		
		// Process pairs of half-groups
		// Extract loser and winner sub-groups, insert winners into main using binary search
		it = new_list.begin();
		for (int g = 0; g < full_groups; g++)
		{
			std::list<int> loser_values;
			std::list<int> winner_values;
			
			for (int i = 0; i < half && it != new_list.end(); ++i, ++it)
				loser_values.push_back(*it);
			
			for (int i = 0; i < half && it != new_list.end(); ++i, ++it)
				winner_values.push_back(*it);
			
			if (winner_values.empty())
				continue ;
			int key = winner_values.back();
			std::list<int>::iterator insert_pos = std::upper_bound(main.begin(), main.end(), key);
			
			// Track the iterators for the inserted winner elements
			std::list<std::list<int>::iterator> winner_iters;
			for (std::list<int>::iterator wit = winner_values.begin(); wit != winner_values.end(); ++wit)
			{
				std::list<int>::iterator m_it = main.insert(insert_pos, *wit);
				winner_iters.push_back(m_it);
			}
			
			// Create pending nodes pairing losers with winners
			std::list<int>::iterator l_it = loser_values.begin();
			std::list<std::list<int>::iterator>::iterator w_iter = winner_iters.begin();
			for (; l_it != loser_values.end() && w_iter != winner_iters.end(); ++l_it, ++w_iter)
			{
				pending.push_back(PendingNode(*l_it, *w_iter));
			}
		}
		//insertion using Jacobsthal sequence 
		int pend_size = (int)pending.size();
		
		if (pend_size > 0)
		{
			std::list<PendingNode>::iterator first_pend = pending.begin();
			std::list<int>::iterator pos = std::upper_bound(main.begin(), main.end(), first_pend->value);
			main.insert(pos, first_pend->value);
		}

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
		
		std::list<bool> inserted;
		for (int i = 0; i < pend_size; ++i)
			inserted.push_back(i == 0); 
		
		// Insert pending elements in Jacobsthal order using full binary search
		for (std::list<int>::iterator ord_it = insert_order.begin(); ord_it != insert_order.end(); ++ord_it)
		{
			int pend_idx = *ord_it; 
			if (pend_idx <= 0 || pend_idx >= pend_size)
				continue;
			std::list<bool>::iterator ins_it = inserted.begin();
			std::advance(ins_it, pend_idx);
			if (*ins_it)
				continue;
			*ins_it = true;
			std::list<PendingNode>::iterator pend_it = pending.begin();
			std::advance(pend_it, pend_idx);
			std::list<int>::iterator pos = std::upper_bound(main.begin(), main.end(), pend_it->value);
			main.insert(pos, pend_it->value);
		}
		
		// Insert any remaining pending elements that weren't covered
		std::list<bool>::iterator ins_check = inserted.begin();
		for (std::list<PendingNode>::iterator pend_it = pending.begin(); pend_it != pending.end(); ++pend_it, ++ins_check)
		{
			if (!(*ins_check))
			{
				std::list<int>::iterator pos = std::upper_bound(main.begin(), main.end(), pend_it->value);
				main.insert(pos, pend_it->value);
			}
		}

		// Insert non-participating elements using binary search as well
		for (std::list<int>::iterator np_it = non_participaring.begin(); np_it != non_participaring.end(); ++np_it)
		{
			std::list<int>::iterator pos = std::upper_bound(main.begin(), main.end(), *np_it);
			main.insert(pos, *np_it);
		}
		
		new_list.clear();
		new_list.insert(new_list.end(), main.begin(), main.end());
		// pending and non-participating elements are now in main
		main.clear();
		pending.clear();
		non_participaring.clear();
		order/=2;
	}
	this->list_sort = new_list;
	clock_t end = clock();
	this->list_duration = double(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::sortDeque(std::string input)
{
	this->deque_sort = fill_deque(input);
	clock_t start = clock();
	std::deque<int>::iterator it = this->deque_sort.begin();
	// print unsorted for debuging
	// end printing
	int first_pair = 0;
	it = this->deque_sort.begin();
	bool stop = false;
	std::deque<int>::iterator next = it;
	next++;
	int order = 1;
	int last = 0;
	bool has_odd_element = false;
	int max_order = 1;
	while(max_order < (int)this->deque_sort.size() / 2)
		max_order *= 2;
	if (max_order > (int)(this->deque_sort.size() / 2))
		max_order /= 2;
	if (max_order < 2 && this->deque_sort.size() >= 2)
		max_order = 2;
	if (this->deque_sort.size() % 2 != 0)
	{
		last = this->deque_sort.back();
		has_odd_element = true;
		this->deque_sort.pop_back();
	}
	while(order < max_order)
	{
		int pair = 0;
		// if (order > (int)this->deque_sort.size() / 2)
		// 	break ;
		stop = false;
		first_pair = 0;
		it = this->deque_sort.begin();
		next = it;
		// next++;
		std::deque<int>::iterator swap_pair_one;
		std::deque<int>::iterator swap_pair_two;
		for (int j = 1; j <= order && next != this->deque_sort.end(); j++)
			next++;
		while(it != this->deque_sort.end() && next != this->deque_sort.end() && stop == false)
		{
			if (it == this->deque_sort.end() || next == this->deque_sort.end())
				break ;
			if (order == 1)
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
			//sort pairs
			else
			{
				int i = 1;
				pair++;
				swap_pair_one = this->deque_sort.begin();
				swap_pair_two = this->deque_sort.begin();
				if (first_pair == 0)
				{
					for (; i < order; i++)
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
					for (;i<=order * 2;++i)
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
					for (int count = order; count > 1; count--)
					{
						swap_pair_one--;
						swap_pair_two--;
					}
					for (int count = 1; count <= order; count++)
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
					for (int i = 1; i < order; i++){
						swap_pair_two++;
						swap_pair_one++;
						if (swap_pair_two == this->deque_sort.end())
						stop = true;
					}
					else
					for (int i = 1; i <order; i++)
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
			// std::cout << *it << "\t\t" << *next << std::endl;
		}
		order *= 2;
	}
	// Re-add the odd element that was removed at the start
	if (has_odd_element)
		this->deque_sort.push_back(last);
	//insertion
	std::deque<int> main;
	std::deque<dequePendingNode> pending;
	std::deque<int> non_participaring;
	std::deque<int> new_list;
	std::deque<std::deque<int>::iterator> b_group;
	new_list.insert(new_list.end(),this->deque_sort.begin(), this->deque_sort.end());
	while(order > 1)
	{

		int half = order / 2;
		
		// First, separate out the non-participating elements
		int full_groups = 0;
		for (it = new_list.begin(); it != new_list.end();)
		{
			if (std::distance(it, new_list.end()) < order)
			{
				for (; it != new_list.end(); ++it)
					non_participaring.push_back(*it);
				break;
			}
			std::advance(it, order);
			full_groups++;
		}
		
		// Process pairs of half-groups
		// Extract loser and winner sub-groups, insert winners into main using binary search
		it = new_list.begin();
		for (int g = 0; g < full_groups; g++)
		{
			std::deque<int> loser_values;
			std::deque<int> winner_values;
			
			// Read loser sub-group (first 'half' elements of this order-group)
			for (int i = 0; i < half && it != new_list.end(); ++i, ++it)
				loser_values.push_back(*it);
			
			// Read winner sub-group (next 'half' elements)
			for (int i = 0; i < half && it != new_list.end(); ++i, ++it)
				winner_values.push_back(*it);
			
			// Insert winner values into main at correct sorted position using binary search
			// The key for insertion is the last (largest) element of the winner group
			if (winner_values.empty())
				continue ;
			int key = winner_values.back();
			std::deque<int>::iterator insert_pos = std::upper_bound(main.begin(), main.end(), key);
			size_t insert_idx = std::distance(main.begin(), insert_pos);
			
			// Insert all winner values at the position (use index since deque iterators are invalidated)
			for (std::deque<int>::iterator wit = winner_values.begin(); wit != winner_values.end(); ++wit)
			{
				main.insert(main.begin() + insert_idx, *wit);
				insert_idx++;
			}
			
			// Create pending nodes pairing losers with winners (don't store iterators for deque)
			std::deque<int>::iterator l_it = loser_values.begin();
			std::deque<int>::iterator w_it = winner_values.begin();
			for (; l_it != loser_values.end() && w_it != winner_values.end(); ++l_it, ++w_it)
			{
				pending.push_back(dequePendingNode(*l_it, main.end())); // partner iterator not used for deque
			}
		}
		//insertion using Jacobsthal sequence (Ford-Johnson)
		int pend_size = (int)pending.size();
		
		// First, insert b1 using binary search
		if (pend_size > 0)
		{
			std::deque<dequePendingNode>::iterator first_pend = pending.begin();
			std::deque<int>::iterator pos = std::upper_bound(main.begin(), main.end(), first_pend->value);
			main.insert(pos, first_pend->value);
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
					insert_order.push_back(i); // 1-indexed, will subtract 1 when accessing
				jacob_prev = jacob_curr;
				jacob_curr = jacobsthal(k);
				k++;
			}
		}
		
		// Mark which pending elements have been inserted (index 0 already done above)
		std::deque<bool> inserted;
		for (int i = 0; i < pend_size; ++i)
			inserted.push_back(i == 0); // index 0 is already inserted
		
		// Insert pending elements in Jacobsthal order using full binary search
		for (std::deque<int>::iterator ord_it = insert_order.begin(); ord_it != insert_order.end(); ++ord_it)
		{
			int pend_idx = *ord_it;
			if (pend_idx <= 0 || pend_idx >= pend_size)
				continue;
			
			// Check if already inserted
			std::deque<bool>::iterator ins_it = inserted.begin();
			std::advance(ins_it, pend_idx);
			if (*ins_it)
				continue;
			*ins_it = true;
			
			// Find the pending node at index pend_idx
			std::deque<dequePendingNode>::iterator pend_it = pending.begin();
			std::advance(pend_it, pend_idx);
			
			// Binary search across entire main chain
			std::deque<int>::iterator pos = std::upper_bound(main.begin(), main.end(), pend_it->value);
			main.insert(pos, pend_it->value);
		}
		
		// Insert remaining
		std::deque<bool>::iterator ins_check = inserted.begin();
		for (std::deque<dequePendingNode>::iterator pend_it = pending.begin(); pend_it != pending.end(); ++pend_it, ++ins_check)
		{
			if (!(*ins_check))
			{
				std::deque<int>::iterator pos = std::upper_bound(main.begin(), main.end(), pend_it->value);
				main.insert(pos, pend_it->value);
			}
		}

		// Insert non-participating elements
		for (std::deque<int>::iterator np_it = non_participaring.begin(); np_it != non_participaring.end(); ++np_it)
		{
			std::deque<int>::iterator pos = std::upper_bound(main.begin(), main.end(), *np_it);
			main.insert(pos, *np_it);
		}
		
		new_list.clear();
		new_list.insert(new_list.end(), main.begin(), main.end());
		main.clear();
		pending.clear();
		non_participaring.clear();
		order/=2;
	}
	this->deque_sort = new_list;
	clock_t end = clock();
	this->deque_duration = double(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::print_list()
{
	std::list<int>::iterator it = this->list_sort.begin();
	for (;it != this->list_sort.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::print_deque()
{
	//std::deque<int>::iterator it = this->deque_sort.begin();
	//for (;it != this->deque_sort.end(); it++)
	//	std::cout << *it << " ";
	for (size_t i = 0; i < this->deque_sort.size(); i++)
		std::cout << this->deque_sort[i] << " ";
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
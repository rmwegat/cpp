/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:17:16 by ldick             #+#    #+#             */
/*   Updated: 2025/08/29 16:22:28 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::list<int>::iterator partner;
	PendingNode(int v, std::list<int>::iterator p) : value(v), partner(p) {}
};

struct dequePendingNode
{
	int value;
	std::deque<int>::iterator partner;
	dequePendingNode(int v, std::deque<int>::iterator p) : value(v), partner(p) {}
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
		std::list<int> list_sort;
		std::deque<int> deque_sort;
		double		list_duration;
		double		deque_duration;
};

#endif
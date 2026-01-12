/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchance.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:30:21 by ldick             #+#    #+#             */
/*   Updated: 2025/08/25 16:04:27 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

class	btc
{
	public:
		btc();
		btc(btc const &copy);
		btc &operator =(btc const &copy);
		~btc();
		int		Check_Data_Bank(const char *data);
		void	add_databank(std::string);
		int		Check_input(char *data);
		void	add_input(std::string line);
		void	calculate(void);
	private:
		std::vector<int> _data_bank_date;
		std::vector<double> _data_bank_value;
		std::vector<int> _input_data_date;
		std::vector<double> _input_data_value;
};

#endif
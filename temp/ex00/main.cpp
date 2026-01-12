/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:33:46 by ldick             #+#    #+#             */
/*   Updated: 2025/08/25 13:51:11 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchance.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	btc Bitcoin;
	Bitcoin.Check_Data_Bank("data.csv");
	Bitcoin.Check_input(argv[1]);
	Bitcoin.calculate();
	return (0);
}
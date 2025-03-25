/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 22:25:26 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/25 23:05:02 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "DEBUG:" << std::endl;
	harl.complain("DEBUG");
	std::cout << "INFO:" << std::endl;
	harl.complain("INFO");
	std::cout << "WARNING:" << std::endl;
	harl.complain("WARNING");
	std::cout << "ERROR:" << std::endl;
	harl.complain("ERROR");
	std::cout << "LEVEL 1:" << std::endl;
	harl.complain("1");
	std::cout << "LEVEL 2:" << std::endl;
	harl.complain("2");
	std::cout << "LEVEL 3:" << std::endl;
	harl.complain("3");
	std::cout << "LEVEL 4:" << std::endl;
	harl.complain("4");

	return (0);
}
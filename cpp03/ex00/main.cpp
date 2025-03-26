/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:50:13 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/26 16:52:26 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("Claptrap");

	claptrap.attack("Siren");
	claptrap.takeDamage(5);
	claptrap.beRepaired(10);
	claptrap.takeDamage(10);
	std::cout << "Fight is over" << std::endl;
	return 0;
}
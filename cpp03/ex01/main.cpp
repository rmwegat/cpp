/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:50:13 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/27 11:03:32 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap claptrap("Claptrap");
	ScavTrap scavtrap("Scavtrap");

	std::cout << "The fight begins!" << std::endl;

	claptrap.attack("Scavtrap");
	scavtrap.takeDamage(claptrap.getAttackDamage());

	scavtrap.attack("Claptrap");
	claptrap.takeDamage(scavtrap.getAttackDamage());

	scavtrap.guardGate();

	claptrap.beRepaired(5);
	scavtrap.beRepaired(5);

	std::cout << "Fight is over" << std::endl;
	return 0;
}
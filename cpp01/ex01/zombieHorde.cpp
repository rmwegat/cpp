/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:35:14 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/25 16:36:16 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int i = 0;
    if (N <= 0)
	{
        return nullptr; 
    }
    Zombie* horde = new Zombie[N];
    while (i < N)
	{
        horde[i].setName(name);
		i++;
    }
    return horde;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 22:19:09 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/26 10:01:24 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*pfunctions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string numericLevels[] = {"1", "2", "3", "4"};
	int i = 0;
	while (i < 4)
	{
		if (level == complains[i] || level == numericLevels[i])
		{
			i++;
			break;
		}
	}
	switch ()
	{
	case 0:
		(this->*pfunctions[0])();
	case 1:
		(this->*pfunctions[1])();
	case 2:
		(this->*pfunctions[2])();
	case 3:
		(this->*pfunctions[3])();
		break;
	default:
		std::cout << "[ Nothing of significance]" << std::endl;
		break;
	}
}

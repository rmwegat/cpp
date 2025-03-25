/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:14:37 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/25 17:18:10 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

    std::cout << "Adress str: " << &str << std::endl;
    std::cout << "Adress stringPTR: " << stringPTR << std::endl;
    std::cout << "Adress stringREF: " << &stringREF << std::endl;
	
	std::cout << "Value str: " << str << std::endl;
	std::cout << "Value stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value stringREF: " << stringREF << std::endl;
	return 0;
}
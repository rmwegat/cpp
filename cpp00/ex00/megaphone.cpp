/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:45:05 by rwegat            #+#    #+#             */
/*   Updated: 2025/02/26 13:38:20 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void    print_string(char *str)
{
    while (*str)
    {
        if (std::isalpha(*str))
            std::cout << (char)std::toupper(*str);
        else
            std::cout << *str;
        str++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        argv++;
        while (*argv)
        {
            print_string(*argv);
            argv++;
        }
        std::cout << std::endl;
    }
    return (0);
}

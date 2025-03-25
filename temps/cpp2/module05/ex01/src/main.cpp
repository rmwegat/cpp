/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:42:11 by babreton          #+#    #+#             */
/*   Updated: 2023/09/17 13:25:47 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int	main() {
	Bureaucrat *	Donald = NULL;
	Bureaucrat *	Joe = NULL;
	Form *			simpleDoc = NULL;

	try {
		Donald = new Bureaucrat("Donald", 55);
		Joe = new Bureaucrat("Joe", 35);
		simpleDoc = new Form("Simple Document", 50);
		simpleDoc->beSigned(*Donald);
		simpleDoc->beSigned(*Joe);
		Donald->promote();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << *simpleDoc << std::endl;
	delete Donald;
	delete Joe;
	delete simpleDoc;
}
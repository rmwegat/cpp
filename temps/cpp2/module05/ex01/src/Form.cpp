/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:56:51 by babreton          #+#    #+#             */
/*   Updated: 2023/09/18 10:36:08 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructors & operators                          */
/* -------------------------------------------------------------------------- */

Form::Form(str name, int signGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(signGrade - 1) {
	std::cout << "[C] Form base constructor called." << std::endl;
}

Form::Form() : _name(NULL), _signed(false), _signGrade(150), _executeGrade(150) {
	std::cout << "[C] Form default constructor called." << std::endl;
}

Form::Form(Form const &src) : _name(src.getName()), _signGrade(src.getSignGrade()), _executeGrade(src.getExecuteGrade()) {
	std::cout << "[C] Form copy constructor called." << std::endl;
	*this = src;
}

Form::~Form() {
	std::cout << "[D] Form default destructor called." << std::endl;
}

Form &	Form::operator=(Form const &rSym) {
	if (this != &rSym) {
		this->_signed = rSym.getSigned();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Form const &rSym) {
	o << "Form name : " << rSym.getName() << std::endl;
	o << "Signed : ";
	if (rSym.getSigned())
		o << "True" << std::endl;
	else
		o << "False" << std::endl;
	o << "Need to be grade " << rSym.getSignGrade() << " to sign it, and grade " << rSym.getExecuteGrade() << " to execute it.";
	return o;
}

/* -------------------------------------------------------------------------- */
/*                              Geteurs & seteurs                             */
/* -------------------------------------------------------------------------- */

str		Form::getName() const {
	return this->_name;
}

bool	Form::getSigned() const {
	return this->_signed;
}

int		Form::getSignGrade() const {
	return this->_signGrade;
}

int		Form::getExecuteGrade() const {
	return this->_executeGrade;
}

/* -------------------------------------------------------------------------- */
/*                              Members functions                             */
/* -------------------------------------------------------------------------- */

void			Form::beSigned(Bureaucrat &person) {
	if (this->_signed) {
		std::cout << this->_name << " is already signed." << std::endl; 
		return;
	}
	if (person.getGrade() > this->_signGrade) {
		person.signForm(this->_name, this->_signed);
		throw Form::GradeTooLowException();
	}
	else {
		this->_signed = true;
		person.signForm(this->_name, this->_signed);
	}
}

const char *	Form::GradeTooHighException::what() const throw() {
	return ("The bureaucrat is too senior to do this.");
}

const char *	Form::GradeTooLowException::what() const throw() {
	return ("The bureaucrat don't have the ability to do this.");
}
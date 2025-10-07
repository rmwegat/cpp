#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define COLOR_RESET   "\033[0m"
#define COLOR_YELLOW  "\033[33m"

int main() {
    std::cout << COLOR_YELLOW << "=== AForm Testing ===" << COLOR_RESET << std::endl;

    try {
        std::cout << COLOR_YELLOW << "\n1. Form Creation and Signing:" << COLOR_RESET << std::endl;
        Bureaucrat highLevel("Boss", 1);
        ShrubberyCreationForm shrub("garden");
        
        std::cout << highLevel << std::endl;
        std::cout << shrub << std::endl;
        highLevel.signForm(shrub);

        std::cout << COLOR_YELLOW << "\n2. Form Execution - Shrubbery:" << COLOR_RESET << std::endl;
        highLevel.executeForm(shrub);

        std::cout << COLOR_YELLOW << "\n3. Form Execution - Robotomy:" << COLOR_RESET << std::endl;
        RobotomyRequestForm robot("Bender");
        highLevel.signForm(robot);
        highLevel.executeForm(robot);

        std::cout << COLOR_YELLOW << "\n4. Form Execution - Presidential Pardon:" << COLOR_RESET << std::endl;
        PresidentialPardonForm pardon("Arthur");
        highLevel.signForm(pardon);
        highLevel.executeForm(pardon);

        std::cout << COLOR_YELLOW << "\n5. Error Handling - Invalid Grade:" << COLOR_RESET << std::endl;
        Bureaucrat invalidBureaucrat("Invalid", 0);

    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << COLOR_YELLOW << "\n6. Error Handling - Unsigned Form:" << COLOR_RESET << std::endl;
        ShrubberyCreationForm unsignedTest("unsigned");
        Bureaucrat lowLevel("LowLevel", 150);
        lowLevel.executeForm(unsignedTest);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

#define COLOR_RESET   "\033[0m"
#define COLOR_YELLOW  "\033[33m"

int main() {
    std::cout << COLOR_YELLOW << "=== Intern Testing ===" << COLOR_RESET << std::endl;

    std::cout << COLOR_YELLOW << "\n1. Creating Intern and Bureaucrat:" << COLOR_RESET << std::endl;
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    std::cout << boss << std::endl;

    std::cout << COLOR_YELLOW << "\n2. Intern creates valid forms:" << COLOR_RESET << std::endl;
    
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur");
    
    if (rrf) {
        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    
    if (scf) {
        std::cout << *scf << std::endl;
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }
    
    if (ppf) {
        std::cout << *ppf << std::endl;
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }

    std::cout << COLOR_YELLOW << "\n3. Intern tries to create invalid form:" << COLOR_RESET << std::endl;
    AForm* invalidForm = someRandomIntern.makeForm("invalid form", "target");
    if (!invalidForm) {
        std::cout << "Invalid form creation returned NULL as expected." << std::endl;
    }

    return 0;
}
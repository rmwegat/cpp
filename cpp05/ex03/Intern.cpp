#include "Intern.hpp"
#include <iostream>

// Initialize the static array of form types
const Intern::FormInfo Intern::formTypes[3] = {
    {"shrubbery creation", &Intern::createShrubberyForm},
    {"robotomy request", &Intern::createRobotomyForm},
    {"presidential pardon", &Intern::createPresidentialForm}
};

// Orthodox Canonical Form
Intern::Intern() {
}

Intern::Intern(const Intern& other) {
    (void)other; // Intern has no attributes to copy
}

Intern& Intern::operator=(const Intern& other) {
    (void)other; // Intern has no attributes to assign
    return *this;
}

Intern::~Intern() {
}

// Form creation methods
AForm* Intern::createShrubberyForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

// Main functionality
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    // Search for the form type
    for (int i = 0; i < 3; i++) {
        if (formTypes[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*(formTypes[i].creator))(target);
        }
    }
    
    // Form not found
    std::cout << "Error: Intern cannot create form '" << formName 
              << "' - unknown form type" << std::endl;
    return NULL;
}

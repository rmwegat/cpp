#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
private:
    // Function pointer type for form creation functions
    typedef AForm* (Intern::*FormCreator)(const std::string& target) const;
    
    // Form creation methods
    AForm* createShrubberyForm(const std::string& target) const;
    AForm* createRobotomyForm(const std::string& target) const;
    AForm* createPresidentialForm(const std::string& target) const;
    
    // Structure to hold form name and creator function
    struct FormInfo {
        std::string name;
        FormCreator creator;
    };
    
    static const FormInfo formTypes[3];

public:
    // Orthodox Canonical Form
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
    
    // Main functionality
    AForm* makeForm(const std::string& formName, const std::string& target) const;
};

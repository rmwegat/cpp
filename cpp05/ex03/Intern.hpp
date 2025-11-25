#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
private:
    typedef AForm* (Intern::*FormCreator)(const std::string& target) const;
    
    AForm* createShrubberyForm(const std::string& target) const;
    AForm* createRobotomyForm(const std::string& target) const;
    AForm* createPresidentialForm(const std::string& target) const;
    
    struct FormInfo {
        std::string name;
        FormCreator creator;
    };
    
    static const FormInfo formTypes[3];

public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
    
    AForm* makeForm(const std::string& formName, const std::string& target) const;
};

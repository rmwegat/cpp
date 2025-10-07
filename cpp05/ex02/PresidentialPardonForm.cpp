#include "PresidentialPardonForm.hpp"

// Orthodox Canonical Form
PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon", GRADE_TO_SIGN, GRADE_TO_EXECUTE), target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("Presidential Pardon", GRADE_TO_SIGN, GRADE_TO_EXECUTE), target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : AForm(other), target(other.target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        // target is const, so it can't be reassigned
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

// Getter
const std::string& PresidentialPardonForm::getTarget() const {
    return target;
}

// Override the pure virtual function
void PresidentialPardonForm::executeAction() const {
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
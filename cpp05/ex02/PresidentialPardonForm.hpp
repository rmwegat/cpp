#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    const std::string target;

    static const int GRADE_TO_SIGN = 25;
    static const int GRADE_TO_EXECUTE = 5;

public:
    // Orthodox Canonical Form
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    virtual ~PresidentialPardonForm();

    // Getter
    const std::string& getTarget() const;

    // Override the pure virtual function
    virtual void executeAction() const override;
};
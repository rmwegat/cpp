#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    const std::string target;

    static const int GRADE_TO_SIGN = 145;
    static const int GRADE_TO_EXECUTE = 137;

public:
    // Orthodox Canonical Form
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();

    // Getter
    const std::string& getTarget() const;

    // Override the pure virtual function
    virtual void executeAction() const override;
};

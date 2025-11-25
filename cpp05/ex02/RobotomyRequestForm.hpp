#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
    const std::string target;

    static const int GRADE_TO_SIGN = 72;
    static const int GRADE_TO_EXECUTE = 45;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();

        const std::string& getTarget() const;

    // Override the pure virtual function
    virtual void executeAction() const override;
};

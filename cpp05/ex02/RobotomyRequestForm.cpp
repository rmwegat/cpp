#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request", GRADE_TO_SIGN, GRADE_TO_EXECUTE), target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy Request", GRADE_TO_SIGN, GRADE_TO_EXECUTE), target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), target(other.target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        // target is const, so it can't be reassigned
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

const std::string& RobotomyRequestForm::getTarget() const {
    return target;
}

// Override the pure virtual function
void RobotomyRequestForm::executeAction() const {
    std::cout << "*** DRILLING NOISES *** BZZZZT! WHIRRRR! CLANK! ***" << std::endl;
    
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << target << "!" << std::endl;
    }
}

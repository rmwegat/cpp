#include "RobotomyRequestForm.hpp"

// Orthodox Canonical Form
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

// Getter
const std::string& RobotomyRequestForm::getTarget() const {
    return target;
}

// Override the pure virtual function
void RobotomyRequestForm::executeAction() const {
    // Make drilling noises
    std::cout << "*** DRILLING NOISES *** BZZZZT! WHIRRRR! CLANK! ***" << std::endl;
    
    // Initialize random seed based on current time
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    // 50% chance of success
    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << target << "!" << std::endl;
    }
}

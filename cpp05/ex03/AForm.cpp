#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const noexcept {
    return "AForm grade is too high (minimum is 1)";
}

const char* AForm::GradeTooLowException::what() const noexcept {
    return "AForm grade is too low (maximum is 150)";
}

const char* AForm::FormNotSignedException::what() const noexcept {
    return "Form is not signed";
}

void AForm::validateGrade(int grade) const {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}


AForm::AForm()
    : name("default"), is_signed(false), grade_to_sign(LOWEST_GRADE), grade_to_execute(LOWEST_GRADE) {}

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute)
    : name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) {
    validateGrade(grade_to_sign);
    validateGrade(grade_to_execute);
}

AForm::AForm(const AForm& other)
    : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        // Only is_signed can be copied, name and grades are const
        is_signed = other.is_signed;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::isSigned() const {
    return is_signed;
}

int AForm::getGradeToSign() const {
    return grade_to_sign;
}

int AForm::getGradeToExecute() const {
    return grade_to_execute;
}


void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > grade_to_sign) {
        throw GradeTooLowException();
    }
    is_signed = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!is_signed) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > grade_to_execute) {
        throw GradeTooLowException();
    }
    executeAction();
}

// Overload insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "AForm: " << form.getName()
       << ", signed: " << (form.isSigned() ? "yes" : "no")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}
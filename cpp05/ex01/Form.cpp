#include "Form.hpp"
#include "Bureaucrat.hpp"

// Exception implementations
const char* Form::GradeTooHighException::what() const noexcept {
    return "Form grade is too high (minimum is 1)";
}

const char* Form::GradeTooLowException::what() const noexcept {
    return "Form grade is too low (maximum is 150)";
}

// Private helper function
void Form::validateGrade(int grade) const {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

// Orthodox Canonical Form
Form::Form() : name("default"), is_signed(false), grade_to_sign(LOWEST_GRADE), grade_to_execute(LOWEST_GRADE) {
}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute) 
    : name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) {
    validateGrade(grade_to_sign);
    validateGrade(grade_to_execute);
}

Form::Form(const Form& other) 
    : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        // Note: name, grade_to_sign, and grade_to_execute are const, so they can't be reassigned
        // Only is_signed can be copied
        is_signed = other.is_signed;
    }
    return *this;
}

Form::~Form() {
}

// Getters
const std::string& Form::getName() const {
    return name;
}

bool Form::isSigned() const {
    return is_signed;
}

int Form::getGradeToSign() const {
    return grade_to_sign;
}

int Form::getGradeToExecute() const {
    return grade_to_execute;
}

// Member functions
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > grade_to_sign) {
        throw GradeTooLowException();
    }
    is_signed = true;
}

// Overload insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() 
       << ", signed: " << (form.isSigned() ? "yes" : "no")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}

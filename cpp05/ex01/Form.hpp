#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool is_signed;
    const int grade_to_sign;
    const int grade_to_execute;

    static const int HIGHEST_GRADE = 1;
    static const int LOWEST_GRADE = 150;

    void validateGrade(int grade) const;

public:
    // Orthodox Canonical Form
    Form();
    Form(const std::string& name, int grade_to_sign, int grade_to_execute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // Getters
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member functions
    void beSigned(const Bureaucrat& bureaucrat);

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const noexcept override;
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const noexcept override;
    };
};

// Overload insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form);

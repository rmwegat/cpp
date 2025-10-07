#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
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
    AForm();
    AForm(const std::string& name, int grade_to_sign, int grade_to_execute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Getters
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member functions
    void beSigned(const Bureaucrat& bureaucrat);
    void execute(const Bureaucrat& executor) const;

    // Pure virtual function to make this an abstract class
    virtual void executeAction() const = 0;

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const noexcept override;
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const noexcept override;
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const noexcept override;
    };
};

// Overload insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& form);

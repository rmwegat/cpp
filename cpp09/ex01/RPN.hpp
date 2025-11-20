#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

class RPN {
private:
    std::stack<double> _operands;
    
    // Helper methods
    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    double performOperation(double a, double b, char op) const;
    void processToken(const std::string& token);
    
public:
    // Constructor
    RPN();
    
    // Copy constructor
    RPN(const RPN& other);
    
    // Assignment operator
    RPN& operator=(const RPN& other);
    
    // Destructor
    ~RPN();
    
    // Main calculation method
    double calculate(const std::string& expression);
    
    // Exception class
    class RPNException : public std::exception {
    private:
        std::string _message;
    public:
        RPNException(const std::string& message) : _message(message) {}
        virtual ~RPNException() throw() {}
        virtual const char* what() const throw() {
            return _message.c_str();
        }
    };
};

#endif
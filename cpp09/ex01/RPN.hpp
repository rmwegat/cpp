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
    
    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    double performOperation(double a, double b, char op) const;
    void processToken(const std::string& token);
    
public:
    RPN();
    
    RPN(const RPN& other);
    
    RPN& operator=(const RPN& other);
    
    ~RPN();
    
    double calculate(const std::string& expression);
    
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
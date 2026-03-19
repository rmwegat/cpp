#include "RPN.hpp"
#include <cstdlib>

RPN::RPN() {
}

RPN::RPN(const RPN& other) : _operands(other._operands) {
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _operands = other._operands;
    }
    return *this;
}

RPN::~RPN() {
}

bool RPN::isOperator(const std::string& token) const {
    return token.length() == 1 && 
           (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

bool RPN::isNumber(const std::string& token) const {
    if (token.empty())
        return false;
    if (token.length() == 1 && token[0] >= '0' && token[0] <= '9') {
        return true;
    }
    return false;
}

double RPN::performOperation(double a, double b, char op) const {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

void RPN::processToken(const std::string& token) {
    if (isNumber(token)) {
        double num = token[0] - '0';
        _operands.push(num);
    }
    else if (isOperator(token)) {
        if (_operands.size() < 2) {
            return;
        }
        
        double b = _operands.top();
        _operands.pop();
        double a = _operands.top();
        _operands.pop();
        
        double result = performOperation(a, b, token[0]);
        _operands.push(result);
    }
}

double RPN::calculate(const std::string& expression) {
    while (!_operands.empty()) {
        _operands.pop();
    }
    
    if (expression.empty()) {
        return 0;
    }
    
    std::istringstream inputStream(expression);
    std::string token;
    
    while (inputStream >> token) {
        processToken(token);
    }
    
    if (_operands.empty()) {
        return 0;
    }
    
    if (_operands.size() != 1) {
        return 0;
    }
    
    return _operands.top();
}
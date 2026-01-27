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
            if (b == 0) {
                throw std::runtime_error("Division by zero");
            }
            return a / b;
        default:
            throw std::runtime_error("Invalid operator");
    }
}

void RPN::processToken(const std::string& token) {
    if (isNumber(token)) {
        double num = token[0] - '0';
        _operands.push(num);
    }
    else if (isOperator(token)) {
        if (_operands.size() < 2) {
            throw std::runtime_error("Insufficient operands for operation");
        }
        
        double b = _operands.top(); _operands.pop();
        double a = _operands.top(); _operands.pop();
        
        double result = performOperation(a, b, token[0]);
        _operands.push(result);
    }
    else {
        throw std::runtime_error("Invalid token: " + token);
    }
}

double RPN::calculate(const std::string& expression) {
    while (!_operands.empty()) {
        _operands.pop();
    }
    
    if (expression.empty()) {
        throw std::runtime_error("Empty expression");
    }
    
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        processToken(token);
    }
    
    if (_operands.empty()) {
        throw std::runtime_error("No result calculated");
    }
    
    if (_operands.size() != 1) {
        throw std::runtime_error("Invalid expression: too many operands");
    }
    
    return _operands.top();
}
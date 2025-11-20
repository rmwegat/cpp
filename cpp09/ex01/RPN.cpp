#include "RPN.hpp"
#include <cstdlib>

// Constructor
RPN::RPN() {
}

// Copy constructor
RPN::RPN(const RPN& other) : _operands(other._operands) {
}

// Assignment operator
RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _operands = other._operands;
    }
    return *this;
}

// Destructor
RPN::~RPN() {
}

// Check if token is an operator
bool RPN::isOperator(const std::string& token) const {
    return token.length() == 1 && 
           (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

// Check if token is a valid single digit number
bool RPN::isNumber(const std::string& token) const {
    if (token.empty()) return false;
    
    // Check for single digit (0-9)
    if (token.length() == 1 && token[0] >= '0' && token[0] <= '9') {
        return true;
    }
    
    return false;
}

// Perform arithmetic operation
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
                throw RPNException("Division by zero");
            }
            return a / b;
        default:
            throw RPNException("Invalid operator");
    }
}

// Process a single token
void RPN::processToken(const std::string& token) {
    if (isNumber(token)) {
        // Convert single digit to number and push to stack
        double num = token[0] - '0';
        _operands.push(num);
    }
    else if (isOperator(token)) {
        // Need at least 2 operands for operation
        if (_operands.size() < 2) {
            throw RPNException("Insufficient operands for operation");
        }
        
        // Pop two operands (note: order matters for - and /)
        double b = _operands.top(); _operands.pop();
        double a = _operands.top(); _operands.pop();
        
        // Perform operation and push result
        double result = performOperation(a, b, token[0]);
        _operands.push(result);
    }
    else {
        throw RPNException("Invalid token: " + token);
    }
}

// Main calculation method
double RPN::calculate(const std::string& expression) {
    // Clear any previous state
    while (!_operands.empty()) {
        _operands.pop();
    }
    
    if (expression.empty()) {
        throw RPNException("Empty expression");
    }
    
    std::istringstream iss(expression);
    std::string token;
    
    // Process each token in the expression
    while (iss >> token) {
        processToken(token);
    }
    
    // Should have exactly one result left
    if (_operands.empty()) {
        throw RPNException("No result calculated");
    }
    
    if (_operands.size() != 1) {
        throw RPNException("Invalid expression: too many operands");
    }
    
    return _operands.top();
}
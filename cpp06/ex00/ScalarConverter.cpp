#include "ScalarConverter.hpp"

// Private constructors/destructor to make class non-instantiable
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& str) {
    return str.length() == 3 && str[0] == '\'' && str[2] == '\'';
}

bool ScalarConverter::isInt(const std::string& str) {
    if (str.empty()) return false;
    
    size_t start = 0;
    if (str[0] == '+' || str[0] == '-') start = 1;
    if (start >= str.length()) return false;
    
    for (size_t i = start; i < str.length(); i++) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
    if (str.empty() || str.back() != 'f') return false;
    
    std::string withoutF = str.substr(0, str.length() - 1);
    if (withoutF.empty()) return false;
    
    size_t start = 0;
    if (withoutF[0] == '+' || withoutF[0] == '-') start = 1;
    if (start >= withoutF.length()) return false;
    
    bool hasDot = false;
    for (size_t i = start; i < withoutF.length(); i++) {
        if (withoutF[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(withoutF[i])) {
            return false;
        }
    }
    return hasDot;
}

bool ScalarConverter::isDouble(const std::string& str) {
    if (str.empty()) return false;
    
    size_t start = 0;
    if (str[0] == '+' || str[0] == '-') start = 1;
    if (start >= str.length()) return false;
    
    bool hasDot = false;
    for (size_t i = start; i < str.length(); i++) {
        if (str[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return hasDot;
}

bool ScalarConverter::isPseudoLiteral(const std::string& str) {
    return str == "-inff" || str == "+inff" || str == "nanf" ||
           str == "-inf" || str == "+inf" || str == "nan";
}

// Conversion methods
void ScalarConverter::convertFromChar(char c) {
    double value = static_cast<double>(c);
    
    std::cout << "char: '" << c << "'" << std::endl;
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::convertFromInt(int value) {
    double doubleValue = static_cast<double>(value);
    
    printChar(doubleValue);
    std::cout << "int: " << value << std::endl;
    printFloat(doubleValue);
    printDouble(doubleValue);
}

void ScalarConverter::convertFromFloat(float value) {
    double doubleValue = static_cast<double>(value);
    
    printChar(doubleValue);
    printInt(doubleValue);
    std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
    printDouble(doubleValue);
}

void ScalarConverter::convertFromDouble(double value) {
    printChar(value);
    printInt(value);
    printFloat(value);
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::handlePseudoLiteral(const std::string& str) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (str == "-inff" || str == "+inff" || str == "nanf") {
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
    } else {
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
    }
}

void ScalarConverter::printChar(double value, bool impossible) {
    if (impossible || std::isnan(value) || std::isinf(value) || 
        value < 0 || value > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (value < 32 || value == 127) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double value, bool impossible) {
    if (impossible || std::isnan(value) || std::isinf(value) ||
        value < std::numeric_limits<int>::min() || 
        value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::printFloat(double value, bool isPseudo, const std::string& pseudoStr) {
    if (isPseudo) {
        std::cout << "float: " << pseudoStr << std::endl;
    } else if (std::isnan(value)) {
        std::cout << "float: nanf" << std::endl;
    } else if (std::isinf(value)) {
        if (value > 0) {
            std::cout << "float: +inff" << std::endl;
        } else {
            std::cout << "float: -inff" << std::endl;
        }
    } else {
        float floatVal = static_cast<float>(value);
        std::cout << "float: " << std::fixed << std::setprecision(1) << floatVal << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value, bool isPseudo, const std::string& pseudoStr) {
    if (isPseudo) {
        std::cout << "double: " << pseudoStr << std::endl;
    } else if (std::isnan(value)) {
        std::cout << "double: nan" << std::endl;
    } else if (std::isinf(value)) {
        if (value > 0) {
            std::cout << "double: +inf" << std::endl;
        } else {
            std::cout << "double: -inf" << std::endl;
        }
    } else {
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    }
}

void ScalarConverter::convert(const std::string& str) {
    if (str.empty()) {
        std::cout << "Error: Empty string" << std::endl;
        return;
    }
    
    // Handle pseudo-literals first
    if (isPseudoLiteral(str)) {
        handlePseudoLiteral(str);
        return;
    }
    
    // Handle char
    if (isChar(str)) {
        convertFromChar(str[1]);
        return;
    }
    
    // Handle int
    if (isInt(str)) {
        try {
            long long value = std::strtoll(str.c_str(), NULL, 10);
            if (value < std::numeric_limits<int>::min() || 
                value > std::numeric_limits<int>::max()) {
                throw std::out_of_range("Integer overflow");
            }
            convertFromInt(static_cast<int>(value));
            return;
        } catch (...) {
            std::cout << "Error: Invalid integer" << std::endl;
            return;
        }
    }
    
    // float
    if (isFloat(str)) {
        try {
            float value = std::strtof(str.c_str(), NULL);
            convertFromFloat(value);
            return;
        } catch (...) {
            std::cout << "Error: Invalid float" << std::endl;
            return;
        }
    }
    
    // double
    if (isDouble(str)) {
        try {
            double value = std::strtod(str.c_str(), NULL);
            convertFromDouble(value);
            return;
        } catch (...) {
            std::cout << "Error: Invalid double" << std::endl;
            return;
        }
    }
    
    std::cout << "Error: Invalid literal format" << std::endl;
}
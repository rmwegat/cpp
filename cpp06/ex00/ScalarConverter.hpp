#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static bool isChar(const std::string& str);
    static bool isInt(const std::string& str);
    static bool isFloat(const std::string& str);
    static bool isDouble(const std::string& str);
    static bool isPseudoLiteral(const std::string& str);

    static void convertFromChar(char c);
    static void convertFromInt(int value);
    static void convertFromFloat(float value);
    static void convertFromDouble(double value);
    static void handlePseudoLiteral(const std::string& str);

    static void printChar(double value, bool impossible = false);
    static void printInt(double value, bool impossible = false);
    static void printFloat(double value, bool isPseudo = false, const std::string& pseudoStr = "");
    static void printDouble(double value, bool isPseudo = false, const std::string& pseudoStr = "");

public:
    static void convert(const std::string& str);
};
#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstdlib>

// Constructor
BitcoinExchange::BitcoinExchange() {
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _exchangeRates(other._exchangeRates) {
}

// Assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {
}

// Helper method to trim whitespace
void BitcoinExchange::trimString(std::string& str) const {
    // Remove leading whitespace
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    // Remove trailing whitespace
    str.erase(std::find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
}

// Validate date format (YYYY-MM-DD)
bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    // Check if all other characters are digits
    for (size_t i = 0; i < date.length(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) return false;
    }
    
    // Extract year, month, day
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    // Basic validation
    if (year < 2009 || year > 2025) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    // Simple day validation (not perfect but sufficient)
    if (month == 2 && day > 29) return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    
    return true;
}

// Validate value (0 to 1000)
bool BitcoinExchange::isValidValue(float value) const {
    return value >= 0 && value <= 1000;
}

// Parse value from string
float BitcoinExchange::parseValue(const std::string& valueStr) const {
    std::string trimmed = valueStr;
    trimString(trimmed);
    
    // Check for empty string
    if (trimmed.empty()) {
        throw std::invalid_argument("empty value");
    }
    
    // Check for valid number format
    char* endptr;
    float value = std::strtof(trimmed.c_str(), &endptr);
    
    if (*endptr != '\0') {
        throw std::invalid_argument("invalid number format");
    }
    
    return value;
}

// Find closest date (lower or equal)
std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    // Find the largest date that is <= input date
    std::map<std::string, float>::const_iterator it = _exchangeRates.upper_bound(date);
    
    if (it == _exchangeRates.begin()) {
        throw DatabaseException("No earlier date found in database");
    }
    
    --it;
    return it->first;
}

// Load database from CSV file
void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw FileException("Could not open database file: " + filename);
    }
    
    std::string line;
    bool isFirstLine = true;
    
    while (std::getline(file, line)) {
        // Skip header line
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }
        
        // Parse CSV line
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos) {
            continue; // Skip malformed lines
        }
        
        std::string date = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);
        
        trimString(date);
        trimString(rateStr);
        
        try {
            float rate = parseValue(rateStr);
            _exchangeRates[date] = rate;
        } catch (const std::exception&) {
            // Skip invalid entries
            continue;
        }
    }
    
    file.close();
    
    if (_exchangeRates.empty()) {
        throw DatabaseException("No valid data found in database");
    }
}

// Get exchange rate for specific date
float BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.find(date);
    if (it != _exchangeRates.end()) {
        return it->second;
    }
    
    // Find closest lower date
    std::string closestDate = findClosestDate(date);
    it = _exchangeRates.find(closestDate);
    return it->second;
}

// Process input file
void BitcoinExchange::processInput(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw FileException("Error: could not open file.");
    }
    
    std::string line;
    bool isFirstLine = true;
    
    while (std::getline(file, line)) {
        // Skip header line
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }
        
        // Parse input line (format: "date | value")
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);
        
        trimString(date);
        trimString(valueStr);
        
        // Validate date
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        // Parse and validate value
        try {
            float value = parseValue(valueStr);
            
            if (value < 0) {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            
            if (!isValidValue(value)) {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            
            // Get exchange rate and calculate result
            try {
                float rate = getExchangeRate(date);
                float result = value * rate;
                
                std::cout << date << " => " << value << " = " << result << std::endl;
            } catch (const DatabaseException& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            
        } catch (const std::exception&) {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
    
    file.close();
}
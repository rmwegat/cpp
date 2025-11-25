#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

class BitcoinExchange {
private:
    std::map<std::string, float> _exchangeRates;
    
    // Helper methods
    bool isValidDate(const std::string& date) const;
    bool isValidValue(float value) const;
    float parseValue(const std::string& valueStr) const;
    std::string findClosestDate(const std::string& date) const;
    void trimString(std::string& str) const;
    
public:
    BitcoinExchange();
    
    BitcoinExchange(const BitcoinExchange& other);
    
    BitcoinExchange& operator=(const BitcoinExchange& other);
    
    ~BitcoinExchange();
    
    void loadDatabase(const std::string& filename);
    
    void processInput(const std::string& filename) const;
    
    float getExchangeRate(const std::string& date) const;
    
    class DatabaseException : public std::exception {
    private:
        std::string _message;
    public:
        DatabaseException(const std::string& message) : _message(message) {}
        virtual ~DatabaseException() throw() {}
        virtual const char* what() const throw() {
            return _message.c_str();
        }
    };
    
    class FileException : public std::exception {
    private:
        std::string _message;
    public:
        FileException(const std::string& message) : _message(message) {}
        virtual ~FileException() throw() {}
        virtual const char* what() const throw() {
            return _message.c_str();
        }
    };
};

#endif
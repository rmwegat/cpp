#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange exchange;
        exchange.loadDatabase("data.csv");
        }
        exchange.processInput(argv[1]);

    catch (const BitcoinExchange::FileException& e) {
        std::cout << e.what() << std::endl;
        return 1;
    } catch (const BitcoinExchange::DatabaseException& e) {
        std::cout << "Database error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
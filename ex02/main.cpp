/* ************************************************************************** */
/*                                                                            */
/*    Ford-Johnson Merge-Insert Sort Algorithm Implementation                 */
/*    Exercise 02 - CPP Module 09                                            */
/*                                                                            */
/*    Objective: Implement the Ford-Johnson algorithm to sort positive       */
/*    integers using two different STL containers (vector and deque)         */
/*    and compare their performance.                                         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    
    // Input validation
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [positive integers]" << std::endl;
        std::cerr << "Example: " << argv[0] << " 3 5 9 7 4" << std::endl;
        return 1;
    }
    
    try {
        // Create PmergeMe instance and sort
        PmergeMe sorter;
        sorter.sort(argc, argv);
        
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

/* 
 * Expected Output Format:
 * Before: 3 5 9 7 4
 * After:  3 4 5 7 9
 * Time to process a range of 5 elements with std::vector : 0.00031 us
 * Time to process a range of 5 elements with std::deque : 0.00014 us
 * 
 * Algorithm Overview (Ford-Johnson):
 * 1. Group elements into pairs
 * 2. Sort each pair (smaller first)  
 * 3. Recursively sort the larger elements
 * 4. Insert smaller elements using optimal insertion sequence
 * 
 * Key Benefits:
 * - Minimizes comparisons for small datasets
 * - Mathematically optimal for small inputs
 * - Good demonstration of STL container performance differences
 */
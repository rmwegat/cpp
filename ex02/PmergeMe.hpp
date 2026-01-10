#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <sstream>
#include <algorithm>

class PmergeMe
{
private:
    std::vector<int> _vectorContainer;
    std::deque<int> _dequeContainer;
    
    // Ford-Johnson merge-insert sort for vector
    void _sortVector();
    std::vector<int> _mergeInsertSortVector(std::vector<int> &arr);
    
    // Ford-Johnson merge-insert sort for deque  
    void _sortDeque();
    std::deque<int> _mergeInsertSortDeque(std::deque<int> &arr);
    
    // Helper functions
    bool _isValidInput(const std::string &input);
    void _parseInput(int argc, char **argv);
    void _displayResults();
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();
    
    // Main sorting function
    void sort(int argc, char **argv);
};

#endif

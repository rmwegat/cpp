#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // Constructor
    Span(unsigned int N);
    
    // Copy constructor
    Span(const Span& other);
    
    // Assignment operator
    Span& operator=(const Span& other);
    
    // Destructor
    ~Span();
    
    // Add a single number
    void addNumber(int number);
    
    // Add multiple numbers using iterators
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end);
    
    // Find shortest span
    unsigned int shortestSpan() const;
    
    // Find longest span
    unsigned int longestSpan() const;
    
    // Utility functions
    unsigned int size() const;
    unsigned int maxSize() const;
    bool isFull() const;
    
    // Exception classes
    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Span is already full";
        }
    };
    
    class NoSpanFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "No span can be found (need at least 2 numbers)";
        }
    };
};

// Template function implementation (must be in header)
template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    // Calculate how many elements we're trying to add
    typename std::iterator_traits<Iterator>::difference_type distance = std::distance(begin, end);
    
    // Check if we have enough space
    if (_numbers.size() + static_cast<unsigned int>(distance) > _maxSize) {
        throw SpanFullException();
    }
    
    // Add the elements
    _numbers.insert(_numbers.end(), begin, end);
}

#endif
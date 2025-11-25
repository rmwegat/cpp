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
    Span(unsigned int N);
    
    Span(const Span& other);
    
    Span& operator=(const Span& other);
    
    ~Span();
    
    void addNumber(int number);
    
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end);
    
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    
    unsigned int size() const;
    unsigned int maxSize() const;
    bool isFull() const;
    
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

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    typename std::iterator_traits<Iterator>::difference_type distance = std::distance(begin, end);
    if (_numbers.size() + static_cast<unsigned int>(distance) > _maxSize) {
        throw SpanFullException();
    }
    _numbers.insert(_numbers.end(), begin, end);
}

#endif
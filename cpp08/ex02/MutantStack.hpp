#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Default constructor
    MutantStack() : std::stack<T>() {}
    
    // Copy constructor
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    
    // Assignment operator
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }
    
    // Destructor
    ~MutantStack() {}
    
    // Iterator type definitions
    // std::stack uses std::deque as default underlying container
    // We access the protected member 'c' which is the underlying container
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    
    // Iterator functions
    iterator begin() {
        return std::stack<T>::c.begin();
    }
    
    iterator end() {
        return std::stack<T>::c.end();
    }
    
    const_iterator begin() const {
        return std::stack<T>::c.begin();
    }
    
    const_iterator end() const {
        return std::stack<T>::c.end();
    }
    
    // Reverse iterators (optional but useful)
    reverse_iterator rbegin() {
        return std::stack<T>::c.rbegin();
    }
    
    reverse_iterator rend() {
        return std::stack<T>::c.rend();
    }
    
    const_reverse_iterator rbegin() const {
        return std::stack<T>::c.rbegin();
    }
    
    const_reverse_iterator rend() const {
        return std::stack<T>::c.rend();
    }
};

#endif
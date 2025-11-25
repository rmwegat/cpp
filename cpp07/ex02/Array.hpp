#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* _elements;
    unsigned int _size;

public:
    Array() : _elements(NULL), _size(0) {
    }
    
    Array(unsigned int n) : _elements(NULL), _size(n) {
        if (n > 0) {
            _elements = new T[n]();  // () ensures default initialization
        }
    }
    
    // Copy constructor: Deep copy
    Array(const Array& other) : _elements(NULL), _size(other._size) {
        if (_size > 0) {
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _elements[i] = other._elements[i];
            }
        }
    }
    
    Array& operator=(const Array& other) {
        if (this != &other) {
            // Clean up current resources
            delete[] _elements;
            
            // Copy new data
            _size = other._size;
            if (_size > 0) {
                _elements = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    _elements[i] = other._elements[i];
                }
            } else {
                _elements = NULL;
            }
        }
        return *this;
    }
    
    ~Array() {
        delete[] _elements;
    }
    
    // Subscript operator for non-const objects
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }
    
    // Subscript operator for const objects
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }
    
    // Size function: returns number of elements
    unsigned int size() const {
        return _size;
    }
};

#endif
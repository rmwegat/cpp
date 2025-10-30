#ifndef ITER_HPP
#define ITER_HPP

// Template function iter that takes an array address, length, and function
// Works with both const and non-const arrays
template <typename T, typename F>
void iter(T* array, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

// Overload for const arrays
template <typename T, typename F>
void iter(const T* array, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

#endif
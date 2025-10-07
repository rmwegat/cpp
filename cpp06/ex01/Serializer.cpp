#include "Serializer.hpp"

// Static method to serialize a Data pointer to uintptr_t
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

// Static method to deserialize uintptr_t back to Data pointer
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
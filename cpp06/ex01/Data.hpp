#pragma once

#include <string>

struct Data {
    int id;
    std::string name;
    double value;
    bool active;
    
    Data(int id, const std::string& name, double value, bool active)
        : id(id), name(name), value(value), active(active) {}
    
    // Default constructor
    Data() : id(0), name(""), value(0.0), active(false) {}
};

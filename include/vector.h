#pragma once

#include <vector>
#include <string>
#include <iostream>

class Vector {
public:
    Vector();
    Vector(std::initializer_list<float> list);

    Vector operator+(const Vector& other) const;
    void print() const;
    float operator[](size_t index) const;
    size_t size() const;

    std::vector<std::string> split(const std::string& input, const std::string& delimiter) const;

private:
    std::vector<float> data;
};

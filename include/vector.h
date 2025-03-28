#pragma once

#include <vector>
#include <iostream>
#include <initializer_list>

template<typename T>
class Vector {
public:
    Vector();
    Vector(std::initializer_list<T> list);

    Vector<T> operator+(const Vector<T>& other) const;
    void print() const;
    T operator[](size_t index) const;
    size_t size() const;

private:
    std::vector<T> data;
};

// Explicit template declarations
extern template class Vector<float>;
extern template class Vector<double>;

#include "../include/vector.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>

Vector::Vector() = default;

Vector::Vector(std::initializer_list<float> list) : data(list) {}

Vector Vector::operator+(const Vector& other) const {
    Vector result;
    size_t size = std::min(data.size(), other.data.size());
    for (size_t i = 0; i < size; ++i) {
        result.data.push_back(data[i] + other.data[i]);
    }
    return result;
}

void Vector::print() const {
    for (const auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

float Vector::operator[](size_t index) const {
    return data.at(index);
}

size_t Vector::size() const {
    return data.size();
}

std::vector<std::string> Vector::split(const std::string& input, const std::string& delimiter) const {
    std::vector<std::string> result;
    boost::split(result, input, boost::is_any_of(delimiter));
    return result;
}

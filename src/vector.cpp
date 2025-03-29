#include "../include/vector.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>

// Template definitions
template<typename T>
Vector<T>::Vector() = default;

template<typename T>
Vector<T>::Vector(std::initializer_list<T> list) : data(list) {}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const {
    Vector<T> result;
    size_t size = std::min(data.size(), other.data.size());
    for (size_t i = 0; i < size; ++i) {
        result.data.push_back(data[i] + other.data[i]);
    }
    return result;
}

template<typename T>
void Vector<T>::print() const {
    for (const auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

template<typename T>
T Vector<T>::operator[](size_t index) const {
    return data.at(index);
}

template<typename T>
size_t Vector<T>::size() const {
    return data.size();
}

template<typename T>
std::vector<std::string> Vector<T>::split(const std::string& input, const std::string& delimiter) {
    std::vector<std::string> result;
    // boost::split(result, input, boost::is_any_of(delimiter));
    return result;
}

// Explicit template instantiations
template class Vector<float>;
template class Vector<double>;

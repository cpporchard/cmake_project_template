#include "../include/vector.h"
#include <cassert>

int main() {
    Vector<float> v1 = {1.0f, 2.0f, 3.0f};
    Vector<float> v2 = {4.0f, 5.0f, 6.0f};

    Vector<float> v3 = v1 + v2;

    assert(v3.size() == 3);
    assert(v3[0] == 5.0f);
    assert(v3[1] == 7.0f);
    assert(v3[2] == 9.0f);

    Vector<double> d1 = {1.0, 2.0};
    Vector<double> d2 = {3.0, 4.0};
    Vector<double> d3 = d1 + d2;

    assert(d3.size() == 2);
    assert(d3[0] == 4.0);
    assert(d3[1] == 6.0);

    std::cout << "All tests passed.\n";
    return 0;
}

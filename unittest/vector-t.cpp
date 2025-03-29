#include "../include/vector.h"
#include <gtest/gtest.h>

TEST(VectorFloatTest, BasicAddition) {
    Vector<float> v1 = {1.0f, 2.0f, 3.0f};
    Vector<float> v2 = {4.0f, 5.0f, 6.0f};
    Vector<float> v3 = v1 + v2;

    ASSERT_EQ(v3.size(), 3);
    EXPECT_FLOAT_EQ(v3[0], 5.0f);
    EXPECT_FLOAT_EQ(v3[1], 7.0f);
    EXPECT_FLOAT_EQ(v3[2], 9.0f);
}

TEST(VectorSplitTest, CommaSeparatedValues) {
    std::vector<std::string> expected = {"apple", "banana", "grape"};
    auto result = Vector<int>::split("apple,banana,grape", ",");

    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(result[i], expected[i]);
    }
}
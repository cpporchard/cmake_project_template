#include "../include/vector.h"
#include <gtest/gtest.h>

TEST(VectorFloatTest, BasicAddition) {
    Vector v1 = {1.0f, 2.0f, 3.0f};
    Vector v2 = {4.0f, 5.0f, 6.0f};
    Vector v3 = v1 + v2;

    ASSERT_EQ(v3.size(), 3);
    EXPECT_FLOAT_EQ(v3[0], 5.0f);
    EXPECT_FLOAT_EQ(v3[1], 7.0f);
    EXPECT_FLOAT_EQ(v3[2], 9.0f);
}


TEST(VectorTest, SplitString) {
    Vector v;
    std::string input = "one,two,three";
    std::string delim = ",";

    auto result = v.split(input, delim);
    std::vector<std::string> expected = {"one", "two", "three"};

    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(result[i], expected[i]);
    }
}

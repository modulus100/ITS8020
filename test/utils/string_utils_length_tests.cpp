#include <gtest/gtest.h>

extern "C" {
#include "utils/string_utils.h"
}

//TEST(utils, add) {
//    // Arrange
//    double res;
//    // Act
//    res = add_numbers(1.0, 2.0);
//    // Assert
//    ASSERT_NEAR(res, 3.0, 1.0e-11);
//}

class Environment : public ::testing::Environment {
public:
    ~Environment() override = default;

    void SetUp() override {}


    void TearDown() override {}
};

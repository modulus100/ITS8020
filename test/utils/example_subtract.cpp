#include <gtest/gtest.h>

extern "C" {
#include "utils/example.h"
}

TEST(utils, subtract) {
    // Arrange
    double res;
    // Act
    res = subtract_numbers(1.0, 2.0);
    // Assert
    ASSERT_NEAR(res, -1.0, 1.0e-11);
}

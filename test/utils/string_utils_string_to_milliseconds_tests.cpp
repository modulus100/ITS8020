#include <gtest/gtest.h>

extern "C" {
#include "utils/string_utils.h"
}

TEST(utils, string_to_milliseconds_returns_valid_long) {
    // Arrange
    const char *str = "1";

    // Act
    long expected_long = string_to_milliseconds(str);

    // Assert
    ASSERT_EQ(expected_long, 1000);
}

TEST(utils, string_to_milliseconds_returns_valid_long_for_complex_string) {
    // Arrange
    const char *str = "2 ndfs";

    // Act
    long expected_long = string_to_milliseconds(str);

    // Assert
    ASSERT_EQ(expected_long, 2000);
}

TEST(utils, string_to_milliseconds_returns_zero_if_no_integer) {
    // Arrange
    const char *str = "ndfs";

    // Act
    long expected_long = string_to_milliseconds(str);

    // Assert
    ASSERT_EQ(expected_long, 0);
}
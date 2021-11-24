#include <gtest/gtest.h>

extern "C" {
#include "utils/string_utils.h"
}

TEST(utils, length_returns_valid_length_for_many) {
    // Arrange
    char **strings = new char*[2];

    strings[0] = (char*)"Hello";
    strings[1] = (char*)"World";

    // Act
    int expected_length = length(strings);

    // Assert
    ASSERT_EQ(expected_length, 11);
}


TEST(utils, length_returns_one_for_empty_array) {
    // Arrange
    char **strings = new char*[0];

    // Act
    int expected_length = length(strings);

    // Assert
    ASSERT_EQ(expected_length, 1);
}

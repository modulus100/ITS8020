#include <gtest/gtest.h>

extern "C" {
#include "utils/watch_utils.h"
}

TEST(utils, contains_short_version_returs_true) {
    // Arrange
    char const *short_version = "-v";
    char const *actual_version = "-v";
    char const *long_version = "";

    // Act
    int contains = contains_argument(short_version, long_version, actual_version);

    // Assert
    ASSERT_TRUE(contains);
}

TEST(utils, contains_long_version_returns_true) {
    // Arrange
    char const *short_version = "";
    char const *actual_version = "--version";
    char const *long_version = "--version";

    // Act
    int contains = contains_argument(short_version, long_version, actual_version);

    // Assert
    ASSERT_TRUE(contains);
}

TEST(utils, contains_long_no_arguments_returns_false) {
    // Arrange
    char const *short_version = "";
    char const *actual_version = " ";
    char const *long_version = "";

    // Act
    int contains = contains_argument(short_version, long_version, actual_version);

    // Assert
    ASSERT_FALSE(contains);
}
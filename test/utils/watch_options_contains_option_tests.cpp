#include <gtest/gtest.h>

extern "C" {
#include "utils/watch_options.h"
}

TEST(utils, contains_short_version) {
    // Arrange
    char const *short_version = "-v";
    char const *actual_option = "-v";
    char const *long_option = "";

    // Act
    int contains = contains_option(short_version, long_option, actual_option);

    // Assert
    ASSERT_TRUE(contains);
}

TEST(utils, contains_long_version) {
    // Arrange
    char const *short_version = "";
    char const *actual_option = "--version";
    char const *long_option = "--version";

    // Act
    int contains = contains_option(short_version, long_option, actual_option);

    // Assert
    ASSERT_TRUE(contains);
}

TEST(utils, no_options) {
    // Arrange
    char const *short_version = "";
    char const *actual_option = " ";
    char const *long_option = "";

    // Act
    int contains = contains_option(short_version, long_option, actual_option);

    // Assert
    ASSERT_FALSE(contains);
}
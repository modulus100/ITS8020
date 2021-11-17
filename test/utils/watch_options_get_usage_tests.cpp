#include <gtest/gtest.h>
#include <cstring>

extern "C" {
#include "utils/watch_options.h"
}

TEST(utils, get_valid_usage) {
    // Arrange
    const char *usage;
    // Act
    usage = get_usage();
    // Assert
    ASSERT_TRUE(strlen(usage) > 0);
}
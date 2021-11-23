#include <gtest/gtest.h>
#include <cstring>

extern "C" {
#include "utils/watch_utils.h"
}

TEST(utils, get_usage_returns_usage_info) {
    // Arrange
    const char *usage;
    // Act
    usage = get_usage();
    // Assert
    ASSERT_TRUE(strlen(usage) > 0);
}
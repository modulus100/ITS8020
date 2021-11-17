#include <gtest/gtest.h>

extern "C" {
#include "utils/example.h"
}

TEST(utils, add) {
  double res;
  res = add_numbers(1.0, 2.0);
  ASSERT_NEAR(res, 3.0, 1.0e-11);
}

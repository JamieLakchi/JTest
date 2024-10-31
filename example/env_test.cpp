#include "env.h"

JTEST(ENV, access) {
  EXPECT_EQ(numbers[0], 1);
  EXPECT_EQ(numbers[1], 2);
  EXPECT_EQ(numbers[2], 3);
}

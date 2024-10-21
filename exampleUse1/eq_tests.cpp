#include "../JTest.h"

JTEST(addition) {
  auto additionfunc = [](const int i1, const int i2) { return i1 + i2; };

  EXPECT_EQ(additionfunc(1, 1), 2);
  EXPECT_EQ(additionfunc(1, 2), 3);
  EXPECT_EQ(additionfunc(5, -2), 3);
  EXPECT_EQ(additionfunc(-2, 0), -2);
}

JTEST(multiply) {
  auto multfunc = [](const int i1, const int i2) { return i1 * i2; };

  EXPECT_EQ(multfunc(1, 1), -1);
  EXPECT_EQ(multfunc(1, 2), -1);
  EXPECT_EQ(multfunc(5, -2), -1);
  EXPECT_EQ(multfunc(-2, 0), -1);
}

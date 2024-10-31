#include "../JTest.h"

JTESTENV(EQ) {
  SETUP{};
  TEARDOWN{};
  int additionfunc(const int i1, const int i2) { return i1 + i2; }
  int multfunc(const int i1, const int i2) { return i1 * i2; }
};

JTEST(EQ, addition) {
  EXPECT_EQ(additionfunc(1, 2), 3);
  EXPECT_EQ(additionfunc(5, -2), 3);
  EXPECT_EQ(additionfunc(-2, 0), -2);
}

JTEST(EQ, multiply) {
  EXPECT_EQ(multfunc(1, 1), -1);
  EXPECT_EQ(multfunc(1, 2), -1);
  EXPECT_EQ(multfunc(5, -2), -1);
  EXPECT_EQ(multfunc(-2, 0), -1);
}

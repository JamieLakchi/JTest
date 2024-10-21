#include "../JTest.h"

JTEST(errtypepass) {
  auto thrower = []() { throw 5; };
  EXPECT_ERRORTYPE(int, thrower());
}

JTEST(errtypefail1) {
  auto thrower = []() { throw 5; };
  EXPECT_ERRORTYPE(double, thrower());
}

JTEST(errtypefail2) {
  auto notthrower = []() {};
  EXPECT_ERRORTYPE(int, notthrower());
}

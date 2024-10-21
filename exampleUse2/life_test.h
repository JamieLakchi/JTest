#include "../JTest.h"

JTEST(lifepass) {
  auto notthrower = []() {};
  EXPECT_LIFE(notthrower());
}

JTEST(lifefail) {
  auto thrower = []() { throw 5; };
  EXPECT_LIFE(thrower());
}

#include "../JTest.h"

JTEST(deathpass) {
  auto thrower = []() { throw 5; };
  EXPECT_DEATH(thrower());
}

JTEST(deathfail) {
  auto notthrower = []() {};
  EXPECT_DEATH(notthrower());
}

#include "../JTest.h"

JTESTENV(ERRTYPE) {
  SETUP{};
  TEARDOWN{};
  void thrower() { throw 5; }
  void notthrower() {}
};

JTEST(ERRTYPE, errtypepass) { EXPECT_ERRORTYPE(int, thrower()); }

JTEST(ERRTYPE, errtypefail1) { EXPECT_ERRORTYPE(double, thrower()); }

JTEST(ERRTYPE, errtypefail2) { EXPECT_ERRORTYPE(int, notthrower()); }

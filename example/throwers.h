#include "../JTest.h"

JTESTENV(THROWER) {
  SETUP{};
  TEARDOWN{};

public:
  void thrower() { throw 5; }
  void notthrower() {}
};

#include "throwers.h"

JTEST(THROWER, deathpass) { EXPECT_DEATH(thrower()); }

JTEST(THROWER, deathfail) { EXPECT_DEATH(notthrower()); }

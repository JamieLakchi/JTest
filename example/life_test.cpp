#include "throwers.h"

JTEST(THROWER, lifepass) { EXPECT_LIFE(notthrower()); }

JTEST(THROWER, lifefail) { EXPECT_LIFE(thrower()); }

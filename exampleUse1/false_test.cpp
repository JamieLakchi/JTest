#include "../JTest.h"

JTEST(falsepass) { EXPECT_FALSE(false); }

JTEST(falsefail) { EXPECT_FALSE(true); }

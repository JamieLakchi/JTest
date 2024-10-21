#include "../JTest.h"

JTEST(truepass) { EXPECT_TRUE(true); }

JTEST(truefail) { EXPECT_TRUE(false); }

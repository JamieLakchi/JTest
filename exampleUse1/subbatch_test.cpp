#include "../JTest.h"

JTEST(nosubbatchtest) { EXPECT_TRUE(true); }

JTEST(subbatch1, hassubbatchtest) { EXPECT_TRUE(true); }

JTEST(subbatch2, hassubbatchtest) { EXPECT_TRUE(true); }

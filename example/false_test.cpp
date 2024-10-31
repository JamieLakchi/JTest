#include "../JTest.h"

JTESTENV(EXPFALSE){};

JTEST(EXPFALSE, falsepass) { EXPECT_FALSE(false); }

JTEST(EXPFALSE, falsefail) { EXPECT_FALSE(true); }

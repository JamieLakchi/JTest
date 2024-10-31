#include "../JTest.h"

JTESTENV(EXPTRUE){};

JTEST(EXPTRUE, truepass) { EXPECT_TRUE(true); }

JTEST(EXPTRUE, truefail) { EXPECT_TRUE(false); }

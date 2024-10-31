#include "../JTest.h"

JTESTENV(FLAWED){};

JTEST(FLAWED, flawedtest1) { throw 1; }

JTEST(FLAWED, flawedtest2) { throw "apples"; }

JTEST(FLAWED, flawedtest3) { throw false; }

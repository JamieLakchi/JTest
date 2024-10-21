#include "../JTest.h"

JTEST(flawedtest1) { throw 1; }

JTEST(flawedtest2) { throw "apples"; }

JTEST(flawedtest3) { throw false; }

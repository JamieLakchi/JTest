#include "death_test.h"
#include "eq_tests.h"
#include "errtype_test.h"
#include "false_test.h"
#include "flawed_test.h"
#include "life_test.h"
#include "subbatch_test.h"
#include "true_test.h"

int main(int argc, char *argv[]) {
  TestRegistry::runAllTests();
  return 0;
}

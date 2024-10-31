#include "../JTest.h"

JTESTENV(ENV) {
  SETUP {
    numbers = new int[3];
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
  };
  TEARDOWN { delete[] numbers; };

protected:
  int *numbers;
};

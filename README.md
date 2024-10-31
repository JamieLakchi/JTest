# JTest

This is a small, fast, portable, and lightweight test suite contained entirely within a header file (for C++11 and up).

![](https://github.com/JamieLakchi/JTest/blob/master/JTESTWINDOWSCMD.gif)

## Motivation

I don't like GTest. There's some setup work to do, and you need to remake it if you want to run your tests on a different machine.


## Creating Tests

To create a test, you first need to create the environment the test will be run in, this can be done using the `JTESTENV(_envname){ ... }` macro:

```cpp
// creates an empty environment
JTESTENV(EXPTRUE){};

// creates an environment with empty setup and teardown functions.
JTESTENV(THROWER) {
  SETUP{};
  TEARDOWN{};

public:
// thrower and notthrower will be available in every test
// within this environment
  void thrower() { throw 5; } 
  void notthrower() {}
};

// creates environment with name ENV
JTESTENV(ENV) {
// before every test is run, an array will be allocated
// and it will be set equal to {1, 2, 3}
  SETUP {
    numbers = new int[3];
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
  };
// after every test the array will be deallocated
  TEARDOWN { delete[] numbers; };

public:
  int *numbers; // numbers is freely accessible within every test
};
```

Environments don't need to contain anything, you can define whichever parts you like.

The `SETUP` macro creates a function that will be run before every test in the environment, likewise the `TEARDOWN` macro creates a function that will be run after every test in the environment.

All fields and methods defined withing an environment are directly available inside tests in the environment. Access specifiers `(public|protected|private)` can be used to further dictate which methods are available to the test. Anything that is `public|protected` can be accessed, anything `private` cannot be accessed.

To create a test use the `JTEST(_envname, _testname){ ... }` macro:

```cpp
// All of these could also be in the same file.

// in EQENV.h
JTESTENV(EQ) {
  SETUP{};
  TEARDOWN{};
  int additionfunc(const int i1, const int i2) { return i1 + i2; }
  int multfunc(const int i1, const int i2) { return i1 * i2; }
};

// in additionfunc.cpp
JTEST(EQ, addition) {
  EXPECT_EQ(additionfunc(1, 2), 3);
  EXPECT_EQ(additionfunc(5, -2), 3);
  EXPECT_EQ(additionfunc(-2, 0), -2);
}

// in multfunc.cpp
JTEST(EQ, multiply) {
  EXPECT_EQ(multfunc(1, 1), -1);
  EXPECT_EQ(multfunc(1, 2), -1);
  EXPECT_EQ(multfunc(5, -2), -1);
  EXPECT_EQ(multfunc(-2, 0), -1);
}
```

This example will perform 4 checks per test (1 per `EXPECT`).
If 1 of these checks fails, the whole test will register as a failure and the
console will say how many expectations weren't met.

There are 6 `EXPECT` macros you can use:
- `EXPECT_EQ(inp1, inp2)`: will add a fail if (inp1) != (inp2)
- `EXPECT_TRUE(inp1)`: will add a fail if !(inp1) evaluates to true
- `EXPECT_FALSE(inp1)`: will add a fail if (inp1) evaluates to true
- `EXPECT_LIFE(ACTION)`: will add a fail if ACTION throws an exception
- `EXPECT_DEATH(ACTION)`: will add a fail if ACTION doesn't throw an exception
- `EXPECT_ERRORTYPE(ERR_TYPE, ACTION)`: will add a fail if ACTION does not throw an exception or if the thrown  exception is not of type ERR_TYPE
 
When a test is running, it will have the `[RUNNING]` status.
When a test is done running there can be 3 different of status messages:
- `[PASSED]`: The test has completed and all expectations were met
- `[FAILED]`: The test has completed but some/all expectations weren't met
- `[FLAWED]`: The test has not completed, something threw an exception when it wasn't supposed to and terminated the test early

If everything goes right, there will be a final line presenting a `[COMPLETE]` status message.

## Usage

To see an example output, in `example/` run: 
- `cmake . && make && ./runAllTests` on Linux
- `cmake -G "MinGW Makefiles" . && make && runAllTests.exe` on Windows
- `g++ -o runAllTests *.cpp && ./runAllTests` on Linux
- `g++ -o *.cpp runAllTests && runAllTests.exe` on Windows

***If your console does not support ANSI characters, compile the tests
with the `NO_ANSI_CONSOLE` macro defined (if you're using g++, add
`-DNO_ANSI_CONSOLE` as an option).***

***Compile the tests with the `TERSE` macro defined to get a shorter output, only failed tests will appear and if none fail only one line will be printed saying so.***

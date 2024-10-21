# JTest

This is a small, fast, portable, and lightweight test suite contained entirely within a header file (for C++11 and up).

![](https://github.com/JamieLakchi/JTest/blob/master/JTESTWINDOWSCMD.gif)

## Motivation

I don't like GTest. There's some setup work to do, and you need to remake it if you want to run your tests on a different machine.


## Usage

### With CMake (see `exampleUse1/`):

1. Create all your tests in .cpp files.
2. In main(), add the line: `TestRegistry::runAllTests();` to run all the tests.
3. Make your .cpp files and run the executable.

To see an example output, in exampleUse1 run: 
- `cmake . && make && clear && ./runAllTests` on Linux
- `cmake -G "MinGW Makefiles" . && make && cls && runAllTests.exe` on Windows

### Without CMake (see `exampleUse2/`): 
1. create all your tests in .h files.
2. Create one .cpp in which you include all the .h files.
3. Create a main() function and add the line `TestRegistry::runAllTests();` to run all the tests.
4. Compile the .cpp and run the executable.

To see an example output, in exampleUse2 run:
- `g++ main.cpp -o runAllTests && clear && ./runAllTests` on Linux
- `g++ main.cpp -o runAllTests && cls && runAllTests.exe` on Windows

***If your console does not support ANSI characters, compile the tests
with the `NO_ANSI_CONSOLE` macro defined (if you're using g++, add
`-DNO_ANSI_CONSOLE` as an option).***

## Creating Tests

All tests in one file are combined into a batch, the name of the batch will
be displayed before the tests are run.

Batches are run in alphabetical order.

To create a test use the `JTEST(test name){ ... }` macro:

```cpp
JTEST(addition){
  auto additionfunc = [](const int i1, const int i2){return i1 + i2;};

  EXPECT_EQ(additionfunc(1, 1), 2);
  EXPECT_EQ(additionfunc(1, 2), 3);
  EXPECT_EQ(additionfunc(5, -2), 3);
  EXPECT_EQ(additionfunc(-2, 0), -2);
}
```

This example will perform 4 checks (1 per `EXPECT`).
If 1 of these checks fails, the whole test will register as a failure and the
console will say how many expectations weren't met.

There are 6 `EXPECT` macros you can use:
- `EXPECT_EQ(inp1, inp2)`: will add a fail if (inp1) != (inp2)
- `EXPECT_TRUE(inp1)`: will add a fail if !(inp1) == true
- `EXPECT_FALSE(inp1)`: will add a fail if (inp1) == true
- `EXPECT_LIFE(ACTION)`: will add a fail if ACTION throws an exception
- `EXPECT_DEATH(ACTION)`: will add a fail if ACTION doesn't throw an exception
- `EXPECT_ERRORTYPE(ERR_TYPE, ACTION)`: will add a fail if ACTION does not throw an exception or if the thrown  exception is not of type ERR_TYPE
 
When a test is running, it will have the `[RUNNING]` status.
When a test is done running there can be 3 different of status messages:
- `[PASSED]`: The test has completed and all expectations were met
- `[FAILED]`: The test has completed but some/all expectations weren't met
- `[FLAWED]`: The test has not completed, something threw an exception when it wasn't supposed to and terminated the test early

If everything goes right, there will be a final line presenting a `[COMPLETE]` status message.

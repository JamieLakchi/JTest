/*
 * File: JTest.h
 * Author: Jamie Lakchi
 * Date: 21/10/2024
 * Description: These are the building blocks for a generic testing suite
 * Version: 1.0.0
 *
 * Change History:
 *  - 21/10/2024: Jamie Lakchi - Initial creation of the file
 */

/**
 * This is a small, fast, portable, and lightweight testsuite contained entirely
 * in this header file (for c++ 11 and up).
 *
 * -------- Motivation --------
 *
 * I don't like gtest.
 * There's some setup work to do, and you need to remake it if you want to run
 * your tests on a different machine.
 *
 * -------- Usage --------
 *
 * With CMake (see exampleUse1/): create all your tests in .cpp files. In main()
 * add the line "TestRegistry::runAllTests();" to run all the tests. Make
 * your .cpp files and run the executable.
 *
 * Without CMake (see exampleUse2/): create all your tests in .h files. Create
 * one .cpp in which you include all the .h files. Create a main() function and
 * add the line "TestRegistry::runAllTests();" to run all the tests. Compile the
 * .cpp and run the executable.
 *
 * INFO: if your console does not support ANSI characters, compile the tests
 * with the NO_ANSI_CONSOLE macro defined (if you're using g++, add
 * -DNO_ANSI_CONSOLE as an option).
 *
 * All tests in one file are combined into a batch, the name of the batch will
 * be displayed before the tests are run.
 *
 * Batches are run in alphabetical order.
 *
 * To create a test use the JTEST(test name){ ... } macro:
 *
 * JTEST(addition){
 *  auto additionfunc = [](const int i1, const int i2){return i1 + i2;};
 *
 *  EXPECT_EQ(additionfunc(1, 1), 2);
 *  EXPECT_EQ(additionfunc(1, 2), 3);
 *  EXPECT_EQ(additionfunc(5, -2), 3);
 *  EXPECT_EQ(additionfunc(-2, 0), -2);
 * }
 *
 * This example will perform 4 checks (1 per EXPECT).
 * If 1 of these checks fails, the whole test will register as a failure and the
 * console will say how many expectations weren't met.
 *
 * There are ... EXPECT macros you can use:
 *    EXPECT_EQ(inp1, inp2): will add a fail if (inp1) != (inp2)
 *    EXPECT_TRUE(inp1): will add a fail if !(inp1) == true
 *    EXPECT_FALSE(inp1): will add a fail if (inp1) == true
 *    EXPECT_LIFE(ACTION): will add a fail if ACTION throws an exception
 *    EXPECT_DEATH(ACTION): will add a fail if ACTION doesn't throw an exception
 *    EXPECT_ERRORTYPE(ERR_TYPE, ACTION): will add a fail if ACTION does not
 *       throw an exception or if the thrown  exception is not of type ERR_TYPE
 *
 * When a test is running, it will have the [RUNNING] status.
 * When a test is done running there can be 3 different of status messages:
 *    [PASSED]: The test has completed and all expectations were met
 *    [FAILED]: The test has completed but some/all expectations weren't met
 *    [FLAWED]: The test has not completed, something threw an exception when it
 *        wasn't supposed to and terminated the test early
 *
 * If everything goes right, there will be a final line presenting a [COMPLETE]
 * status message.
 *
 */

#ifndef INC_JTEST_HPP
#define INC_JTEST_HPP

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// simple token transformation functions
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define CONCAT(a, b) a##b

#define GETFILE TOSTRING(__FILE__)

#ifdef NO_ANSI_CONSOLE
#define CONSOLERED ""
#define CONSOLEGREEN ""
#define CONSOLEYELLOW ""
#define CONSOLEBLUE ""
#define CONSOLEMAGENTA ""
#define CONSOLECYAN ""
#define CONSOLEDEFAULT ""
#define CONSOLECLEARLASTLINE ""
#else
// when printed via std::cout these will change the color of the coming text if
// the console supports ANSI characters (so all consoles except windows base
// cmd;) the 1; in front changes the text style to bold
#define CONSOLERED "\033[1;31m"
#define CONSOLEGREEN "\033[1;32m"
#define CONSOLEYELLOW "\033[1;33m"
#define CONSOLEBLUE "\033[1;34m"
#define CONSOLEMAGENTA "\033[1;35m"
#define CONSOLECYAN "\033[1;36m"
#define CONSOLEDEFAULT "\033[0m"
#define CONSOLECLEARLASTLINE "\033[A\033[2K"
#endif

#define RUNNINGSTATUS CONSOLECYAN "[RUNNING]" CONSOLEDEFAULT
#define PASSEDSTATUS CONSOLEGREEN "[PASSED]" CONSOLEDEFAULT
#define FAILEDSTATUS CONSOLERED "[FAILED]" CONSOLEDEFAULT
#define FLAWEDSTATUS CONSOLEYELLOW "[FLAWED]" CONSOLEDEFAULT
#define COMPLETESTATUS CONSOLEBLUE "[COMPLETE]" CONSOLEDEFAULT

// the following expect_... will error outside of the context of a JTEST(){}
// block

// will add a fail if inp1 != inp2
#define EXPECT_EQ(inp1, inp2)                                                  \
  if ((inp1) != (inp2)) {                                                      \
    ++_t.nrOfTestsFailed;                                                      \
  }

// will add a fail if !(inp1) == true
#define EXPECT_TRUE(inp1)                                                      \
  if (!(inp1)) {                                                               \
    ++_t.nrOfTestsFailed;                                                      \
  }

// will add a fail if inp1 == true
#define EXPECT_FALSE(inp1)                                                     \
  if ((inp1)) {                                                                \
    ++_t.nrOfTestsFailed;                                                      \
  }

// will fail if inp1 throws an exception
#define EXPECT_LIFE(ACTION)                                                    \
  try {                                                                        \
    ACTION;                                                                    \
  } catch (...) {                                                              \
    ++_t.nrOfTestsFailed;                                                      \
  }

// will fail if inp1 does not throw an exception
#define EXPECT_DEATH(ACTION)                                                   \
  try {                                                                        \
    ACTION;                                                                    \
    ++_t.nrOfTestsFailed;                                                      \
  } catch (...) {                                                              \
  }

// will add a fail if ACTION does not throw an exception or if the thrown
// exception is not of type ERR_TYPE
#define EXPECT_ERRORTYPE(ERR_TYPE, ACTION)                                     \
  try {                                                                        \
    try {                                                                      \
      ACTION;                                                                  \
      ++_t.nrOfTestsFailed;                                                    \
    } catch (ERR_TYPE & e) {                                                   \
    }                                                                          \
  } catch (...) {                                                              \
    ++_t.nrOfTestsFailed;                                                      \
  }

struct Test;

// this macro is used for the actual testing like so:
// JTEST(name of your test){your code}
#define JTEST(testname)                                                        \
  void CONCAT(test_, testname)(Test & _t);                                     \
  bool CONCAT(dummy_, testname) = TestRegistry::registerTest(                  \
      GETFILE, {TOSTRING(testname), CONCAT(test_, testname)});                 \
  void CONCAT(test_, testname)(Test & _t)

using TestFunction = std::function<void(Test &_t)>;

// this struct should never be created manually
// it's elements are accessible in a JTEST block but shouldn't be changed
struct Test {
  std::string name;
  TestFunction func;
  int nrOfTestsFailed = 0;
};

// this will hold all of the tests
// use TestRegistry::runAllTests() to run all of the tests
// don't use registerTest manually, instead use the JTEST macro's
// don't create an object of this type
class TestRegistry {
public:
  static bool registerTest(const std::string &filename, Test test) {
    auto &instance = getInstance();
    auto testiter = instance.tests.find(filename);
    if (testiter == instance.tests.end()) {
      instance.tests[filename] = {test};
    } else {
      (*testiter).second.push_back(test);
    }
    return true;
  }

  static void runAllTests() {
    auto &instance = getInstance();
    int failedTests = 0;
    int maxBatchSizeName = 0;

    auto maxBSN = [&](const int i) {
      maxBatchSizeName = maxBatchSizeName > i ? maxBatchSizeName : i;
    };

    for (auto &batch : instance.tests) {
      maxBSN(batch.first.size());
    }

    auto batchNameExtension = [&](const int normalSize) {
      return std::string(maxBatchSizeName - normalSize, '-');
    };

    for (auto &batch : instance.tests) {
      failedTests += batch.second.size();
      std::cout << CONSOLEMAGENTA << "---- " << batch.first << " ----"
                << batchNameExtension(batch.first.size()) << CONSOLEDEFAULT
                << std::endl;
      for (auto &test : batch.second) {
        bool fatal = false;
        std::string mid;

        std::cout << RUNNINGSTATUS << "\t" << test.name << std::endl;

        try {
          test.func(test);
        } catch (...) {
          fatal = true;
        }

        std::cout << CONSOLECLEARLASTLINE;
        if (test.nrOfTestsFailed) {
          std::cout << FAILEDSTATUS;
        } else if (fatal) {
          std::cout << FLAWEDSTATUS;
        } else {
          --failedTests;
          std::cout << PASSEDSTATUS;
        }

        if (fatal) {
          mid = "test threw exception";
        } else {
          mid = (test.nrOfTestsFailed ? std::to_string(test.nrOfTestsFailed)
                                      : "no") +
                " check(s) failed";
        }

        std::cout << "\t" << test.name << ": " << mid << std::endl;
      }
      std::cout << std::endl;
    }

    std::cout << COMPLETESTATUS << "\t";
    if (!failedTests) {
      std::cout << "All tests passed!" << std::endl;
    } else {
      std::cout << "Some tests failed." << std::endl;
    }
  }

private:
  std::map<std::string, std::vector<Test>> tests;

  // this function only exists to adhere by the singleton design pattern
  static TestRegistry &getInstance() {
    static TestRegistry instance;
    return instance;
  }
};

#endif

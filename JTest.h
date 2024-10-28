/*
 * File: JTest.h
 * Author: Jamie Lakchi
 * Date: 21/10/2024
 * Description: These are the building blocks for a generic testing suite
 * Version: 1.1.0
 *
 * Change History:
 *  - 21/10/2024: Jamie Lakchi - Initial creation of the file
 *  - 22/10/2024: Jamie Lakchi - Removed nested try-catch block from
 *                               EXPECT_ERRORTYPE, added explicit constructor to
 *                               Test
 *  - 28/10/2024: Jamie Lakchi - created subbatch system
 */

#ifndef INC_JTEST_HPP
#define INC_JTEST_HPP

#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

// simple token transformation functions
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define CONCATIFY(a, b) a##b
#define CONCAT(a, b) CONCATIFY(a, b)

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
#define COMPLETESTATUSF CONSOLERED "[RESULT]\tSome tests failed." CONSOLEDEFAULT
#define COMPLETESTATUSP CONSOLEGREEN "[RESULT]\tAll test passed!" CONSOLEDEFAULT

// the following expect_... will error outside of the context of a JTEST(){}
// block

// will add a fail if inp1 != inp2
#define EXPECT_EQ(inp1, inp2)                                                  \
  do {                                                                         \
    if ((inp1) != (inp2)) {                                                    \
      ++_t.nrOfTestsFailed;                                                    \
    }                                                                          \
  } while (false)

// will add a fail if !(inp1) == true
#define EXPECT_TRUE(inp1)                                                      \
  do {                                                                         \
    if (!(inp1)) {                                                             \
      ++_t.nrOfTestsFailed;                                                    \
    }                                                                          \
  } while (false)

// will add a fail if inp1 == true
#define EXPECT_FALSE(inp1)                                                     \
  do {                                                                         \
    if ((inp1)) {                                                              \
      ++_t.nrOfTestsFailed;                                                    \
    }                                                                          \
  } while (false)

// will fail if inp1 throws an exception
#define EXPECT_LIFE(ACTION)                                                    \
  do {                                                                         \
    try {                                                                      \
      ACTION;                                                                  \
    } catch (...) {                                                            \
      ++_t.nrOfTestsFailed;                                                    \
    }                                                                          \
  } while (false)

// will fail if inp1 does not throw an exception
#define EXPECT_DEATH(ACTION)                                                   \
  do {                                                                         \
    try {                                                                      \
      ACTION;                                                                  \
      ++_t.nrOfTestsFailed;                                                    \
    } catch (...) {                                                            \
    }                                                                          \
  } while (false)

// will add a fail if ACTION does not throw an exception or if the thrown
// exception is not of type ERR_TYPE
#define EXPECT_ERRORTYPE(ERR_TYPE, ACTION)                                     \
  do {                                                                         \
    try {                                                                      \
      ACTION;                                                                  \
      ++_t.nrOfTestsFailed;                                                    \
    } catch (ERR_TYPE & e) {                                                   \
    } catch (...) {                                                            \
      ++_t.nrOfTestsFailed;                                                    \
    }                                                                          \
  } while (false)

// this macro is used for the actual testing like so:
// JTEST(name of your test){your code}
#define JTEST1(testname)                                                       \
  void CONCAT(test_, testname)(Test & _t);                                     \
  bool CONCAT(dummy_, testname) = TestRegistry::registerTest(                  \
      GETFILE, Test{TOSTRING(testname), CONCAT(test_, testname)});             \
  void CONCAT(test_, testname)(Test & _t)

#define JTEST2(subbatchname, testname)                                         \
  void CONCAT(test_, CONCAT(subbatchname, testname))(Test & _t);               \
  bool CONCAT(dummy_, CONCAT(subbatchname, testname)) =                        \
      TestRegistry::registerTest(                                              \
          GETFILE, TOSTRING(subbatchname),                                     \
          Test{TOSTRING(testname),                                             \
               CONCAT(test_, CONCAT(subbatchname, testname))});                \
  void CONCAT(test_, CONCAT(subbatchname, testname))(Test & _t)

#define JTESTSELECTOR(_1, _2, NAME, ...) NAME

#define JTEST(...) JTESTSELECTOR(__VA_ARGS__, JTEST2, JTEST1)(__VA_ARGS__)

struct Test;
using TestFunction = std::function<void(Test &_t)>;

// this struct should never be created manually
// it's elements are accessible in a JTEST block but shouldn't be changed
struct Test {
  Test(std::string &&s, TestFunction tfunc) : name(s), func(tfunc){};
  std::string name;
  TestFunction func;
  int nrOfTestsFailed = 0;
};

struct Subbatch {
  bool addTest(Test &test) {
    tests.push_back(test);
    return true;
  };

  int run() {
    int failures = tests.size();

    for (auto &test : tests) {
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
        --failures;
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

    return failures;
  };

  std::vector<Test> tests;
};

struct Batch {
  bool addTest(const std::string &sbatchname, Test &test) {
    auto sbatchIter = subbatches.find(sbatchname);
    if (sbatchIter == subbatches.end()) {
      subbatches[sbatchname] = Subbatch{};
      return subbatches[sbatchname].addTest(test);
    } else {
      return (*sbatchIter).second.addTest(test);
    }
    return false;
  }

  int run() {
    bool printSBNames =
        subbatches.size() > 1 || (*subbatches.begin()).first.size() != 0;

    int failures = 0;

    for (auto &subbatch : subbatches) {
      if (printSBNames) {
        std::cout << CONSOLEBLUE << "< "
                  << (subbatch.first.size() == 0 ? "MISC" : subbatch.first)
                  << " >" << CONSOLEDEFAULT << std::endl;
      }

      failures += subbatch.second.run();
    }

    return failures;
  }

  std::map<std::string, Subbatch> subbatches;
};

struct _TestRegistry_Container {
  bool addTest(const std::string &batchname, const std::string &sbatchname,
               Test &test) {
    auto batchIter = batches.find(batchname);
    if (batchIter == batches.end()) {
      batches[batchname] = Batch{};
      return batches[batchname].addTest(sbatchname, test);
    } else {
      return (*batchIter).second.addTest(sbatchname, test);
    }
    return false;
  };

  int run() {
    int failures = 0;
    int maxBatchSizeName = 0;

    auto maxBSN = [&](const int i) {
      maxBatchSizeName = maxBatchSizeName > i ? maxBatchSizeName : i;
    };

    for (auto &batch : batches) {
      maxBSN(batch.first.size());
    }

    auto batchNameExtension = [&](const int normalSize) {
      return std::string(maxBatchSizeName - normalSize, '-');
    };

    for (auto &batch : batches) {
      std::cout << CONSOLEMAGENTA << "---- " << batch.first << " ----"
                << batchNameExtension(batch.first.size()) << CONSOLEDEFAULT
                << std::endl;

      failures += batch.second.run();
    }

    return failures;
  }

  std::map<std::string, Batch> batches;
};

// this will hold all of the tests
// use TestRegistry::runAllTests() to run all of the tests
// don't use registerTest manually, instead use the JTEST macros
// don't create an object of this type
class TestRegistry {
public:
  static bool registerTest(const std::string &batchname,
                           const std::string &sbatchname, Test &&test) {
    getInstance().tests.addTest(batchname, sbatchname, test);
    return true;
  }

  static bool registerTest(const std::string &batchname, Test test) {
    getInstance().tests.addTest(batchname, "", test);
    return true;
  }

  static void runAllTests() {
    auto &instance = getInstance();
    int failedTests = instance.tests.run();

    if (!failedTests) {
      std::cout << COMPLETESTATUSP << std::endl;
    } else {
      std::cout << COMPLETESTATUSF << std::endl;
    }
  }

  static void _dump() {
    auto &instance = getInstance();
    for (auto &bp : instance.tests.batches) {
      std::cout << "batch: " << bp.first << std::endl;
      for (auto &sbp : bp.second.subbatches) {
        std::cout << "subbatch: " << sbp.first << std::endl;
        for (auto &t : sbp.second.tests) {
          std::cout << "test: " << t.name << std::endl;
        }
      }
    }
  }

private:
  _TestRegistry_Container tests;

  // this function only exists to adhere by the singleton design pattern
  static TestRegistry &getInstance() {
    static TestRegistry instance;
    return instance;
  }
};

#endif

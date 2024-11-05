/*
 * File: JTest.h
 * Author: Jamie Lakchi
 * Date: 21/10/2024
 * Description: These are the building blocks for a generic testing suite
 * Version: 2.0.1
 */

#ifndef INC_JTEST_HPP
#define INC_JTEST_HPP

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>

// simple token transformation functions
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define CONCATIFY(a, b) a##b
#define CONCAT(a, b) CONCATIFY(a, b)
#define CONCAT2(a, b, c) CONCAT(a##_, CONCAT(b##_, c))

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
#define COMPLETEF CONSOLERED "[RESULT]\tSome tests failed." CONSOLEDEFAULT
#define COMPLETEP CONSOLEGREEN "[RESULT]\tAll tests passed!" CONSOLEDEFAULT
#define TERSEP                                                                 \
  CONSOLEGREEN "[REPORT]\tAll expectations were met!" CONSOLEDEFAULT

// the following expect_... will error outside of the context of a JTEST(){}
// block

// will add a fail if inp1 != inp2
#define EXPECT_EQ(inp1, inp2)                                                  \
  do {                                                                         \
    if ((inp1) != (inp2)) {                                                    \
      t.incr();                                                                \
    }                                                                          \
  } while (false)

// will add a fail if !(inp1) == true
#define EXPECT_TRUE(inp1)                                                      \
  do {                                                                         \
    if (!(inp1)) {                                                             \
      t.incr();                                                                \
    }                                                                          \
  } while (false)

// will add a fail if inp1 == true
#define EXPECT_FALSE(inp1)                                                     \
  do {                                                                         \
    if ((inp1)) {                                                              \
      t.incr();                                                                \
    }                                                                          \
  } while (false)

// will fail if inp1 throws an exception
#define EXPECT_LIFE(ACTION)                                                    \
  do {                                                                         \
    try {                                                                      \
      ACTION;                                                                  \
    } catch (...) {                                                            \
      t.incr();                                                                \
    }                                                                          \
  } while (false)

// will fail if inp1 does not throw an exception
#define EXPECT_DEATH(ACTION)                                                   \
  do {                                                                         \
    try {                                                                      \
      ACTION;                                                                  \
      t.incr();                                                                \
    } catch (...) {                                                            \
    }                                                                          \
  } while (false)

// will add a fail if ACTION does not throw an exception or if the thrown
// exception is not of type ERR_TYPE
#define EXPECT_ERRORTYPE(ERR_TYPE, ACTION)                                     \
  do {                                                                         \
    try {                                                                      \
      ACTION;                                                                  \
      t.incr();                                                                \
    } catch (ERR_TYPE & e) {                                                   \
    } catch (...) {                                                            \
      t.incr();                                                                \
    }                                                                          \
  } while (false)

// jtest environment creator
#define JTESTENV(_envname)                                                     \
  class _envname : public JTest::internal::_JTESTENV_base

#define SETUP                                                                  \
public:                                                                        \
  virtual void setup() override
#define TEARDOWN                                                               \
public:                                                                        \
  virtual void teardown() override

// jtest creator
#define JTESTEXPAND(_envname, _testname, _testclassname, _testfuncname,        \
                    _envfuncname, _dummyname, _boolname)                       \
  class _testclassname : public _envname {                                     \
  public:                                                                      \
    _testclassname() = default;                                                \
    void _testfuncname(JTest::internal::test &t);                              \
    void _envfuncname(JTest::internal::test &t) {                              \
      setup();                                                                 \
      _testfuncname(t);                                                        \
      teardown();                                                              \
    }                                                                          \
  };                                                                           \
  void _dummyname(JTest::internal::test &t) {                                  \
    _testclassname suite{};                                                    \
    suite._envfuncname(t);                                                     \
  }                                                                            \
  bool _boolname = JTest::TestRegister::registerTest(                          \
      TOSTRING(_envname),                                                      \
      JTest::internal::test{TOSTRING(_testname), _dummyname});                 \
  void _testclassname::_testfuncname(JTest::internal::test &t)

#define JTEST(_envname, _testname)                                             \
  JTESTEXPAND(_envname, _testname, CONCAT2(_envname, _testname, ),             \
              CONCAT2(_envname, _testname, test),                              \
              CONCAT2(_envname, _testname, env),                               \
              CONCAT2(_envname, _testname, dummy),                             \
              CONCAT2(_envname, _testname, _bool))

// JTest begin

namespace JTest {
namespace internal {
struct test;
}

using testfunc = std::function<void(internal::test &)>;
using std::list;
using std::map;
using std::string;

namespace internal {
class _JTESTENV_base {
protected:
  // prevent construction of objects of this type
  _JTESTENV_base() = default;
  _JTESTENV_base(void *){};

public:
  virtual void setup() {}
  virtual void teardown() {}
};

struct test {
  test(string &&name, testfunc func) : t_name(name), t_func(func) {}

  void operator()() { t_func(*this); }

  inline void incr() { ++failures; }

  inline void prettyPrint() {
    std::cout << "\t" << CONSOLEBLUE << t_name << CONSOLEDEFAULT << ": ";
  }

  unsigned short failures = 0;
  string t_name;
  testfunc t_func;
};

}; // namespace internal

class TestRegister {
public:
  static bool registerTest(string &&envname, internal::test &&t) {
    auto &_tests = getInstance()._tests;
    auto _testiter = _tests.find(envname);
    if (_testiter == _tests.end()) {
      _tests[envname] = list{t};
    } else {
      (*_testiter).second.push_back(t);
    }
    return true;
  }

  static void _dump() {
    auto &_tests = getInstance()._tests;
    for (auto &p : _tests) {
      std::cout << "ENV:\t" << p.first << std::endl;
      for (auto &t : p.second) {
        std::cout << "TEST:\t" << t.t_name << t.failures << std::endl;
      }
    }
  }

  static int runAllTests() {
    auto &_tests = getInstance()._tests;
    bool completefail = false;
    for (auto &p_envtestlist : _tests) {
      std::cout << CONSOLEMAGENTA << "STARTED:\t{ " << p_envtestlist.first
                << " }" << CONSOLEDEFAULT << std::endl;

      int failingTests = p_envtestlist.second.size();

      for (auto &t : p_envtestlist.second) {
        std::cout << RUNNINGSTATUS << std::endl;

        bool flawed = false;

        try {
          t();
        } catch (...) {
          flawed = true;
        }

        std::cout << CONSOLECLEARLASTLINE;

        if (!flawed && !t.failures) {
          --failingTests;
#ifdef TERSE
          continue;
#endif
          std::cout << PASSEDSTATUS;
          t.prettyPrint();
          std::cout << "all expectations were met!" << std::endl;
        } else if (flawed) {
          std::cout << FLAWEDSTATUS;
          t.prettyPrint();
          std::cout << "an exception was thrown and not caught" << std::endl;
          completefail = true;
        } else {
          std::cout << FAILEDSTATUS;
          t.prettyPrint();
          std::cout << t.failures << " unexpected event(s)" << std::endl;
          completefail = true;
        }

      }
#ifdef TERSE
      if (!failingTests) {
        std::cout << TERSEP << std::endl;
      }
#endif
      std::cout << std::endl;
    }

    std::cout << (completefail ? COMPLETEF : COMPLETEP) << std::endl;
    return completefail;
  }

private:
  TestRegister() = default;
  TestRegister(void *){};

  static TestRegister &getInstance() {
    static TestRegister t{};
    return t;
  }

  map<string, list<internal::test>> _tests;
};

inline int RunAllTests() { return TestRegister::runAllTests(); };

} // namespace JTest

#endif

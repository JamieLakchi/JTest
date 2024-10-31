cmake_minimum_required(VERSION 3.22)

project(exampleUse1)

add_executable(runAllTests 
  eq_tests.cpp
  true_test.cpp
  false_test.cpp
  life_test.cpp
  death_test.cpp
  errtype_test.cpp
  flawed_test.cpp
  env_test.cpp
  main.cpp
)


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/scidae/petprojects/JTEST/JENV/example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/scidae/petprojects/JTEST/JENV/example/build

# Include any dependencies generated for this target.
include CMakeFiles/runAllTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/runAllTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/runAllTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runAllTests.dir/flags.make

CMakeFiles/runAllTests.dir/eq_tests.cpp.o: CMakeFiles/runAllTests.dir/flags.make
CMakeFiles/runAllTests.dir/eq_tests.cpp.o: /home/scidae/petprojects/JTEST/JENV/example/eq_tests.cpp
CMakeFiles/runAllTests.dir/eq_tests.cpp.o: CMakeFiles/runAllTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/scidae/petprojects/JTEST/JENV/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runAllTests.dir/eq_tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runAllTests.dir/eq_tests.cpp.o -MF CMakeFiles/runAllTests.dir/eq_tests.cpp.o.d -o CMakeFiles/runAllTests.dir/eq_tests.cpp.o -c /home/scidae/petprojects/JTEST/JENV/example/eq_tests.cpp

CMakeFiles/runAllTests.dir/eq_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runAllTests.dir/eq_tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scidae/petprojects/JTEST/JENV/example/eq_tests.cpp > CMakeFiles/runAllTests.dir/eq_tests.cpp.i

CMakeFiles/runAllTests.dir/eq_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runAllTests.dir/eq_tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scidae/petprojects/JTEST/JENV/example/eq_tests.cpp -o CMakeFiles/runAllTests.dir/eq_tests.cpp.s

CMakeFiles/runAllTests.dir/true_test.cpp.o: CMakeFiles/runAllTests.dir/flags.make
CMakeFiles/runAllTests.dir/true_test.cpp.o: /home/scidae/petprojects/JTEST/JENV/example/true_test.cpp
CMakeFiles/runAllTests.dir/true_test.cpp.o: CMakeFiles/runAllTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/scidae/petprojects/JTEST/JENV/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/runAllTests.dir/true_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runAllTests.dir/true_test.cpp.o -MF CMakeFiles/runAllTests.dir/true_test.cpp.o.d -o CMakeFiles/runAllTests.dir/true_test.cpp.o -c /home/scidae/petprojects/JTEST/JENV/example/true_test.cpp

CMakeFiles/runAllTests.dir/true_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runAllTests.dir/true_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scidae/petprojects/JTEST/JENV/example/true_test.cpp > CMakeFiles/runAllTests.dir/true_test.cpp.i

CMakeFiles/runAllTests.dir/true_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runAllTests.dir/true_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scidae/petprojects/JTEST/JENV/example/true_test.cpp -o CMakeFiles/runAllTests.dir/true_test.cpp.s

CMakeFiles/runAllTests.dir/false_test.cpp.o: CMakeFiles/runAllTests.dir/flags.make
CMakeFiles/runAllTests.dir/false_test.cpp.o: /home/scidae/petprojects/JTEST/JENV/example/false_test.cpp
CMakeFiles/runAllTests.dir/false_test.cpp.o: CMakeFiles/runAllTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/scidae/petprojects/JTEST/JENV/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/runAllTests.dir/false_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runAllTests.dir/false_test.cpp.o -MF CMakeFiles/runAllTests.dir/false_test.cpp.o.d -o CMakeFiles/runAllTests.dir/false_test.cpp.o -c /home/scidae/petprojects/JTEST/JENV/example/false_test.cpp

CMakeFiles/runAllTests.dir/false_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runAllTests.dir/false_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scidae/petprojects/JTEST/JENV/example/false_test.cpp > CMakeFiles/runAllTests.dir/false_test.cpp.i

CMakeFiles/runAllTests.dir/false_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runAllTests.dir/false_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scidae/petprojects/JTEST/JENV/example/false_test.cpp -o CMakeFiles/runAllTests.dir/false_test.cpp.s

CMakeFiles/runAllTests.dir/life_test.cpp.o: CMakeFiles/runAllTests.dir/flags.make
CMakeFiles/runAllTests.dir/life_test.cpp.o: /home/scidae/petprojects/JTEST/JENV/example/life_test.cpp
CMakeFiles/runAllTests.dir/life_test.cpp.o: CMakeFiles/runAllTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/scidae/petprojects/JTEST/JENV/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/runAllTests.dir/life_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runAllTests.dir/life_test.cpp.o -MF CMakeFiles/runAllTests.dir/life_test.cpp.o.d -o CMakeFiles/runAllTests.dir/life_test.cpp.o -c /home/scidae/petprojects/JTEST/JENV/example/life_test.cpp

CMakeFiles/runAllTests.dir/life_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runAllTests.dir/life_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scidae/petprojects/JTEST/JENV/example/life_test.cpp > CMakeFiles/runAllTests.dir/life_test.cpp.i

CMakeFiles/runAllTests.dir/life_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runAllTests.dir/life_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scidae/petprojects/JTEST/JENV/example/life_test.cpp -o CMakeFiles/runAllTests.dir/life_test.cpp.s

CMakeFiles/runAllTests.dir/death_test.cpp.o: CMakeFiles/runAllTests.dir/flags.make
CMakeFiles/runAllTests.dir/death_test.cpp.o: /home/scidae/petprojects/JTEST/JENV/example/death_test.cpp
CMakeFiles/runAllTests.dir/death_test.cpp.o: CMakeFiles/runAllTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/scidae/petprojects/JTEST/JENV/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/runAllTests.dir/death_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runAllTests.dir/death_test.cpp.o -MF CMakeFiles/runAllTests.dir/death_test.cpp.o.d -o CMakeFiles/runAllTests.dir/death_test.cpp.o -c /home/scidae/petprojects/JTEST/JENV/example/death_test.cpp

CMakeFiles/runAllTests.dir/death_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runAllTests.dir/death_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scidae/petprojects/JTEST/JENV/example/death_test.cpp > CMakeFiles/runAllTests.dir/death_test.cpp.i

CMakeFiles/runAllTests.dir/death_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runAllTests.dir/death_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scidae/petprojects/JTEST/JENV/example/death_test.cpp -o CMakeFiles/runAllTests.dir/death_test.cpp.s

CMakeFiles/runAllTests.dir/errtype_test.cpp.o: CMakeFiles/runAllTests.dir/flags.make
CMakeFiles/runAllTests.dir/errtype_test.cpp.o: /home/scidae/petprojects/JTEST/JENV/example/errtype_test.cpp
CMakeFiles/runAllTests.dir/errtype_test.cpp.o: CMakeFiles/runAllTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/scidae/petprojects/JTEST/JENV/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/runAllTests.dir/errtype_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runAllTests.dir/errtype_test.cpp.o -MF CMakeFiles/runAllTests.dir/errtype_test.cpp.o.d -o CMakeFiles/runAllTests.dir/errtype_test.cpp.o -c /home/scidae/petprojects/JTEST/JENV/example/errtype_test.cpp

CMakeFiles/runAllTests.dir/errtype_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runAllTests.dir/errtype_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scidae/petprojects/JTEST/JENV/example/errtype_test.cpp > CMakeFiles/runAllTests.dir/errtype_test.cpp.i

CMakeFiles/runAllTests.dir/errtype_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runAllTests.dir/errtype_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scidae/petprojects/JTEST/JENV/example/errtype_test.cpp -o CMakeFiles/runAllTests.dir/errtype_test.cpp.s

CMakeFiles/runAllTests.dir/flawed_test.cpp.o: CMakeFiles/runAllTests.dir/flags.make
CMakeFiles/runAllTests.dir/flawed_test.cpp.o: /home/scidae/petprojects/JTEST/JENV/example/flawed_test.cpp
CMakeFiles/runAllTests.dir/flawed_test.cpp.o: CMakeFiles/runAllTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/scidae/petprojects/JTEST/JENV/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/runAllTests.dir/flawed_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runAllTests.dir/flawed_test.cpp.o -MF CMakeFiles/runAllTests.dir/flawed_test.cpp.o.d -o CMakeFiles/runAllTests.dir/flawed_test.cpp.o -c /home/scidae/petprojects/JTEST/JENV/example/flawed_test.cpp

CMakeFiles/runAllTests.dir/flawed_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runAllTests.dir/flawed_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scidae/petprojects/JTEST/JENV/example/flawed_test.cpp > CMakeFiles/runAllTests.dir/flawed_test.cpp.i

CMakeFiles/runAllTests.dir/flawed_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runAllTests.dir/flawed_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scidae/petprojects/JTEST/JENV/example/flawed_test.cpp -o CMakeFiles/runAllTests.dir/flawed_test.cpp.s

CMakeFiles/runAllTests.dir/env_test.cpp.o: CMakeFiles/runAllTests.dir/flags.make
CMakeFiles/runAllTests.dir/env_test.cpp.o: /home/scidae/petprojects/JTEST/JENV/example/env_test.cpp
CMakeFiles/runAllTests.dir/env_test.cpp.o: CMakeFiles/runAllTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/scidae/petprojects/JTEST/JENV/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/runAllTests.dir/env_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runAllTests.dir/env_test.cpp.o -MF CMakeFiles/runAllTests.dir/env_test.cpp.o.d -o CMakeFiles/runAllTests.dir/env_test.cpp.o -c /home/scidae/petprojects/JTEST/JENV/example/env_test.cpp

CMakeFiles/runAllTests.dir/env_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runAllTests.dir/env_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scidae/petprojects/JTEST/JENV/example/env_test.cpp > CMakeFiles/runAllTests.dir/env_test.cpp.i

CMakeFiles/runAllTests.dir/env_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runAllTests.dir/env_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scidae/petprojects/JTEST/JENV/example/env_test.cpp -o CMakeFiles/runAllTests.dir/env_test.cpp.s

CMakeFiles/runAllTests.dir/main.cpp.o: CMakeFiles/runAllTests.dir/flags.make
CMakeFiles/runAllTests.dir/main.cpp.o: /home/scidae/petprojects/JTEST/JENV/example/main.cpp
CMakeFiles/runAllTests.dir/main.cpp.o: CMakeFiles/runAllTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/scidae/petprojects/JTEST/JENV/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/runAllTests.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runAllTests.dir/main.cpp.o -MF CMakeFiles/runAllTests.dir/main.cpp.o.d -o CMakeFiles/runAllTests.dir/main.cpp.o -c /home/scidae/petprojects/JTEST/JENV/example/main.cpp

CMakeFiles/runAllTests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/runAllTests.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scidae/petprojects/JTEST/JENV/example/main.cpp > CMakeFiles/runAllTests.dir/main.cpp.i

CMakeFiles/runAllTests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/runAllTests.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scidae/petprojects/JTEST/JENV/example/main.cpp -o CMakeFiles/runAllTests.dir/main.cpp.s

# Object files for target runAllTests
runAllTests_OBJECTS = \
"CMakeFiles/runAllTests.dir/eq_tests.cpp.o" \
"CMakeFiles/runAllTests.dir/true_test.cpp.o" \
"CMakeFiles/runAllTests.dir/false_test.cpp.o" \
"CMakeFiles/runAllTests.dir/life_test.cpp.o" \
"CMakeFiles/runAllTests.dir/death_test.cpp.o" \
"CMakeFiles/runAllTests.dir/errtype_test.cpp.o" \
"CMakeFiles/runAllTests.dir/flawed_test.cpp.o" \
"CMakeFiles/runAllTests.dir/env_test.cpp.o" \
"CMakeFiles/runAllTests.dir/main.cpp.o"

# External object files for target runAllTests
runAllTests_EXTERNAL_OBJECTS =

runAllTests: CMakeFiles/runAllTests.dir/eq_tests.cpp.o
runAllTests: CMakeFiles/runAllTests.dir/true_test.cpp.o
runAllTests: CMakeFiles/runAllTests.dir/false_test.cpp.o
runAllTests: CMakeFiles/runAllTests.dir/life_test.cpp.o
runAllTests: CMakeFiles/runAllTests.dir/death_test.cpp.o
runAllTests: CMakeFiles/runAllTests.dir/errtype_test.cpp.o
runAllTests: CMakeFiles/runAllTests.dir/flawed_test.cpp.o
runAllTests: CMakeFiles/runAllTests.dir/env_test.cpp.o
runAllTests: CMakeFiles/runAllTests.dir/main.cpp.o
runAllTests: CMakeFiles/runAllTests.dir/build.make
runAllTests: CMakeFiles/runAllTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/scidae/petprojects/JTEST/JENV/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable runAllTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runAllTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runAllTests.dir/build: runAllTests
.PHONY : CMakeFiles/runAllTests.dir/build

CMakeFiles/runAllTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runAllTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runAllTests.dir/clean

CMakeFiles/runAllTests.dir/depend:
	cd /home/scidae/petprojects/JTEST/JENV/example/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/scidae/petprojects/JTEST/JENV/example /home/scidae/petprojects/JTEST/JENV/example /home/scidae/petprojects/JTEST/JENV/example/build /home/scidae/petprojects/JTEST/JENV/example/build /home/scidae/petprojects/JTEST/JENV/example/build/CMakeFiles/runAllTests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/runAllTests.dir/depend


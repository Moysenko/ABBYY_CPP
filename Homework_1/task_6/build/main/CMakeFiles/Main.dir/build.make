# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.23.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.23.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/moysenko/Study/CPP/Homework_1/task_6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/moysenko/Study/CPP/Homework_1/task_6/build

# Include any dependencies generated for this target.
include main/CMakeFiles/Main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include main/CMakeFiles/Main.dir/compiler_depend.make

# Include the progress variables for this target.
include main/CMakeFiles/Main.dir/progress.make

# Include the compile flags for this target's objects.
include main/CMakeFiles/Main.dir/flags.make

main/CMakeFiles/Main.dir/main.cpp.o: main/CMakeFiles/Main.dir/flags.make
main/CMakeFiles/Main.dir/main.cpp.o: ../main/main.cpp
main/CMakeFiles/Main.dir/main.cpp.o: main/CMakeFiles/Main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moysenko/Study/CPP/Homework_1/task_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object main/CMakeFiles/Main.dir/main.cpp.o"
	cd /Users/moysenko/Study/CPP/Homework_1/task_6/build/main && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT main/CMakeFiles/Main.dir/main.cpp.o -MF CMakeFiles/Main.dir/main.cpp.o.d -o CMakeFiles/Main.dir/main.cpp.o -c /Users/moysenko/Study/CPP/Homework_1/task_6/main/main.cpp

main/CMakeFiles/Main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/main.cpp.i"
	cd /Users/moysenko/Study/CPP/Homework_1/task_6/build/main && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/moysenko/Study/CPP/Homework_1/task_6/main/main.cpp > CMakeFiles/Main.dir/main.cpp.i

main/CMakeFiles/Main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/main.cpp.s"
	cd /Users/moysenko/Study/CPP/Homework_1/task_6/build/main && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/moysenko/Study/CPP/Homework_1/task_6/main/main.cpp -o CMakeFiles/Main.dir/main.cpp.s

# Object files for target Main
Main_OBJECTS = \
"CMakeFiles/Main.dir/main.cpp.o"

# External object files for target Main
Main_EXTERNAL_OBJECTS =

main/Main: main/CMakeFiles/Main.dir/main.cpp.o
main/Main: main/CMakeFiles/Main.dir/build.make
main/Main: args/libArgs.a
main/Main: stonks/libStonks.a
main/Main: transactions/libTransactions.a
main/Main: args/libArgs.a
main/Main: stonks/libStonks.a
main/Main: main/CMakeFiles/Main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/moysenko/Study/CPP/Homework_1/task_6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Main"
	cd /Users/moysenko/Study/CPP/Homework_1/task_6/build/main && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
main/CMakeFiles/Main.dir/build: main/Main
.PHONY : main/CMakeFiles/Main.dir/build

main/CMakeFiles/Main.dir/clean:
	cd /Users/moysenko/Study/CPP/Homework_1/task_6/build/main && $(CMAKE_COMMAND) -P CMakeFiles/Main.dir/cmake_clean.cmake
.PHONY : main/CMakeFiles/Main.dir/clean

main/CMakeFiles/Main.dir/depend:
	cd /Users/moysenko/Study/CPP/Homework_1/task_6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/moysenko/Study/CPP/Homework_1/task_6 /Users/moysenko/Study/CPP/Homework_1/task_6/main /Users/moysenko/Study/CPP/Homework_1/task_6/build /Users/moysenko/Study/CPP/Homework_1/task_6/build/main /Users/moysenko/Study/CPP/Homework_1/task_6/build/main/CMakeFiles/Main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : main/CMakeFiles/Main.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/apollo/Study/CPP/Homework_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/apollo/Study/CPP/Homework_1/build

# Include any dependencies generated for this target.
include args/CMakeFiles/Args.dir/depend.make

# Include the progress variables for this target.
include args/CMakeFiles/Args.dir/progress.make

# Include the compile flags for this target's objects.
include args/CMakeFiles/Args.dir/flags.make

args/CMakeFiles/Args.dir/args.cpp.o: args/CMakeFiles/Args.dir/flags.make
args/CMakeFiles/Args.dir/args.cpp.o: ../args/args.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apollo/Study/CPP/Homework_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object args/CMakeFiles/Args.dir/args.cpp.o"
	cd /home/apollo/Study/CPP/Homework_1/build/args && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Args.dir/args.cpp.o -c /home/apollo/Study/CPP/Homework_1/args/args.cpp

args/CMakeFiles/Args.dir/args.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Args.dir/args.cpp.i"
	cd /home/apollo/Study/CPP/Homework_1/build/args && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apollo/Study/CPP/Homework_1/args/args.cpp > CMakeFiles/Args.dir/args.cpp.i

args/CMakeFiles/Args.dir/args.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Args.dir/args.cpp.s"
	cd /home/apollo/Study/CPP/Homework_1/build/args && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apollo/Study/CPP/Homework_1/args/args.cpp -o CMakeFiles/Args.dir/args.cpp.s

# Object files for target Args
Args_OBJECTS = \
"CMakeFiles/Args.dir/args.cpp.o"

# External object files for target Args
Args_EXTERNAL_OBJECTS =

args/libArgs.a: args/CMakeFiles/Args.dir/args.cpp.o
args/libArgs.a: args/CMakeFiles/Args.dir/build.make
args/libArgs.a: args/CMakeFiles/Args.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/apollo/Study/CPP/Homework_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libArgs.a"
	cd /home/apollo/Study/CPP/Homework_1/build/args && $(CMAKE_COMMAND) -P CMakeFiles/Args.dir/cmake_clean_target.cmake
	cd /home/apollo/Study/CPP/Homework_1/build/args && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Args.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
args/CMakeFiles/Args.dir/build: args/libArgs.a

.PHONY : args/CMakeFiles/Args.dir/build

args/CMakeFiles/Args.dir/clean:
	cd /home/apollo/Study/CPP/Homework_1/build/args && $(CMAKE_COMMAND) -P CMakeFiles/Args.dir/cmake_clean.cmake
.PHONY : args/CMakeFiles/Args.dir/clean

args/CMakeFiles/Args.dir/depend:
	cd /home/apollo/Study/CPP/Homework_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/apollo/Study/CPP/Homework_1 /home/apollo/Study/CPP/Homework_1/args /home/apollo/Study/CPP/Homework_1/build /home/apollo/Study/CPP/Homework_1/build/args /home/apollo/Study/CPP/Homework_1/build/args/CMakeFiles/Args.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : args/CMakeFiles/Args.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shunqingwang/Desktop/github/leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shunqingwang/Desktop/github/leetcode/build

# Include any dependencies generated for this target.
include numberof/CMakeFiles/number_of.dir/depend.make

# Include the progress variables for this target.
include numberof/CMakeFiles/number_of.dir/progress.make

# Include the compile flags for this target's objects.
include numberof/CMakeFiles/number_of.dir/flags.make

numberof/CMakeFiles/number_of.dir/number_of_1.cpp.o: numberof/CMakeFiles/number_of.dir/flags.make
numberof/CMakeFiles/number_of.dir/number_of_1.cpp.o: ../numberof/number_of_1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shunqingwang/Desktop/github/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object numberof/CMakeFiles/number_of.dir/number_of_1.cpp.o"
	cd /Users/shunqingwang/Desktop/github/leetcode/build/numberof && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/number_of.dir/number_of_1.cpp.o -c /Users/shunqingwang/Desktop/github/leetcode/numberof/number_of_1.cpp

numberof/CMakeFiles/number_of.dir/number_of_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/number_of.dir/number_of_1.cpp.i"
	cd /Users/shunqingwang/Desktop/github/leetcode/build/numberof && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shunqingwang/Desktop/github/leetcode/numberof/number_of_1.cpp > CMakeFiles/number_of.dir/number_of_1.cpp.i

numberof/CMakeFiles/number_of.dir/number_of_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/number_of.dir/number_of_1.cpp.s"
	cd /Users/shunqingwang/Desktop/github/leetcode/build/numberof && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shunqingwang/Desktop/github/leetcode/numberof/number_of_1.cpp -o CMakeFiles/number_of.dir/number_of_1.cpp.s

# Object files for target number_of
number_of_OBJECTS = \
"CMakeFiles/number_of.dir/number_of_1.cpp.o"

# External object files for target number_of
number_of_EXTERNAL_OBJECTS =

../bin/number_of: numberof/CMakeFiles/number_of.dir/number_of_1.cpp.o
../bin/number_of: numberof/CMakeFiles/number_of.dir/build.make
../bin/number_of: numberof/CMakeFiles/number_of.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shunqingwang/Desktop/github/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/number_of"
	cd /Users/shunqingwang/Desktop/github/leetcode/build/numberof && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/number_of.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
numberof/CMakeFiles/number_of.dir/build: ../bin/number_of

.PHONY : numberof/CMakeFiles/number_of.dir/build

numberof/CMakeFiles/number_of.dir/clean:
	cd /Users/shunqingwang/Desktop/github/leetcode/build/numberof && $(CMAKE_COMMAND) -P CMakeFiles/number_of.dir/cmake_clean.cmake
.PHONY : numberof/CMakeFiles/number_of.dir/clean

numberof/CMakeFiles/number_of.dir/depend:
	cd /Users/shunqingwang/Desktop/github/leetcode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shunqingwang/Desktop/github/leetcode /Users/shunqingwang/Desktop/github/leetcode/numberof /Users/shunqingwang/Desktop/github/leetcode/build /Users/shunqingwang/Desktop/github/leetcode/build/numberof /Users/shunqingwang/Desktop/github/leetcode/build/numberof/CMakeFiles/number_of.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : numberof/CMakeFiles/number_of.dir/depend

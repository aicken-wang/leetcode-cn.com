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
include reorder_odd_even/CMakeFiles/reorder_odd_even.dir/depend.make

# Include the progress variables for this target.
include reorder_odd_even/CMakeFiles/reorder_odd_even.dir/progress.make

# Include the compile flags for this target's objects.
include reorder_odd_even/CMakeFiles/reorder_odd_even.dir/flags.make

reorder_odd_even/CMakeFiles/reorder_odd_even.dir/reorder_odd_even.cpp.o: reorder_odd_even/CMakeFiles/reorder_odd_even.dir/flags.make
reorder_odd_even/CMakeFiles/reorder_odd_even.dir/reorder_odd_even.cpp.o: ../reorder_odd_even/reorder_odd_even.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shunqingwang/Desktop/github/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object reorder_odd_even/CMakeFiles/reorder_odd_even.dir/reorder_odd_even.cpp.o"
	cd /Users/shunqingwang/Desktop/github/leetcode/build/reorder_odd_even && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reorder_odd_even.dir/reorder_odd_even.cpp.o -c /Users/shunqingwang/Desktop/github/leetcode/reorder_odd_even/reorder_odd_even.cpp

reorder_odd_even/CMakeFiles/reorder_odd_even.dir/reorder_odd_even.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reorder_odd_even.dir/reorder_odd_even.cpp.i"
	cd /Users/shunqingwang/Desktop/github/leetcode/build/reorder_odd_even && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shunqingwang/Desktop/github/leetcode/reorder_odd_even/reorder_odd_even.cpp > CMakeFiles/reorder_odd_even.dir/reorder_odd_even.cpp.i

reorder_odd_even/CMakeFiles/reorder_odd_even.dir/reorder_odd_even.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reorder_odd_even.dir/reorder_odd_even.cpp.s"
	cd /Users/shunqingwang/Desktop/github/leetcode/build/reorder_odd_even && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shunqingwang/Desktop/github/leetcode/reorder_odd_even/reorder_odd_even.cpp -o CMakeFiles/reorder_odd_even.dir/reorder_odd_even.cpp.s

# Object files for target reorder_odd_even
reorder_odd_even_OBJECTS = \
"CMakeFiles/reorder_odd_even.dir/reorder_odd_even.cpp.o"

# External object files for target reorder_odd_even
reorder_odd_even_EXTERNAL_OBJECTS =

../bin/reorder_odd_even: reorder_odd_even/CMakeFiles/reorder_odd_even.dir/reorder_odd_even.cpp.o
../bin/reorder_odd_even: reorder_odd_even/CMakeFiles/reorder_odd_even.dir/build.make
../bin/reorder_odd_even: reorder_odd_even/CMakeFiles/reorder_odd_even.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shunqingwang/Desktop/github/leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/reorder_odd_even"
	cd /Users/shunqingwang/Desktop/github/leetcode/build/reorder_odd_even && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reorder_odd_even.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
reorder_odd_even/CMakeFiles/reorder_odd_even.dir/build: ../bin/reorder_odd_even

.PHONY : reorder_odd_even/CMakeFiles/reorder_odd_even.dir/build

reorder_odd_even/CMakeFiles/reorder_odd_even.dir/clean:
	cd /Users/shunqingwang/Desktop/github/leetcode/build/reorder_odd_even && $(CMAKE_COMMAND) -P CMakeFiles/reorder_odd_even.dir/cmake_clean.cmake
.PHONY : reorder_odd_even/CMakeFiles/reorder_odd_even.dir/clean

reorder_odd_even/CMakeFiles/reorder_odd_even.dir/depend:
	cd /Users/shunqingwang/Desktop/github/leetcode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shunqingwang/Desktop/github/leetcode /Users/shunqingwang/Desktop/github/leetcode/reorder_odd_even /Users/shunqingwang/Desktop/github/leetcode/build /Users/shunqingwang/Desktop/github/leetcode/build/reorder_odd_even /Users/shunqingwang/Desktop/github/leetcode/build/reorder_odd_even/CMakeFiles/reorder_odd_even.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : reorder_odd_even/CMakeFiles/reorder_odd_even.dir/depend

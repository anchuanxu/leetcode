# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/xu/software/Clion/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/xu/software/Clion/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xu/repo/leetcode/Q21_257

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xu/repo/leetcode/Q21_257/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Q21_257.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Q21_257.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Q21_257.dir/flags.make

CMakeFiles/Q21_257.dir/main.cpp.o: CMakeFiles/Q21_257.dir/flags.make
CMakeFiles/Q21_257.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xu/repo/leetcode/Q21_257/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Q21_257.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Q21_257.dir/main.cpp.o -c /home/xu/repo/leetcode/Q21_257/main.cpp

CMakeFiles/Q21_257.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Q21_257.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xu/repo/leetcode/Q21_257/main.cpp > CMakeFiles/Q21_257.dir/main.cpp.i

CMakeFiles/Q21_257.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Q21_257.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xu/repo/leetcode/Q21_257/main.cpp -o CMakeFiles/Q21_257.dir/main.cpp.s

# Object files for target Q21_257
Q21_257_OBJECTS = \
"CMakeFiles/Q21_257.dir/main.cpp.o"

# External object files for target Q21_257
Q21_257_EXTERNAL_OBJECTS =

Q21_257: CMakeFiles/Q21_257.dir/main.cpp.o
Q21_257: CMakeFiles/Q21_257.dir/build.make
Q21_257: CMakeFiles/Q21_257.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xu/repo/leetcode/Q21_257/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Q21_257"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Q21_257.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Q21_257.dir/build: Q21_257

.PHONY : CMakeFiles/Q21_257.dir/build

CMakeFiles/Q21_257.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Q21_257.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Q21_257.dir/clean

CMakeFiles/Q21_257.dir/depend:
	cd /home/xu/repo/leetcode/Q21_257/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xu/repo/leetcode/Q21_257 /home/xu/repo/leetcode/Q21_257 /home/xu/repo/leetcode/Q21_257/cmake-build-debug /home/xu/repo/leetcode/Q21_257/cmake-build-debug /home/xu/repo/leetcode/Q21_257/cmake-build-debug/CMakeFiles/Q21_257.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Q21_257.dir/depend


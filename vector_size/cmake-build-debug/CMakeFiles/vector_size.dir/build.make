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
CMAKE_SOURCE_DIR = /home/xu/repo/leetcode/vector_size

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xu/repo/leetcode/vector_size/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/vector_size.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vector_size.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vector_size.dir/flags.make

CMakeFiles/vector_size.dir/main.cpp.o: CMakeFiles/vector_size.dir/flags.make
CMakeFiles/vector_size.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xu/repo/leetcode/vector_size/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vector_size.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vector_size.dir/main.cpp.o -c /home/xu/repo/leetcode/vector_size/main.cpp

CMakeFiles/vector_size.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector_size.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xu/repo/leetcode/vector_size/main.cpp > CMakeFiles/vector_size.dir/main.cpp.i

CMakeFiles/vector_size.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector_size.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xu/repo/leetcode/vector_size/main.cpp -o CMakeFiles/vector_size.dir/main.cpp.s

# Object files for target vector_size
vector_size_OBJECTS = \
"CMakeFiles/vector_size.dir/main.cpp.o"

# External object files for target vector_size
vector_size_EXTERNAL_OBJECTS =

vector_size: CMakeFiles/vector_size.dir/main.cpp.o
vector_size: CMakeFiles/vector_size.dir/build.make
vector_size: CMakeFiles/vector_size.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xu/repo/leetcode/vector_size/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vector_size"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vector_size.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vector_size.dir/build: vector_size

.PHONY : CMakeFiles/vector_size.dir/build

CMakeFiles/vector_size.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vector_size.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vector_size.dir/clean

CMakeFiles/vector_size.dir/depend:
	cd /home/xu/repo/leetcode/vector_size/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xu/repo/leetcode/vector_size /home/xu/repo/leetcode/vector_size /home/xu/repo/leetcode/vector_size/cmake-build-debug /home/xu/repo/leetcode/vector_size/cmake-build-debug /home/xu/repo/leetcode/vector_size/cmake-build-debug/CMakeFiles/vector_size.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vector_size.dir/depend

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
CMAKE_SOURCE_DIR = /home/xu/repo/leetcode/SizeOf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xu/repo/leetcode/SizeOf/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SizeOf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SizeOf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SizeOf.dir/flags.make

CMakeFiles/SizeOf.dir/main.cpp.o: CMakeFiles/SizeOf.dir/flags.make
CMakeFiles/SizeOf.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xu/repo/leetcode/SizeOf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SizeOf.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SizeOf.dir/main.cpp.o -c /home/xu/repo/leetcode/SizeOf/main.cpp

CMakeFiles/SizeOf.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SizeOf.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xu/repo/leetcode/SizeOf/main.cpp > CMakeFiles/SizeOf.dir/main.cpp.i

CMakeFiles/SizeOf.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SizeOf.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xu/repo/leetcode/SizeOf/main.cpp -o CMakeFiles/SizeOf.dir/main.cpp.s

# Object files for target SizeOf
SizeOf_OBJECTS = \
"CMakeFiles/SizeOf.dir/main.cpp.o"

# External object files for target SizeOf
SizeOf_EXTERNAL_OBJECTS =

SizeOf: CMakeFiles/SizeOf.dir/main.cpp.o
SizeOf: CMakeFiles/SizeOf.dir/build.make
SizeOf: CMakeFiles/SizeOf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xu/repo/leetcode/SizeOf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SizeOf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SizeOf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SizeOf.dir/build: SizeOf

.PHONY : CMakeFiles/SizeOf.dir/build

CMakeFiles/SizeOf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SizeOf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SizeOf.dir/clean

CMakeFiles/SizeOf.dir/depend:
	cd /home/xu/repo/leetcode/SizeOf/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xu/repo/leetcode/SizeOf /home/xu/repo/leetcode/SizeOf /home/xu/repo/leetcode/SizeOf/cmake-build-debug /home/xu/repo/leetcode/SizeOf/cmake-build-debug /home/xu/repo/leetcode/SizeOf/cmake-build-debug/CMakeFiles/SizeOf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SizeOf.dir/depend


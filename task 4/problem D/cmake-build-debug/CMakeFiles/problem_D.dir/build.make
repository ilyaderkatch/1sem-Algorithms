# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/100/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/100/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/dalex/Desktop/1st algo sem/task 4/problem D"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/dalex/Desktop/1st algo sem/task 4/problem D/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/problem_D.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/problem_D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/problem_D.dir/flags.make

CMakeFiles/problem_D.dir/main.cpp.o: CMakeFiles/problem_D.dir/flags.make
CMakeFiles/problem_D.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/dalex/Desktop/1st algo sem/task 4/problem D/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/problem_D.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/problem_D.dir/main.cpp.o -c "/home/dalex/Desktop/1st algo sem/task 4/problem D/main.cpp"

CMakeFiles/problem_D.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problem_D.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/dalex/Desktop/1st algo sem/task 4/problem D/main.cpp" > CMakeFiles/problem_D.dir/main.cpp.i

CMakeFiles/problem_D.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problem_D.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/dalex/Desktop/1st algo sem/task 4/problem D/main.cpp" -o CMakeFiles/problem_D.dir/main.cpp.s

# Object files for target problem_D
problem_D_OBJECTS = \
"CMakeFiles/problem_D.dir/main.cpp.o"

# External object files for target problem_D
problem_D_EXTERNAL_OBJECTS =

problem_D: CMakeFiles/problem_D.dir/main.cpp.o
problem_D: CMakeFiles/problem_D.dir/build.make
problem_D: CMakeFiles/problem_D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/dalex/Desktop/1st algo sem/task 4/problem D/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable problem_D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/problem_D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/problem_D.dir/build: problem_D

.PHONY : CMakeFiles/problem_D.dir/build

CMakeFiles/problem_D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/problem_D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/problem_D.dir/clean

CMakeFiles/problem_D.dir/depend:
	cd "/home/dalex/Desktop/1st algo sem/task 4/problem D/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/dalex/Desktop/1st algo sem/task 4/problem D" "/home/dalex/Desktop/1st algo sem/task 4/problem D" "/home/dalex/Desktop/1st algo sem/task 4/problem D/cmake-build-debug" "/home/dalex/Desktop/1st algo sem/task 4/problem D/cmake-build-debug" "/home/dalex/Desktop/1st algo sem/task 4/problem D/cmake-build-debug/CMakeFiles/problem_D.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/problem_D.dir/depend

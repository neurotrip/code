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
CMAKE_SOURCE_DIR = /home/code/TestApp/build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/code/TestApp/build

# Include any dependencies generated for this target.
include CMakeFiles/TestApp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestApp.dir/flags.make

CMakeFiles/TestApp.dir/v3_program.c.o: CMakeFiles/TestApp.dir/flags.make
CMakeFiles/TestApp.dir/v3_program.c.o: v3_program.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/code/TestApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TestApp.dir/v3_program.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TestApp.dir/v3_program.c.o   -c /home/code/TestApp/build/v3_program.c

CMakeFiles/TestApp.dir/v3_program.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TestApp.dir/v3_program.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/code/TestApp/build/v3_program.c > CMakeFiles/TestApp.dir/v3_program.c.i

CMakeFiles/TestApp.dir/v3_program.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TestApp.dir/v3_program.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/code/TestApp/build/v3_program.c -o CMakeFiles/TestApp.dir/v3_program.c.s

# Object files for target TestApp
TestApp_OBJECTS = \
"CMakeFiles/TestApp.dir/v3_program.c.o"

# External object files for target TestApp
TestApp_EXTERNAL_OBJECTS =

TestApp: CMakeFiles/TestApp.dir/v3_program.c.o
TestApp: CMakeFiles/TestApp.dir/build.make
TestApp: CMakeFiles/TestApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/code/TestApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable TestApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestApp.dir/build: TestApp

.PHONY : CMakeFiles/TestApp.dir/build

CMakeFiles/TestApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestApp.dir/clean

CMakeFiles/TestApp.dir/depend:
	cd /home/code/TestApp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/code/TestApp/build /home/code/TestApp/build /home/code/TestApp/build /home/code/TestApp/build /home/code/TestApp/build/CMakeFiles/TestApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestApp.dir/depend

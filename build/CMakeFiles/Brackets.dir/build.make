# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/joshua/c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joshua/c/build

# Include any dependencies generated for this target.
include CMakeFiles/Brackets.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Brackets.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Brackets.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Brackets.dir/flags.make

CMakeFiles/Brackets.dir/Brackets.c.o: CMakeFiles/Brackets.dir/flags.make
CMakeFiles/Brackets.dir/Brackets.c.o: ../Brackets.c
CMakeFiles/Brackets.dir/Brackets.c.o: CMakeFiles/Brackets.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joshua/c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Brackets.dir/Brackets.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Brackets.dir/Brackets.c.o -MF CMakeFiles/Brackets.dir/Brackets.c.o.d -o CMakeFiles/Brackets.dir/Brackets.c.o -c /home/joshua/c/Brackets.c

CMakeFiles/Brackets.dir/Brackets.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Brackets.dir/Brackets.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/joshua/c/Brackets.c > CMakeFiles/Brackets.dir/Brackets.c.i

CMakeFiles/Brackets.dir/Brackets.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Brackets.dir/Brackets.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/joshua/c/Brackets.c -o CMakeFiles/Brackets.dir/Brackets.c.s

# Object files for target Brackets
Brackets_OBJECTS = \
"CMakeFiles/Brackets.dir/Brackets.c.o"

# External object files for target Brackets
Brackets_EXTERNAL_OBJECTS =

Brackets: CMakeFiles/Brackets.dir/Brackets.c.o
Brackets: CMakeFiles/Brackets.dir/build.make
Brackets: CMakeFiles/Brackets.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joshua/c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Brackets"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Brackets.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Brackets.dir/build: Brackets
.PHONY : CMakeFiles/Brackets.dir/build

CMakeFiles/Brackets.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Brackets.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Brackets.dir/clean

CMakeFiles/Brackets.dir/depend:
	cd /home/joshua/c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joshua/c /home/joshua/c /home/joshua/c/build /home/joshua/c/build /home/joshua/c/build/CMakeFiles/Brackets.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Brackets.dir/depend

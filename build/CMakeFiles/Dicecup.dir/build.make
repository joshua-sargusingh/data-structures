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
include CMakeFiles/Dicecup.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Dicecup.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Dicecup.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Dicecup.dir/flags.make

CMakeFiles/Dicecup.dir/Dicecup.c.o: CMakeFiles/Dicecup.dir/flags.make
CMakeFiles/Dicecup.dir/Dicecup.c.o: ../Dicecup.c
CMakeFiles/Dicecup.dir/Dicecup.c.o: CMakeFiles/Dicecup.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joshua/c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Dicecup.dir/Dicecup.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Dicecup.dir/Dicecup.c.o -MF CMakeFiles/Dicecup.dir/Dicecup.c.o.d -o CMakeFiles/Dicecup.dir/Dicecup.c.o -c /home/joshua/c/Dicecup.c

CMakeFiles/Dicecup.dir/Dicecup.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Dicecup.dir/Dicecup.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/joshua/c/Dicecup.c > CMakeFiles/Dicecup.dir/Dicecup.c.i

CMakeFiles/Dicecup.dir/Dicecup.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Dicecup.dir/Dicecup.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/joshua/c/Dicecup.c -o CMakeFiles/Dicecup.dir/Dicecup.c.s

# Object files for target Dicecup
Dicecup_OBJECTS = \
"CMakeFiles/Dicecup.dir/Dicecup.c.o"

# External object files for target Dicecup
Dicecup_EXTERNAL_OBJECTS =

Dicecup: CMakeFiles/Dicecup.dir/Dicecup.c.o
Dicecup: CMakeFiles/Dicecup.dir/build.make
Dicecup: CMakeFiles/Dicecup.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joshua/c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Dicecup"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Dicecup.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Dicecup.dir/build: Dicecup
.PHONY : CMakeFiles/Dicecup.dir/build

CMakeFiles/Dicecup.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Dicecup.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Dicecup.dir/clean

CMakeFiles/Dicecup.dir/depend:
	cd /home/joshua/c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joshua/c /home/joshua/c /home/joshua/c/build /home/joshua/c/build /home/joshua/c/build/CMakeFiles/Dicecup.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Dicecup.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /snap/cmake/1364/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1364/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/Piotrek/CLionProjects/untitled116

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Piotrek/CLionProjects/untitled116/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled116.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/untitled116.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled116.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled116.dir/flags.make

CMakeFiles/untitled116.dir/main.c.o: CMakeFiles/untitled116.dir/flags.make
CMakeFiles/untitled116.dir/main.c.o: /mnt/c/Users/Piotrek/CLionProjects/untitled116/main.c
CMakeFiles/untitled116.dir/main.c.o: CMakeFiles/untitled116.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Piotrek/CLionProjects/untitled116/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled116.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled116.dir/main.c.o -MF CMakeFiles/untitled116.dir/main.c.o.d -o CMakeFiles/untitled116.dir/main.c.o -c /mnt/c/Users/Piotrek/CLionProjects/untitled116/main.c

CMakeFiles/untitled116.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/untitled116.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Piotrek/CLionProjects/untitled116/main.c > CMakeFiles/untitled116.dir/main.c.i

CMakeFiles/untitled116.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/untitled116.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Piotrek/CLionProjects/untitled116/main.c -o CMakeFiles/untitled116.dir/main.c.s

# Object files for target untitled116
untitled116_OBJECTS = \
"CMakeFiles/untitled116.dir/main.c.o"

# External object files for target untitled116
untitled116_EXTERNAL_OBJECTS =

untitled116: CMakeFiles/untitled116.dir/main.c.o
untitled116: CMakeFiles/untitled116.dir/build.make
untitled116: CMakeFiles/untitled116.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/c/Users/Piotrek/CLionProjects/untitled116/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable untitled116"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled116.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled116.dir/build: untitled116
.PHONY : CMakeFiles/untitled116.dir/build

CMakeFiles/untitled116.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled116.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled116.dir/clean

CMakeFiles/untitled116.dir/depend:
	cd /mnt/c/Users/Piotrek/CLionProjects/untitled116/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Piotrek/CLionProjects/untitled116 /mnt/c/Users/Piotrek/CLionProjects/untitled116 /mnt/c/Users/Piotrek/CLionProjects/untitled116/cmake-build-debug /mnt/c/Users/Piotrek/CLionProjects/untitled116/cmake-build-debug /mnt/c/Users/Piotrek/CLionProjects/untitled116/cmake-build-debug/CMakeFiles/untitled116.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/untitled116.dir/depend


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
CMAKE_COMMAND = /clion-2019.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /clion-2019.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/masaadkhan/Documents/312/Labs/Project3_starter_files/Tester

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/masaadkhan/Documents/312/Labs/Project3_starter_files/Tester/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tester.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tester.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tester.dir/flags.make

CMakeFiles/Tester.dir/strrealloc.c.o: CMakeFiles/Tester.dir/flags.make
CMakeFiles/Tester.dir/strrealloc.c.o: ../strrealloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masaadkhan/Documents/312/Labs/Project3_starter_files/Tester/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Tester.dir/strrealloc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tester.dir/strrealloc.c.o   -c /home/masaadkhan/Documents/312/Labs/Project3_starter_files/Tester/strrealloc.c

CMakeFiles/Tester.dir/strrealloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tester.dir/strrealloc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/masaadkhan/Documents/312/Labs/Project3_starter_files/Tester/strrealloc.c > CMakeFiles/Tester.dir/strrealloc.c.i

CMakeFiles/Tester.dir/strrealloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tester.dir/strrealloc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/masaadkhan/Documents/312/Labs/Project3_starter_files/Tester/strrealloc.c -o CMakeFiles/Tester.dir/strrealloc.c.s

# Object files for target Tester
Tester_OBJECTS = \
"CMakeFiles/Tester.dir/strrealloc.c.o"

# External object files for target Tester
Tester_EXTERNAL_OBJECTS =

Tester: CMakeFiles/Tester.dir/strrealloc.c.o
Tester: CMakeFiles/Tester.dir/build.make
Tester: CMakeFiles/Tester.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/masaadkhan/Documents/312/Labs/Project3_starter_files/Tester/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Tester"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tester.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tester.dir/build: Tester

.PHONY : CMakeFiles/Tester.dir/build

CMakeFiles/Tester.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tester.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tester.dir/clean

CMakeFiles/Tester.dir/depend:
	cd /home/masaadkhan/Documents/312/Labs/Project3_starter_files/Tester/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/masaadkhan/Documents/312/Labs/Project3_starter_files/Tester /home/masaadkhan/Documents/312/Labs/Project3_starter_files/Tester /home/masaadkhan/Documents/312/Labs/Project3_starter_files/Tester/cmake-build-debug /home/masaadkhan/Documents/312/Labs/Project3_starter_files/Tester/cmake-build-debug /home/masaadkhan/Documents/312/Labs/Project3_starter_files/Tester/cmake-build-debug/CMakeFiles/Tester.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tester.dir/depend

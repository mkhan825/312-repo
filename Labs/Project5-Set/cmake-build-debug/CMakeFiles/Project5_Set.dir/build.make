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
CMAKE_SOURCE_DIR = /home/masaadkhan/Documents/312/Labs/Project5-Set

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/masaadkhan/Documents/312/Labs/Project5-Set/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project5_Set.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project5_Set.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project5_Set.dir/flags.make

CMakeFiles/Project5_Set.dir/Project5_starter_files/main.cpp.o: CMakeFiles/Project5_Set.dir/flags.make
CMakeFiles/Project5_Set.dir/Project5_starter_files/main.cpp.o: ../Project5_starter_files/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masaadkhan/Documents/312/Labs/Project5-Set/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project5_Set.dir/Project5_starter_files/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project5_Set.dir/Project5_starter_files/main.cpp.o -c /home/masaadkhan/Documents/312/Labs/Project5-Set/Project5_starter_files/main.cpp

CMakeFiles/Project5_Set.dir/Project5_starter_files/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project5_Set.dir/Project5_starter_files/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/masaadkhan/Documents/312/Labs/Project5-Set/Project5_starter_files/main.cpp > CMakeFiles/Project5_Set.dir/Project5_starter_files/main.cpp.i

CMakeFiles/Project5_Set.dir/Project5_starter_files/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project5_Set.dir/Project5_starter_files/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/masaadkhan/Documents/312/Labs/Project5-Set/Project5_starter_files/main.cpp -o CMakeFiles/Project5_Set.dir/Project5_starter_files/main.cpp.s

CMakeFiles/Project5_Set.dir/Project5_starter_files/Project5.cpp.o: CMakeFiles/Project5_Set.dir/flags.make
CMakeFiles/Project5_Set.dir/Project5_starter_files/Project5.cpp.o: ../Project5_starter_files/Project5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masaadkhan/Documents/312/Labs/Project5-Set/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project5_Set.dir/Project5_starter_files/Project5.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project5_Set.dir/Project5_starter_files/Project5.cpp.o -c /home/masaadkhan/Documents/312/Labs/Project5-Set/Project5_starter_files/Project5.cpp

CMakeFiles/Project5_Set.dir/Project5_starter_files/Project5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project5_Set.dir/Project5_starter_files/Project5.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/masaadkhan/Documents/312/Labs/Project5-Set/Project5_starter_files/Project5.cpp > CMakeFiles/Project5_Set.dir/Project5_starter_files/Project5.cpp.i

CMakeFiles/Project5_Set.dir/Project5_starter_files/Project5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project5_Set.dir/Project5_starter_files/Project5.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/masaadkhan/Documents/312/Labs/Project5-Set/Project5_starter_files/Project5.cpp -o CMakeFiles/Project5_Set.dir/Project5_starter_files/Project5.cpp.s

# Object files for target Project5_Set
Project5_Set_OBJECTS = \
"CMakeFiles/Project5_Set.dir/Project5_starter_files/main.cpp.o" \
"CMakeFiles/Project5_Set.dir/Project5_starter_files/Project5.cpp.o"

# External object files for target Project5_Set
Project5_Set_EXTERNAL_OBJECTS =

Project5_Set: CMakeFiles/Project5_Set.dir/Project5_starter_files/main.cpp.o
Project5_Set: CMakeFiles/Project5_Set.dir/Project5_starter_files/Project5.cpp.o
Project5_Set: CMakeFiles/Project5_Set.dir/build.make
Project5_Set: CMakeFiles/Project5_Set.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/masaadkhan/Documents/312/Labs/Project5-Set/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Project5_Set"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project5_Set.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project5_Set.dir/build: Project5_Set

.PHONY : CMakeFiles/Project5_Set.dir/build

CMakeFiles/Project5_Set.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project5_Set.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project5_Set.dir/clean

CMakeFiles/Project5_Set.dir/depend:
	cd /home/masaadkhan/Documents/312/Labs/Project5-Set/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/masaadkhan/Documents/312/Labs/Project5-Set /home/masaadkhan/Documents/312/Labs/Project5-Set /home/masaadkhan/Documents/312/Labs/Project5-Set/cmake-build-debug /home/masaadkhan/Documents/312/Labs/Project5-Set/cmake-build-debug /home/masaadkhan/Documents/312/Labs/Project5-Set/cmake-build-debug/CMakeFiles/Project5_Set.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project5_Set.dir/depend

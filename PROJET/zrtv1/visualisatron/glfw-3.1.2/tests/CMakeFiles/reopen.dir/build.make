# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /nfs/sgoinfre/goinfre/Perso/alelievr/homebrew/Cellar/cmake/3.4.2/bin/cmake

# The command to remove a file.
RM = /nfs/sgoinfre/goinfre/Perso/alelievr/homebrew/Cellar/cmake/3.4.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests

# Include any dependencies generated for this target.
include CMakeFiles/reopen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/reopen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reopen.dir/flags.make

CMakeFiles/reopen.dir/reopen.o: CMakeFiles/reopen.dir/flags.make
CMakeFiles/reopen.dir/reopen.o: reopen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/reopen.dir/reopen.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/reopen.dir/reopen.o   -c /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests/reopen.c

CMakeFiles/reopen.dir/reopen.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/reopen.dir/reopen.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests/reopen.c > CMakeFiles/reopen.dir/reopen.i

CMakeFiles/reopen.dir/reopen.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/reopen.dir/reopen.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests/reopen.c -o CMakeFiles/reopen.dir/reopen.s

CMakeFiles/reopen.dir/reopen.o.requires:

.PHONY : CMakeFiles/reopen.dir/reopen.o.requires

CMakeFiles/reopen.dir/reopen.o.provides: CMakeFiles/reopen.dir/reopen.o.requires
	$(MAKE) -f CMakeFiles/reopen.dir/build.make CMakeFiles/reopen.dir/reopen.o.provides.build
.PHONY : CMakeFiles/reopen.dir/reopen.o.provides

CMakeFiles/reopen.dir/reopen.o.provides.build: CMakeFiles/reopen.dir/reopen.o


# Object files for target reopen
reopen_OBJECTS = \
"CMakeFiles/reopen.dir/reopen.o"

# External object files for target reopen
reopen_EXTERNAL_OBJECTS =

reopen: CMakeFiles/reopen.dir/reopen.o
reopen: CMakeFiles/reopen.dir/build.make
reopen: CMakeFiles/reopen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable reopen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reopen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reopen.dir/build: reopen

.PHONY : CMakeFiles/reopen.dir/build

CMakeFiles/reopen.dir/requires: CMakeFiles/reopen.dir/reopen.o.requires

.PHONY : CMakeFiles/reopen.dir/requires

CMakeFiles/reopen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reopen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reopen.dir/clean

CMakeFiles/reopen.dir/depend:
	cd /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests/CMakeFiles/reopen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/reopen.dir/depend

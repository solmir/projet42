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
include CMakeFiles/windows.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/windows.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/windows.dir/flags.make

CMakeFiles/windows.dir/windows.o: CMakeFiles/windows.dir/flags.make
CMakeFiles/windows.dir/windows.o: windows.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/windows.dir/windows.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/windows.dir/windows.o   -c /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests/windows.c

CMakeFiles/windows.dir/windows.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/windows.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests/windows.c > CMakeFiles/windows.dir/windows.i

CMakeFiles/windows.dir/windows.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/windows.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests/windows.c -o CMakeFiles/windows.dir/windows.s

CMakeFiles/windows.dir/windows.o.requires:

.PHONY : CMakeFiles/windows.dir/windows.o.requires

CMakeFiles/windows.dir/windows.o.provides: CMakeFiles/windows.dir/windows.o.requires
	$(MAKE) -f CMakeFiles/windows.dir/build.make CMakeFiles/windows.dir/windows.o.provides.build
.PHONY : CMakeFiles/windows.dir/windows.o.provides

CMakeFiles/windows.dir/windows.o.provides.build: CMakeFiles/windows.dir/windows.o


# Object files for target windows
windows_OBJECTS = \
"CMakeFiles/windows.dir/windows.o"

# External object files for target windows
windows_EXTERNAL_OBJECTS =

windows.app/Contents/MacOS/windows: CMakeFiles/windows.dir/windows.o
windows.app/Contents/MacOS/windows: CMakeFiles/windows.dir/build.make
windows.app/Contents/MacOS/windows: CMakeFiles/windows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable windows.app/Contents/MacOS/windows"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/windows.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/windows.dir/build: windows.app/Contents/MacOS/windows

.PHONY : CMakeFiles/windows.dir/build

CMakeFiles/windows.dir/requires: CMakeFiles/windows.dir/windows.o.requires

.PHONY : CMakeFiles/windows.dir/requires

CMakeFiles/windows.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/windows.dir/cmake_clean.cmake
.PHONY : CMakeFiles/windows.dir/clean

CMakeFiles/windows.dir/depend:
	cd /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests /nfs/zfs-student-2/users/alelievr/c/corewar/visualisatron/glfw-3.1.2/tests/CMakeFiles/windows.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/windows.dir/depend


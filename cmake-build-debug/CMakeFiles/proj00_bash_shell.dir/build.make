# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/bahamut/Installations/clion-2017.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/bahamut/Installations/clion-2017.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bahamut/ClionProjects/ubiquitous-octo-computing-machine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bahamut/ClionProjects/ubiquitous-octo-computing-machine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proj00_bash_shell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proj00_bash_shell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj00_bash_shell.dir/flags.make

CMakeFiles/proj00_bash_shell.dir/commandline.c.o: CMakeFiles/proj00_bash_shell.dir/flags.make
CMakeFiles/proj00_bash_shell.dir/commandline.c.o: ../commandline.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bahamut/ClionProjects/ubiquitous-octo-computing-machine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/proj00_bash_shell.dir/commandline.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/proj00_bash_shell.dir/commandline.c.o   -c /home/bahamut/ClionProjects/ubiquitous-octo-computing-machine/commandline.c

CMakeFiles/proj00_bash_shell.dir/commandline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/proj00_bash_shell.dir/commandline.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bahamut/ClionProjects/ubiquitous-octo-computing-machine/commandline.c > CMakeFiles/proj00_bash_shell.dir/commandline.c.i

CMakeFiles/proj00_bash_shell.dir/commandline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/proj00_bash_shell.dir/commandline.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bahamut/ClionProjects/ubiquitous-octo-computing-machine/commandline.c -o CMakeFiles/proj00_bash_shell.dir/commandline.c.s

CMakeFiles/proj00_bash_shell.dir/commandline.c.o.requires:

.PHONY : CMakeFiles/proj00_bash_shell.dir/commandline.c.o.requires

CMakeFiles/proj00_bash_shell.dir/commandline.c.o.provides: CMakeFiles/proj00_bash_shell.dir/commandline.c.o.requires
	$(MAKE) -f CMakeFiles/proj00_bash_shell.dir/build.make CMakeFiles/proj00_bash_shell.dir/commandline.c.o.provides.build
.PHONY : CMakeFiles/proj00_bash_shell.dir/commandline.c.o.provides

CMakeFiles/proj00_bash_shell.dir/commandline.c.o.provides.build: CMakeFiles/proj00_bash_shell.dir/commandline.c.o


# Object files for target proj00_bash_shell
proj00_bash_shell_OBJECTS = \
"CMakeFiles/proj00_bash_shell.dir/commandline.c.o"

# External object files for target proj00_bash_shell
proj00_bash_shell_EXTERNAL_OBJECTS =

proj00_bash_shell: CMakeFiles/proj00_bash_shell.dir/commandline.c.o
proj00_bash_shell: CMakeFiles/proj00_bash_shell.dir/build.make
proj00_bash_shell: CMakeFiles/proj00_bash_shell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bahamut/ClionProjects/ubiquitous-octo-computing-machine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable proj00_bash_shell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proj00_bash_shell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj00_bash_shell.dir/build: proj00_bash_shell

.PHONY : CMakeFiles/proj00_bash_shell.dir/build

CMakeFiles/proj00_bash_shell.dir/requires: CMakeFiles/proj00_bash_shell.dir/commandline.c.o.requires

.PHONY : CMakeFiles/proj00_bash_shell.dir/requires

CMakeFiles/proj00_bash_shell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proj00_bash_shell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proj00_bash_shell.dir/clean

CMakeFiles/proj00_bash_shell.dir/depend:
	cd /home/bahamut/ClionProjects/ubiquitous-octo-computing-machine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bahamut/ClionProjects/ubiquitous-octo-computing-machine /home/bahamut/ClionProjects/ubiquitous-octo-computing-machine /home/bahamut/ClionProjects/ubiquitous-octo-computing-machine/cmake-build-debug /home/bahamut/ClionProjects/ubiquitous-octo-computing-machine/cmake-build-debug /home/bahamut/ClionProjects/ubiquitous-octo-computing-machine/cmake-build-debug/CMakeFiles/proj00_bash_shell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proj00_bash_shell.dir/depend

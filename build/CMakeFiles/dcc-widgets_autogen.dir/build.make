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
CMAKE_SOURCE_DIR = /home/pundthsea/Desktop/os-final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pundthsea/Desktop/os-final/build

# Utility rule file for dcc-widgets_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/dcc-widgets_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dcc-widgets_autogen.dir/progress.make

CMakeFiles/dcc-widgets_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pundthsea/Desktop/os-final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target dcc-widgets"
	/usr/bin/cmake -E cmake_autogen /home/pundthsea/Desktop/os-final/build/CMakeFiles/dcc-widgets_autogen.dir/AutogenInfo.json ""

dcc-widgets_autogen: CMakeFiles/dcc-widgets_autogen
dcc-widgets_autogen: CMakeFiles/dcc-widgets_autogen.dir/build.make
.PHONY : dcc-widgets_autogen

# Rule to build all files generated by this target.
CMakeFiles/dcc-widgets_autogen.dir/build: dcc-widgets_autogen
.PHONY : CMakeFiles/dcc-widgets_autogen.dir/build

CMakeFiles/dcc-widgets_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dcc-widgets_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dcc-widgets_autogen.dir/clean

CMakeFiles/dcc-widgets_autogen.dir/depend:
	cd /home/pundthsea/Desktop/os-final/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pundthsea/Desktop/os-final /home/pundthsea/Desktop/os-final /home/pundthsea/Desktop/os-final/build /home/pundthsea/Desktop/os-final/build /home/pundthsea/Desktop/os-final/build/CMakeFiles/dcc-widgets_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dcc-widgets_autogen.dir/depend


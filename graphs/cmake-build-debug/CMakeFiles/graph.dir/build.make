# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\nik1m\Desktop\C\2\graphs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\nik1m\Desktop\C\2\graphs\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/graph.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/graph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graph.dir/flags.make

CMakeFiles/graph.dir/graph.c.obj: CMakeFiles/graph.dir/flags.make
CMakeFiles/graph.dir/graph.c.obj: ../graph.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nik1m\Desktop\C\2\graphs\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/graph.dir/graph.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\graph.dir\graph.c.obj -c C:\Users\nik1m\Desktop\C\2\graphs\graph.c

CMakeFiles/graph.dir/graph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/graph.dir/graph.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\nik1m\Desktop\C\2\graphs\graph.c > CMakeFiles\graph.dir\graph.c.i

CMakeFiles/graph.dir/graph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/graph.dir/graph.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\nik1m\Desktop\C\2\graphs\graph.c -o CMakeFiles\graph.dir\graph.c.s

CMakeFiles/graph.dir/main.c.obj: CMakeFiles/graph.dir/flags.make
CMakeFiles/graph.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nik1m\Desktop\C\2\graphs\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/graph.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\graph.dir\main.c.obj -c C:\Users\nik1m\Desktop\C\2\graphs\main.c

CMakeFiles/graph.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/graph.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\nik1m\Desktop\C\2\graphs\main.c > CMakeFiles\graph.dir\main.c.i

CMakeFiles/graph.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/graph.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\nik1m\Desktop\C\2\graphs\main.c -o CMakeFiles\graph.dir\main.c.s

# Object files for target graph
graph_OBJECTS = \
"CMakeFiles/graph.dir/graph.c.obj" \
"CMakeFiles/graph.dir/main.c.obj"

# External object files for target graph
graph_EXTERNAL_OBJECTS =

graph.exe: CMakeFiles/graph.dir/graph.c.obj
graph.exe: CMakeFiles/graph.dir/main.c.obj
graph.exe: CMakeFiles/graph.dir/build.make
graph.exe: CMakeFiles/graph.dir/linklibs.rsp
graph.exe: CMakeFiles/graph.dir/objects1.rsp
graph.exe: CMakeFiles/graph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\nik1m\Desktop\C\2\graphs\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable graph.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\graph.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graph.dir/build: graph.exe
.PHONY : CMakeFiles/graph.dir/build

CMakeFiles/graph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\graph.dir\cmake_clean.cmake
.PHONY : CMakeFiles/graph.dir/clean

CMakeFiles/graph.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\nik1m\Desktop\C\2\graphs C:\Users\nik1m\Desktop\C\2\graphs C:\Users\nik1m\Desktop\C\2\graphs\cmake-build-debug C:\Users\nik1m\Desktop\C\2\graphs\cmake-build-debug C:\Users\nik1m\Desktop\C\2\graphs\cmake-build-debug\CMakeFiles\graph.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graph.dir/depend


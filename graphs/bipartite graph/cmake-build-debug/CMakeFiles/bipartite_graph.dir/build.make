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
CMAKE_SOURCE_DIR = "C:\Users\nik1m\Desktop\C\2\graphs\bipartite graph"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\nik1m\Desktop\C\2\graphs\bipartite graph\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/bipartite_graph.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/bipartite_graph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bipartite_graph.dir/flags.make

CMakeFiles/bipartite_graph.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.obj: CMakeFiles/bipartite_graph.dir/flags.make
CMakeFiles/bipartite_graph.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.obj: C:/Users/nik1m/Desktop/C/2/graphs/graph.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\nik1m\Desktop\C\2\graphs\bipartite graph\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bipartite_graph.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bipartite_graph.dir\C_\Users\nik1m\Desktop\C\2\graphs\graph.c.obj -c C:\Users\nik1m\Desktop\C\2\graphs\graph.c

CMakeFiles/bipartite_graph.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bipartite_graph.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\nik1m\Desktop\C\2\graphs\graph.c > CMakeFiles\bipartite_graph.dir\C_\Users\nik1m\Desktop\C\2\graphs\graph.c.i

CMakeFiles/bipartite_graph.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bipartite_graph.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\nik1m\Desktop\C\2\graphs\graph.c -o CMakeFiles\bipartite_graph.dir\C_\Users\nik1m\Desktop\C\2\graphs\graph.c.s

CMakeFiles/bipartite_graph.dir/main.c.obj: CMakeFiles/bipartite_graph.dir/flags.make
CMakeFiles/bipartite_graph.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\nik1m\Desktop\C\2\graphs\bipartite graph\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/bipartite_graph.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\bipartite_graph.dir\main.c.obj -c "C:\Users\nik1m\Desktop\C\2\graphs\bipartite graph\main.c"

CMakeFiles/bipartite_graph.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bipartite_graph.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\nik1m\Desktop\C\2\graphs\bipartite graph\main.c" > CMakeFiles\bipartite_graph.dir\main.c.i

CMakeFiles/bipartite_graph.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bipartite_graph.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\nik1m\Desktop\C\2\graphs\bipartite graph\main.c" -o CMakeFiles\bipartite_graph.dir\main.c.s

# Object files for target bipartite_graph
bipartite_graph_OBJECTS = \
"CMakeFiles/bipartite_graph.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.obj" \
"CMakeFiles/bipartite_graph.dir/main.c.obj"

# External object files for target bipartite_graph
bipartite_graph_EXTERNAL_OBJECTS =

bipartite_graph.exe: CMakeFiles/bipartite_graph.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.obj
bipartite_graph.exe: CMakeFiles/bipartite_graph.dir/main.c.obj
bipartite_graph.exe: CMakeFiles/bipartite_graph.dir/build.make
bipartite_graph.exe: CMakeFiles/bipartite_graph.dir/linklibs.rsp
bipartite_graph.exe: CMakeFiles/bipartite_graph.dir/objects1.rsp
bipartite_graph.exe: CMakeFiles/bipartite_graph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\nik1m\Desktop\C\2\graphs\bipartite graph\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable bipartite_graph.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bipartite_graph.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bipartite_graph.dir/build: bipartite_graph.exe
.PHONY : CMakeFiles/bipartite_graph.dir/build

CMakeFiles/bipartite_graph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bipartite_graph.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bipartite_graph.dir/clean

CMakeFiles/bipartite_graph.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\nik1m\Desktop\C\2\graphs\bipartite graph" "C:\Users\nik1m\Desktop\C\2\graphs\bipartite graph" "C:\Users\nik1m\Desktop\C\2\graphs\bipartite graph\cmake-build-debug" "C:\Users\nik1m\Desktop\C\2\graphs\bipartite graph\cmake-build-debug" "C:\Users\nik1m\Desktop\C\2\graphs\bipartite graph\cmake-build-debug\CMakeFiles\bipartite_graph.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/bipartite_graph.dir/depend

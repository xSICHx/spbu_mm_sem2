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
CMAKE_SOURCE_DIR = "C:\Users\nik1m\Desktop\C\2\graphs\graphs and files"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\nik1m\Desktop\C\2\graphs\graphs and files\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/graphs_and_files.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/graphs_and_files.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graphs_and_files.dir/flags.make

CMakeFiles/graphs_and_files.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.obj: CMakeFiles/graphs_and_files.dir/flags.make
CMakeFiles/graphs_and_files.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.obj: C:/Users/nik1m/Desktop/C/2/graphs/graph.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\nik1m\Desktop\C\2\graphs\graphs and files\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/graphs_and_files.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\graphs_and_files.dir\C_\Users\nik1m\Desktop\C\2\graphs\graph.c.obj -c C:\Users\nik1m\Desktop\C\2\graphs\graph.c

CMakeFiles/graphs_and_files.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/graphs_and_files.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\nik1m\Desktop\C\2\graphs\graph.c > CMakeFiles\graphs_and_files.dir\C_\Users\nik1m\Desktop\C\2\graphs\graph.c.i

CMakeFiles/graphs_and_files.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/graphs_and_files.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\nik1m\Desktop\C\2\graphs\graph.c -o CMakeFiles\graphs_and_files.dir\C_\Users\nik1m\Desktop\C\2\graphs\graph.c.s

CMakeFiles/graphs_and_files.dir/main.c.obj: CMakeFiles/graphs_and_files.dir/flags.make
CMakeFiles/graphs_and_files.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\nik1m\Desktop\C\2\graphs\graphs and files\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/graphs_and_files.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\graphs_and_files.dir\main.c.obj -c "C:\Users\nik1m\Desktop\C\2\graphs\graphs and files\main.c"

CMakeFiles/graphs_and_files.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/graphs_and_files.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\nik1m\Desktop\C\2\graphs\graphs and files\main.c" > CMakeFiles\graphs_and_files.dir\main.c.i

CMakeFiles/graphs_and_files.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/graphs_and_files.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\nik1m\Desktop\C\2\graphs\graphs and files\main.c" -o CMakeFiles\graphs_and_files.dir\main.c.s

# Object files for target graphs_and_files
graphs_and_files_OBJECTS = \
"CMakeFiles/graphs_and_files.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.obj" \
"CMakeFiles/graphs_and_files.dir/main.c.obj"

# External object files for target graphs_and_files
graphs_and_files_EXTERNAL_OBJECTS =

graphs_and_files.exe: CMakeFiles/graphs_and_files.dir/C_/Users/nik1m/Desktop/C/2/graphs/graph.c.obj
graphs_and_files.exe: CMakeFiles/graphs_and_files.dir/main.c.obj
graphs_and_files.exe: CMakeFiles/graphs_and_files.dir/build.make
graphs_and_files.exe: CMakeFiles/graphs_and_files.dir/linklibs.rsp
graphs_and_files.exe: CMakeFiles/graphs_and_files.dir/objects1.rsp
graphs_and_files.exe: CMakeFiles/graphs_and_files.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\nik1m\Desktop\C\2\graphs\graphs and files\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable graphs_and_files.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\graphs_and_files.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graphs_and_files.dir/build: graphs_and_files.exe
.PHONY : CMakeFiles/graphs_and_files.dir/build

CMakeFiles/graphs_and_files.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\graphs_and_files.dir\cmake_clean.cmake
.PHONY : CMakeFiles/graphs_and_files.dir/clean

CMakeFiles/graphs_and_files.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\nik1m\Desktop\C\2\graphs\graphs and files" "C:\Users\nik1m\Desktop\C\2\graphs\graphs and files" "C:\Users\nik1m\Desktop\C\2\graphs\graphs and files\cmake-build-debug" "C:\Users\nik1m\Desktop\C\2\graphs\graphs and files\cmake-build-debug" "C:\Users\nik1m\Desktop\C\2\graphs\graphs and files\cmake-build-debug\CMakeFiles\graphs_and_files.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/graphs_and_files.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\C++primer\cppprimer\chapter 8\ex8.4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\C++primer\cppprimer\chapter 8\ex8.4\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ex8_4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex8_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex8_4.dir/flags.make

CMakeFiles/ex8_4.dir/main.cpp.obj: CMakeFiles/ex8_4.dir/flags.make
CMakeFiles/ex8_4.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\C++primer\cppprimer\chapter 8\ex8.4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex8_4.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ex8_4.dir\main.cpp.obj -c "E:\C++primer\cppprimer\chapter 8\ex8.4\main.cpp"

CMakeFiles/ex8_4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex8_4.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\C++primer\cppprimer\chapter 8\ex8.4\main.cpp" > CMakeFiles\ex8_4.dir\main.cpp.i

CMakeFiles/ex8_4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex8_4.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\C++primer\cppprimer\chapter 8\ex8.4\main.cpp" -o CMakeFiles\ex8_4.dir\main.cpp.s

CMakeFiles/ex8_4.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/ex8_4.dir/main.cpp.obj.requires

CMakeFiles/ex8_4.dir/main.cpp.obj.provides: CMakeFiles/ex8_4.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\ex8_4.dir\build.make CMakeFiles/ex8_4.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/ex8_4.dir/main.cpp.obj.provides

CMakeFiles/ex8_4.dir/main.cpp.obj.provides.build: CMakeFiles/ex8_4.dir/main.cpp.obj


# Object files for target ex8_4
ex8_4_OBJECTS = \
"CMakeFiles/ex8_4.dir/main.cpp.obj"

# External object files for target ex8_4
ex8_4_EXTERNAL_OBJECTS =

ex8_4.exe: CMakeFiles/ex8_4.dir/main.cpp.obj
ex8_4.exe: CMakeFiles/ex8_4.dir/build.make
ex8_4.exe: CMakeFiles/ex8_4.dir/linklibs.rsp
ex8_4.exe: CMakeFiles/ex8_4.dir/objects1.rsp
ex8_4.exe: CMakeFiles/ex8_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\C++primer\cppprimer\chapter 8\ex8.4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex8_4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ex8_4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex8_4.dir/build: ex8_4.exe

.PHONY : CMakeFiles/ex8_4.dir/build

CMakeFiles/ex8_4.dir/requires: CMakeFiles/ex8_4.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/ex8_4.dir/requires

CMakeFiles/ex8_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ex8_4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ex8_4.dir/clean

CMakeFiles/ex8_4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\C++primer\cppprimer\chapter 8\ex8.4" "E:\C++primer\cppprimer\chapter 8\ex8.4" "E:\C++primer\cppprimer\chapter 8\ex8.4\cmake-build-debug" "E:\C++primer\cppprimer\chapter 8\ex8.4\cmake-build-debug" "E:\C++primer\cppprimer\chapter 8\ex8.4\cmake-build-debug\CMakeFiles\ex8_4.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ex8_4.dir/depend


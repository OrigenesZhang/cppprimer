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
CMAKE_SOURCE_DIR = "E:\C++primer\cppprimer\chapter 9\ex9.28"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\C++primer\cppprimer\chapter 9\ex9.28\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ex9_28.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex9_28.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex9_28.dir/flags.make

CMakeFiles/ex9_28.dir/main.cpp.obj: CMakeFiles/ex9_28.dir/flags.make
CMakeFiles/ex9_28.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\C++primer\cppprimer\chapter 9\ex9.28\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex9_28.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ex9_28.dir\main.cpp.obj -c "E:\C++primer\cppprimer\chapter 9\ex9.28\main.cpp"

CMakeFiles/ex9_28.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex9_28.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\C++primer\cppprimer\chapter 9\ex9.28\main.cpp" > CMakeFiles\ex9_28.dir\main.cpp.i

CMakeFiles/ex9_28.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex9_28.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\C++primer\cppprimer\chapter 9\ex9.28\main.cpp" -o CMakeFiles\ex9_28.dir\main.cpp.s

CMakeFiles/ex9_28.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/ex9_28.dir/main.cpp.obj.requires

CMakeFiles/ex9_28.dir/main.cpp.obj.provides: CMakeFiles/ex9_28.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\ex9_28.dir\build.make CMakeFiles/ex9_28.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/ex9_28.dir/main.cpp.obj.provides

CMakeFiles/ex9_28.dir/main.cpp.obj.provides.build: CMakeFiles/ex9_28.dir/main.cpp.obj


# Object files for target ex9_28
ex9_28_OBJECTS = \
"CMakeFiles/ex9_28.dir/main.cpp.obj"

# External object files for target ex9_28
ex9_28_EXTERNAL_OBJECTS =

ex9_28.exe: CMakeFiles/ex9_28.dir/main.cpp.obj
ex9_28.exe: CMakeFiles/ex9_28.dir/build.make
ex9_28.exe: CMakeFiles/ex9_28.dir/linklibs.rsp
ex9_28.exe: CMakeFiles/ex9_28.dir/objects1.rsp
ex9_28.exe: CMakeFiles/ex9_28.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\C++primer\cppprimer\chapter 9\ex9.28\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex9_28.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ex9_28.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex9_28.dir/build: ex9_28.exe

.PHONY : CMakeFiles/ex9_28.dir/build

CMakeFiles/ex9_28.dir/requires: CMakeFiles/ex9_28.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/ex9_28.dir/requires

CMakeFiles/ex9_28.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ex9_28.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ex9_28.dir/clean

CMakeFiles/ex9_28.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\C++primer\cppprimer\chapter 9\ex9.28" "E:\C++primer\cppprimer\chapter 9\ex9.28" "E:\C++primer\cppprimer\chapter 9\ex9.28\cmake-build-debug" "E:\C++primer\cppprimer\chapter 9\ex9.28\cmake-build-debug" "E:\C++primer\cppprimer\chapter 9\ex9.28\cmake-build-debug\CMakeFiles\ex9_28.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ex9_28.dir/depend


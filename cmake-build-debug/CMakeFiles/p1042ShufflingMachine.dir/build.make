# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yryang/Desktop/code/PATquiz

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yryang/Desktop/code/PATquiz/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/p1042ShufflingMachine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p1042ShufflingMachine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p1042ShufflingMachine.dir/flags.make

CMakeFiles/p1042ShufflingMachine.dir/p1042ShufflingMachine.cpp.o: CMakeFiles/p1042ShufflingMachine.dir/flags.make
CMakeFiles/p1042ShufflingMachine.dir/p1042ShufflingMachine.cpp.o: ../p1042ShufflingMachine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yryang/Desktop/code/PATquiz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p1042ShufflingMachine.dir/p1042ShufflingMachine.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p1042ShufflingMachine.dir/p1042ShufflingMachine.cpp.o -c /Users/yryang/Desktop/code/PATquiz/p1042ShufflingMachine.cpp

CMakeFiles/p1042ShufflingMachine.dir/p1042ShufflingMachine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p1042ShufflingMachine.dir/p1042ShufflingMachine.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yryang/Desktop/code/PATquiz/p1042ShufflingMachine.cpp > CMakeFiles/p1042ShufflingMachine.dir/p1042ShufflingMachine.cpp.i

CMakeFiles/p1042ShufflingMachine.dir/p1042ShufflingMachine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p1042ShufflingMachine.dir/p1042ShufflingMachine.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yryang/Desktop/code/PATquiz/p1042ShufflingMachine.cpp -o CMakeFiles/p1042ShufflingMachine.dir/p1042ShufflingMachine.cpp.s

# Object files for target p1042ShufflingMachine
p1042ShufflingMachine_OBJECTS = \
"CMakeFiles/p1042ShufflingMachine.dir/p1042ShufflingMachine.cpp.o"

# External object files for target p1042ShufflingMachine
p1042ShufflingMachine_EXTERNAL_OBJECTS =

p1042ShufflingMachine: CMakeFiles/p1042ShufflingMachine.dir/p1042ShufflingMachine.cpp.o
p1042ShufflingMachine: CMakeFiles/p1042ShufflingMachine.dir/build.make
p1042ShufflingMachine: CMakeFiles/p1042ShufflingMachine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yryang/Desktop/code/PATquiz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable p1042ShufflingMachine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p1042ShufflingMachine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p1042ShufflingMachine.dir/build: p1042ShufflingMachine

.PHONY : CMakeFiles/p1042ShufflingMachine.dir/build

CMakeFiles/p1042ShufflingMachine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p1042ShufflingMachine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p1042ShufflingMachine.dir/clean

CMakeFiles/p1042ShufflingMachine.dir/depend:
	cd /Users/yryang/Desktop/code/PATquiz/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yryang/Desktop/code/PATquiz /Users/yryang/Desktop/code/PATquiz /Users/yryang/Desktop/code/PATquiz/cmake-build-debug /Users/yryang/Desktop/code/PATquiz/cmake-build-debug /Users/yryang/Desktop/code/PATquiz/cmake-build-debug/CMakeFiles/p1042ShufflingMachine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p1042ShufflingMachine.dir/depend


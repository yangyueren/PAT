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
include CMakeFiles/p1140LookandsaySequence.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p1140LookandsaySequence.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p1140LookandsaySequence.dir/flags.make

CMakeFiles/p1140LookandsaySequence.dir/p1140LookandsaySequence.cpp.o: CMakeFiles/p1140LookandsaySequence.dir/flags.make
CMakeFiles/p1140LookandsaySequence.dir/p1140LookandsaySequence.cpp.o: ../p1140LookandsaySequence.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yryang/Desktop/code/PATquiz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p1140LookandsaySequence.dir/p1140LookandsaySequence.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p1140LookandsaySequence.dir/p1140LookandsaySequence.cpp.o -c /Users/yryang/Desktop/code/PATquiz/p1140LookandsaySequence.cpp

CMakeFiles/p1140LookandsaySequence.dir/p1140LookandsaySequence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p1140LookandsaySequence.dir/p1140LookandsaySequence.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yryang/Desktop/code/PATquiz/p1140LookandsaySequence.cpp > CMakeFiles/p1140LookandsaySequence.dir/p1140LookandsaySequence.cpp.i

CMakeFiles/p1140LookandsaySequence.dir/p1140LookandsaySequence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p1140LookandsaySequence.dir/p1140LookandsaySequence.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yryang/Desktop/code/PATquiz/p1140LookandsaySequence.cpp -o CMakeFiles/p1140LookandsaySequence.dir/p1140LookandsaySequence.cpp.s

# Object files for target p1140LookandsaySequence
p1140LookandsaySequence_OBJECTS = \
"CMakeFiles/p1140LookandsaySequence.dir/p1140LookandsaySequence.cpp.o"

# External object files for target p1140LookandsaySequence
p1140LookandsaySequence_EXTERNAL_OBJECTS =

p1140LookandsaySequence: CMakeFiles/p1140LookandsaySequence.dir/p1140LookandsaySequence.cpp.o
p1140LookandsaySequence: CMakeFiles/p1140LookandsaySequence.dir/build.make
p1140LookandsaySequence: CMakeFiles/p1140LookandsaySequence.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yryang/Desktop/code/PATquiz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable p1140LookandsaySequence"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p1140LookandsaySequence.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p1140LookandsaySequence.dir/build: p1140LookandsaySequence

.PHONY : CMakeFiles/p1140LookandsaySequence.dir/build

CMakeFiles/p1140LookandsaySequence.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p1140LookandsaySequence.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p1140LookandsaySequence.dir/clean

CMakeFiles/p1140LookandsaySequence.dir/depend:
	cd /Users/yryang/Desktop/code/PATquiz/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yryang/Desktop/code/PATquiz /Users/yryang/Desktop/code/PATquiz /Users/yryang/Desktop/code/PATquiz/cmake-build-debug /Users/yryang/Desktop/code/PATquiz/cmake-build-debug /Users/yryang/Desktop/code/PATquiz/cmake-build-debug/CMakeFiles/p1140LookandsaySequence.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p1140LookandsaySequence.dir/depend


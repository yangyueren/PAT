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
include CMakeFiles/p1132CutInteger.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p1132CutInteger.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p1132CutInteger.dir/flags.make

CMakeFiles/p1132CutInteger.dir/p1132CutInteger.cpp.o: CMakeFiles/p1132CutInteger.dir/flags.make
CMakeFiles/p1132CutInteger.dir/p1132CutInteger.cpp.o: ../p1132CutInteger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yryang/Desktop/code/PATquiz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p1132CutInteger.dir/p1132CutInteger.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p1132CutInteger.dir/p1132CutInteger.cpp.o -c /Users/yryang/Desktop/code/PATquiz/p1132CutInteger.cpp

CMakeFiles/p1132CutInteger.dir/p1132CutInteger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p1132CutInteger.dir/p1132CutInteger.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yryang/Desktop/code/PATquiz/p1132CutInteger.cpp > CMakeFiles/p1132CutInteger.dir/p1132CutInteger.cpp.i

CMakeFiles/p1132CutInteger.dir/p1132CutInteger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p1132CutInteger.dir/p1132CutInteger.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yryang/Desktop/code/PATquiz/p1132CutInteger.cpp -o CMakeFiles/p1132CutInteger.dir/p1132CutInteger.cpp.s

# Object files for target p1132CutInteger
p1132CutInteger_OBJECTS = \
"CMakeFiles/p1132CutInteger.dir/p1132CutInteger.cpp.o"

# External object files for target p1132CutInteger
p1132CutInteger_EXTERNAL_OBJECTS =

p1132CutInteger: CMakeFiles/p1132CutInteger.dir/p1132CutInteger.cpp.o
p1132CutInteger: CMakeFiles/p1132CutInteger.dir/build.make
p1132CutInteger: CMakeFiles/p1132CutInteger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yryang/Desktop/code/PATquiz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable p1132CutInteger"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p1132CutInteger.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p1132CutInteger.dir/build: p1132CutInteger

.PHONY : CMakeFiles/p1132CutInteger.dir/build

CMakeFiles/p1132CutInteger.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p1132CutInteger.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p1132CutInteger.dir/clean

CMakeFiles/p1132CutInteger.dir/depend:
	cd /Users/yryang/Desktop/code/PATquiz/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yryang/Desktop/code/PATquiz /Users/yryang/Desktop/code/PATquiz /Users/yryang/Desktop/code/PATquiz/cmake-build-debug /Users/yryang/Desktop/code/PATquiz/cmake-build-debug /Users/yryang/Desktop/code/PATquiz/cmake-build-debug/CMakeFiles/p1132CutInteger.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p1132CutInteger.dir/depend


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
CMAKE_SOURCE_DIR = /workspaces/CS225/mp_traversals

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/CS225/mp_traversals/build

# Include any dependencies generated for this target.
include src/CMakeFiles/src.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/src.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src.dir/flags.make

src/CMakeFiles/src.dir/Animation.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/Animation.cpp.o: ../src/Animation.cpp
src/CMakeFiles/src.dir/Animation.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/mp_traversals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src.dir/Animation.cpp.o"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/Animation.cpp.o -MF CMakeFiles/src.dir/Animation.cpp.o.d -o CMakeFiles/src.dir/Animation.cpp.o -c /workspaces/CS225/mp_traversals/src/Animation.cpp

src/CMakeFiles/src.dir/Animation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Animation.cpp.i"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/mp_traversals/src/Animation.cpp > CMakeFiles/src.dir/Animation.cpp.i

src/CMakeFiles/src.dir/Animation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Animation.cpp.s"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/mp_traversals/src/Animation.cpp -o CMakeFiles/src.dir/Animation.cpp.s

src/CMakeFiles/src.dir/FloodFilledImage.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/FloodFilledImage.cpp.o: ../src/FloodFilledImage.cpp
src/CMakeFiles/src.dir/FloodFilledImage.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/mp_traversals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src.dir/FloodFilledImage.cpp.o"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/FloodFilledImage.cpp.o -MF CMakeFiles/src.dir/FloodFilledImage.cpp.o.d -o CMakeFiles/src.dir/FloodFilledImage.cpp.o -c /workspaces/CS225/mp_traversals/src/FloodFilledImage.cpp

src/CMakeFiles/src.dir/FloodFilledImage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/FloodFilledImage.cpp.i"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/mp_traversals/src/FloodFilledImage.cpp > CMakeFiles/src.dir/FloodFilledImage.cpp.i

src/CMakeFiles/src.dir/FloodFilledImage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/FloodFilledImage.cpp.s"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/mp_traversals/src/FloodFilledImage.cpp -o CMakeFiles/src.dir/FloodFilledImage.cpp.s

src/CMakeFiles/src.dir/Point.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/Point.cpp.o: ../src/Point.cpp
src/CMakeFiles/src.dir/Point.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/mp_traversals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/src.dir/Point.cpp.o"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/Point.cpp.o -MF CMakeFiles/src.dir/Point.cpp.o.d -o CMakeFiles/src.dir/Point.cpp.o -c /workspaces/CS225/mp_traversals/src/Point.cpp

src/CMakeFiles/src.dir/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Point.cpp.i"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/mp_traversals/src/Point.cpp > CMakeFiles/src.dir/Point.cpp.i

src/CMakeFiles/src.dir/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Point.cpp.s"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/mp_traversals/src/Point.cpp -o CMakeFiles/src.dir/Point.cpp.s

src/CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.o: ../src/colorPicker/GradientColorPicker.cpp
src/CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/mp_traversals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.o"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.o -MF CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.o.d -o CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.o -c /workspaces/CS225/mp_traversals/src/colorPicker/GradientColorPicker.cpp

src/CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.i"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/mp_traversals/src/colorPicker/GradientColorPicker.cpp > CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.i

src/CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.s"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/mp_traversals/src/colorPicker/GradientColorPicker.cpp -o CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.s

src/CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.o: ../src/colorPicker/GridColorPicker.cpp
src/CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/mp_traversals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.o"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.o -MF CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.o.d -o CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.o -c /workspaces/CS225/mp_traversals/src/colorPicker/GridColorPicker.cpp

src/CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.i"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/mp_traversals/src/colorPicker/GridColorPicker.cpp > CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.i

src/CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.s"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/mp_traversals/src/colorPicker/GridColorPicker.cpp -o CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.s

src/CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.o: ../src/colorPicker/MyColorPicker.cpp
src/CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/mp_traversals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.o"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.o -MF CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.o.d -o CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.o -c /workspaces/CS225/mp_traversals/src/colorPicker/MyColorPicker.cpp

src/CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.i"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/mp_traversals/src/colorPicker/MyColorPicker.cpp > CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.i

src/CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.s"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/mp_traversals/src/colorPicker/MyColorPicker.cpp -o CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.s

src/CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.o: ../src/colorPicker/RainbowColorPicker.cpp
src/CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/mp_traversals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.o"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.o -MF CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.o.d -o CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.o -c /workspaces/CS225/mp_traversals/src/colorPicker/RainbowColorPicker.cpp

src/CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.i"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/mp_traversals/src/colorPicker/RainbowColorPicker.cpp > CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.i

src/CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.s"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/mp_traversals/src/colorPicker/RainbowColorPicker.cpp -o CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.s

src/CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.o: ../src/colorPicker/SolidColorPicker.cpp
src/CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/mp_traversals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.o"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.o -MF CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.o.d -o CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.o -c /workspaces/CS225/mp_traversals/src/colorPicker/SolidColorPicker.cpp

src/CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.i"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/mp_traversals/src/colorPicker/SolidColorPicker.cpp > CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.i

src/CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.s"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/mp_traversals/src/colorPicker/SolidColorPicker.cpp -o CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.s

src/CMakeFiles/src.dir/imageTraversal/BFS.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/imageTraversal/BFS.cpp.o: ../src/imageTraversal/BFS.cpp
src/CMakeFiles/src.dir/imageTraversal/BFS.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/mp_traversals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/src.dir/imageTraversal/BFS.cpp.o"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/imageTraversal/BFS.cpp.o -MF CMakeFiles/src.dir/imageTraversal/BFS.cpp.o.d -o CMakeFiles/src.dir/imageTraversal/BFS.cpp.o -c /workspaces/CS225/mp_traversals/src/imageTraversal/BFS.cpp

src/CMakeFiles/src.dir/imageTraversal/BFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/imageTraversal/BFS.cpp.i"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/mp_traversals/src/imageTraversal/BFS.cpp > CMakeFiles/src.dir/imageTraversal/BFS.cpp.i

src/CMakeFiles/src.dir/imageTraversal/BFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/imageTraversal/BFS.cpp.s"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/mp_traversals/src/imageTraversal/BFS.cpp -o CMakeFiles/src.dir/imageTraversal/BFS.cpp.s

src/CMakeFiles/src.dir/imageTraversal/DFS.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/imageTraversal/DFS.cpp.o: ../src/imageTraversal/DFS.cpp
src/CMakeFiles/src.dir/imageTraversal/DFS.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/mp_traversals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/src.dir/imageTraversal/DFS.cpp.o"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/imageTraversal/DFS.cpp.o -MF CMakeFiles/src.dir/imageTraversal/DFS.cpp.o.d -o CMakeFiles/src.dir/imageTraversal/DFS.cpp.o -c /workspaces/CS225/mp_traversals/src/imageTraversal/DFS.cpp

src/CMakeFiles/src.dir/imageTraversal/DFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/imageTraversal/DFS.cpp.i"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/mp_traversals/src/imageTraversal/DFS.cpp > CMakeFiles/src.dir/imageTraversal/DFS.cpp.i

src/CMakeFiles/src.dir/imageTraversal/DFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/imageTraversal/DFS.cpp.s"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/mp_traversals/src/imageTraversal/DFS.cpp -o CMakeFiles/src.dir/imageTraversal/DFS.cpp.s

src/CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.o: ../src/imageTraversal/ImageTraversal.cpp
src/CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/mp_traversals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.o"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.o -MF CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.o.d -o CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.o -c /workspaces/CS225/mp_traversals/src/imageTraversal/ImageTraversal.cpp

src/CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.i"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/mp_traversals/src/imageTraversal/ImageTraversal.cpp > CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.i

src/CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.s"
	cd /workspaces/CS225/mp_traversals/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/mp_traversals/src/imageTraversal/ImageTraversal.cpp -o CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/Animation.cpp.o" \
"CMakeFiles/src.dir/FloodFilledImage.cpp.o" \
"CMakeFiles/src.dir/Point.cpp.o" \
"CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.o" \
"CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.o" \
"CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.o" \
"CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.o" \
"CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.o" \
"CMakeFiles/src.dir/imageTraversal/BFS.cpp.o" \
"CMakeFiles/src.dir/imageTraversal/DFS.cpp.o" \
"CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src/libsrc.a: src/CMakeFiles/src.dir/Animation.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/FloodFilledImage.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/Point.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/colorPicker/GradientColorPicker.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/colorPicker/GridColorPicker.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/colorPicker/MyColorPicker.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/colorPicker/RainbowColorPicker.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/colorPicker/SolidColorPicker.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/imageTraversal/BFS.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/imageTraversal/DFS.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/imageTraversal/ImageTraversal.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/build.make
src/libsrc.a: src/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/CS225/mp_traversals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX static library libsrc.a"
	cd /workspaces/CS225/mp_traversals/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean_target.cmake
	cd /workspaces/CS225/mp_traversals/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src.dir/build: src/libsrc.a
.PHONY : src/CMakeFiles/src.dir/build

src/CMakeFiles/src.dir/clean:
	cd /workspaces/CS225/mp_traversals/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src.dir/clean

src/CMakeFiles/src.dir/depend:
	cd /workspaces/CS225/mp_traversals/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/CS225/mp_traversals /workspaces/CS225/mp_traversals/src /workspaces/CS225/mp_traversals/build /workspaces/CS225/mp_traversals/build/src /workspaces/CS225/mp_traversals/build/src/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/src.dir/depend


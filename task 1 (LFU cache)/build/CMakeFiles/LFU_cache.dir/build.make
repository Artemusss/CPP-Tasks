# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = "/home/daddy/Документы/rep cpp/CPP-Tasks/task 1 (LFU cache)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/daddy/Документы/rep cpp/CPP-Tasks/task 1 (LFU cache)/build"

# Include any dependencies generated for this target.
include CMakeFiles/LFU_cache.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LFU_cache.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LFU_cache.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LFU_cache.dir/flags.make

CMakeFiles/LFU_cache.dir/source/cache.cpp.o: CMakeFiles/LFU_cache.dir/flags.make
CMakeFiles/LFU_cache.dir/source/cache.cpp.o: /home/daddy/Документы/rep\ cpp/CPP-Tasks/task\ 1\ (LFU\ cache)/source/cache.cpp
CMakeFiles/LFU_cache.dir/source/cache.cpp.o: CMakeFiles/LFU_cache.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/daddy/Документы/rep cpp/CPP-Tasks/task 1 (LFU cache)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LFU_cache.dir/source/cache.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LFU_cache.dir/source/cache.cpp.o -MF CMakeFiles/LFU_cache.dir/source/cache.cpp.o.d -o CMakeFiles/LFU_cache.dir/source/cache.cpp.o -c "/home/daddy/Документы/rep cpp/CPP-Tasks/task 1 (LFU cache)/source/cache.cpp"

CMakeFiles/LFU_cache.dir/source/cache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LFU_cache.dir/source/cache.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/daddy/Документы/rep cpp/CPP-Tasks/task 1 (LFU cache)/source/cache.cpp" > CMakeFiles/LFU_cache.dir/source/cache.cpp.i

CMakeFiles/LFU_cache.dir/source/cache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LFU_cache.dir/source/cache.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/daddy/Документы/rep cpp/CPP-Tasks/task 1 (LFU cache)/source/cache.cpp" -o CMakeFiles/LFU_cache.dir/source/cache.cpp.s

# Object files for target LFU_cache
LFU_cache_OBJECTS = \
"CMakeFiles/LFU_cache.dir/source/cache.cpp.o"

# External object files for target LFU_cache
LFU_cache_EXTERNAL_OBJECTS =

libLFU_cache.a: CMakeFiles/LFU_cache.dir/source/cache.cpp.o
libLFU_cache.a: CMakeFiles/LFU_cache.dir/build.make
libLFU_cache.a: CMakeFiles/LFU_cache.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/daddy/Документы/rep cpp/CPP-Tasks/task 1 (LFU cache)/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libLFU_cache.a"
	$(CMAKE_COMMAND) -P CMakeFiles/LFU_cache.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LFU_cache.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LFU_cache.dir/build: libLFU_cache.a
.PHONY : CMakeFiles/LFU_cache.dir/build

CMakeFiles/LFU_cache.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LFU_cache.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LFU_cache.dir/clean

CMakeFiles/LFU_cache.dir/depend:
	cd "/home/daddy/Документы/rep cpp/CPP-Tasks/task 1 (LFU cache)/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/daddy/Документы/rep cpp/CPP-Tasks/task 1 (LFU cache)" "/home/daddy/Документы/rep cpp/CPP-Tasks/task 1 (LFU cache)" "/home/daddy/Документы/rep cpp/CPP-Tasks/task 1 (LFU cache)/build" "/home/daddy/Документы/rep cpp/CPP-Tasks/task 1 (LFU cache)/build" "/home/daddy/Документы/rep cpp/CPP-Tasks/task 1 (LFU cache)/build/CMakeFiles/LFU_cache.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/LFU_cache.dir/depend


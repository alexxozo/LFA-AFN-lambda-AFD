# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /cygdrive/c/Users/Alex/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Alex/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/Alex/Desktop/Github Desktop Projects/LFA-AFN-lambda-AFD"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/Alex/Desktop/Github Desktop Projects/LFA-AFN-lambda-AFD/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/LFA_AFN_lambda__AFD.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LFA_AFN_lambda__AFD.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LFA_AFN_lambda__AFD.dir/flags.make

CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o: CMakeFiles/LFA_AFN_lambda__AFD.dir/flags.make
CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/Alex/Desktop/Github Desktop Projects/LFA-AFN-lambda-AFD/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o -c "/cygdrive/c/Users/Alex/Desktop/Github Desktop Projects/LFA-AFN-lambda-AFD/main.cpp"

CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/Alex/Desktop/Github Desktop Projects/LFA-AFN-lambda-AFD/main.cpp" > CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.i

CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/Alex/Desktop/Github Desktop Projects/LFA-AFN-lambda-AFD/main.cpp" -o CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.s

CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o.requires

CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o.provides: CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/LFA_AFN_lambda__AFD.dir/build.make CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o.provides

CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o.provides.build: CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o


# Object files for target LFA_AFN_lambda__AFD
LFA_AFN_lambda__AFD_OBJECTS = \
"CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o"

# External object files for target LFA_AFN_lambda__AFD
LFA_AFN_lambda__AFD_EXTERNAL_OBJECTS =

LFA_AFN_lambda__AFD.exe: CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o
LFA_AFN_lambda__AFD.exe: CMakeFiles/LFA_AFN_lambda__AFD.dir/build.make
LFA_AFN_lambda__AFD.exe: CMakeFiles/LFA_AFN_lambda__AFD.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/Alex/Desktop/Github Desktop Projects/LFA-AFN-lambda-AFD/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LFA_AFN_lambda__AFD.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LFA_AFN_lambda__AFD.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LFA_AFN_lambda__AFD.dir/build: LFA_AFN_lambda__AFD.exe

.PHONY : CMakeFiles/LFA_AFN_lambda__AFD.dir/build

CMakeFiles/LFA_AFN_lambda__AFD.dir/requires: CMakeFiles/LFA_AFN_lambda__AFD.dir/main.cpp.o.requires

.PHONY : CMakeFiles/LFA_AFN_lambda__AFD.dir/requires

CMakeFiles/LFA_AFN_lambda__AFD.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LFA_AFN_lambda__AFD.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LFA_AFN_lambda__AFD.dir/clean

CMakeFiles/LFA_AFN_lambda__AFD.dir/depend:
	cd "/cygdrive/c/Users/Alex/Desktop/Github Desktop Projects/LFA-AFN-lambda-AFD/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/Alex/Desktop/Github Desktop Projects/LFA-AFN-lambda-AFD" "/cygdrive/c/Users/Alex/Desktop/Github Desktop Projects/LFA-AFN-lambda-AFD" "/cygdrive/c/Users/Alex/Desktop/Github Desktop Projects/LFA-AFN-lambda-AFD/cmake-build-debug" "/cygdrive/c/Users/Alex/Desktop/Github Desktop Projects/LFA-AFN-lambda-AFD/cmake-build-debug" "/cygdrive/c/Users/Alex/Desktop/Github Desktop Projects/LFA-AFN-lambda-AFD/cmake-build-debug/CMakeFiles/LFA_AFN_lambda__AFD.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/LFA_AFN_lambda__AFD.dir/depend


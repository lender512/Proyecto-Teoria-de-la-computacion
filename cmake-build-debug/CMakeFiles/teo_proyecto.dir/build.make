# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /cygdrive/c/Users/Acer/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Acer/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/teo_proyecto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/teo_proyecto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/teo_proyecto.dir/flags.make

CMakeFiles/teo_proyecto.dir/main.cpp.o: CMakeFiles/teo_proyecto.dir/flags.make
CMakeFiles/teo_proyecto.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/teo_proyecto.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/teo_proyecto.dir/main.cpp.o -c /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/main.cpp

CMakeFiles/teo_proyecto.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/teo_proyecto.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/main.cpp > CMakeFiles/teo_proyecto.dir/main.cpp.i

CMakeFiles/teo_proyecto.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/teo_proyecto.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/main.cpp -o CMakeFiles/teo_proyecto.dir/main.cpp.s

CMakeFiles/teo_proyecto.dir/funciones.cpp.o: CMakeFiles/teo_proyecto.dir/flags.make
CMakeFiles/teo_proyecto.dir/funciones.cpp.o: ../funciones.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/teo_proyecto.dir/funciones.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/teo_proyecto.dir/funciones.cpp.o -c /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/funciones.cpp

CMakeFiles/teo_proyecto.dir/funciones.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/teo_proyecto.dir/funciones.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/funciones.cpp > CMakeFiles/teo_proyecto.dir/funciones.cpp.i

CMakeFiles/teo_proyecto.dir/funciones.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/teo_proyecto.dir/funciones.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/funciones.cpp -o CMakeFiles/teo_proyecto.dir/funciones.cpp.s

CMakeFiles/teo_proyecto.dir/methods.cpp.o: CMakeFiles/teo_proyecto.dir/flags.make
CMakeFiles/teo_proyecto.dir/methods.cpp.o: ../methods.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/teo_proyecto.dir/methods.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/teo_proyecto.dir/methods.cpp.o -c /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/methods.cpp

CMakeFiles/teo_proyecto.dir/methods.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/teo_proyecto.dir/methods.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/methods.cpp > CMakeFiles/teo_proyecto.dir/methods.cpp.i

CMakeFiles/teo_proyecto.dir/methods.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/teo_proyecto.dir/methods.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/methods.cpp -o CMakeFiles/teo_proyecto.dir/methods.cpp.s

CMakeFiles/teo_proyecto.dir/methodsP2.cpp.o: CMakeFiles/teo_proyecto.dir/flags.make
CMakeFiles/teo_proyecto.dir/methodsP2.cpp.o: ../methodsP2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/teo_proyecto.dir/methodsP2.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/teo_proyecto.dir/methodsP2.cpp.o -c /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/methodsP2.cpp

CMakeFiles/teo_proyecto.dir/methodsP2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/teo_proyecto.dir/methodsP2.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/methodsP2.cpp > CMakeFiles/teo_proyecto.dir/methodsP2.cpp.i

CMakeFiles/teo_proyecto.dir/methodsP2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/teo_proyecto.dir/methodsP2.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/methodsP2.cpp -o CMakeFiles/teo_proyecto.dir/methodsP2.cpp.s

# Object files for target teo_proyecto
teo_proyecto_OBJECTS = \
"CMakeFiles/teo_proyecto.dir/main.cpp.o" \
"CMakeFiles/teo_proyecto.dir/funciones.cpp.o" \
"CMakeFiles/teo_proyecto.dir/methods.cpp.o" \
"CMakeFiles/teo_proyecto.dir/methodsP2.cpp.o"

# External object files for target teo_proyecto
teo_proyecto_EXTERNAL_OBJECTS =

teo_proyecto.exe: CMakeFiles/teo_proyecto.dir/main.cpp.o
teo_proyecto.exe: CMakeFiles/teo_proyecto.dir/funciones.cpp.o
teo_proyecto.exe: CMakeFiles/teo_proyecto.dir/methods.cpp.o
teo_proyecto.exe: CMakeFiles/teo_proyecto.dir/methodsP2.cpp.o
teo_proyecto.exe: CMakeFiles/teo_proyecto.dir/build.make
teo_proyecto.exe: CMakeFiles/teo_proyecto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable teo_proyecto.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/teo_proyecto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/teo_proyecto.dir/build: teo_proyecto.exe

.PHONY : CMakeFiles/teo_proyecto.dir/build

CMakeFiles/teo_proyecto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/teo_proyecto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/teo_proyecto.dir/clean

CMakeFiles/teo_proyecto.dir/depend:
	cd /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/cmake-build-debug /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/cmake-build-debug /cygdrive/c/Users/Acer/CLionProjects/teo_proyecto/cmake-build-debug/CMakeFiles/teo_proyecto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/teo_proyecto.dir/depend

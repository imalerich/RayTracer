# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ianma\Development\RayTracer\src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ianma\Development\RayTracer\bin

# Include any dependencies generated for this target.
include lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/depend.make

# Include the progress variables for this target.
include lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/flags.make

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/flags.make
lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/includes_C.rsp
lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj: C:/Users/ianma/Development/RayTracer/src/lib/glfw-3.1.1/tests/gamma.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ianma\Development\RayTracer\bin\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj"
	cd /d C:\Users\ianma\Development\RayTracer\bin\lib\glfw-3.1.1\tests && C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles\gamma.dir\gamma.c.obj   -c C:\Users\ianma\Development\RayTracer\src\lib\glfw-3.1.1\tests\gamma.c

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gamma.dir/gamma.c.i"
	cd /d C:\Users\ianma\Development\RayTracer\bin\lib\glfw-3.1.1\tests && C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -E C:\Users\ianma\Development\RayTracer\src\lib\glfw-3.1.1\tests\gamma.c > CMakeFiles\gamma.dir\gamma.c.i

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gamma.dir/gamma.c.s"
	cd /d C:\Users\ianma\Development\RayTracer\bin\lib\glfw-3.1.1\tests && C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -S C:\Users\ianma\Development\RayTracer\src\lib\glfw-3.1.1\tests\gamma.c -o CMakeFiles\gamma.dir\gamma.c.s

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj.requires:

.PHONY : lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj.requires

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj.provides: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj.requires
	$(MAKE) -f lib\glfw-3.1.1\tests\CMakeFiles\gamma.dir\build.make lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj.provides.build
.PHONY : lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj.provides

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj.provides.build: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj


lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/flags.make
lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/includes_C.rsp
lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj: C:/Users/ianma/Development/RayTracer/src/lib/glfw-3.1.1/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ianma\Development\RayTracer\bin\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj"
	cd /d C:\Users\ianma\Development\RayTracer\bin\lib\glfw-3.1.1\tests && C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles\gamma.dir\__\deps\getopt.c.obj   -c C:\Users\ianma\Development\RayTracer\src\lib\glfw-3.1.1\deps\getopt.c

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gamma.dir/__/deps/getopt.c.i"
	cd /d C:\Users\ianma\Development\RayTracer\bin\lib\glfw-3.1.1\tests && C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -E C:\Users\ianma\Development\RayTracer\src\lib\glfw-3.1.1\deps\getopt.c > CMakeFiles\gamma.dir\__\deps\getopt.c.i

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gamma.dir/__/deps/getopt.c.s"
	cd /d C:\Users\ianma\Development\RayTracer\bin\lib\glfw-3.1.1\tests && C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -S C:\Users\ianma\Development\RayTracer\src\lib\glfw-3.1.1\deps\getopt.c -o CMakeFiles\gamma.dir\__\deps\getopt.c.s

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj.requires:

.PHONY : lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj.requires

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj.provides: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj.requires
	$(MAKE) -f lib\glfw-3.1.1\tests\CMakeFiles\gamma.dir\build.make lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj.provides.build
.PHONY : lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj.provides

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj.provides.build: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj


# Object files for target gamma
gamma_OBJECTS = \
"CMakeFiles/gamma.dir/gamma.c.obj" \
"CMakeFiles/gamma.dir/__/deps/getopt.c.obj"

# External object files for target gamma
gamma_EXTERNAL_OBJECTS =

lib/glfw-3.1.1/tests/gamma.exe: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj
lib/glfw-3.1.1/tests/gamma.exe: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj
lib/glfw-3.1.1/tests/gamma.exe: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/build.make
lib/glfw-3.1.1/tests/gamma.exe: lib/glfw-3.1.1/src/libglfw3.a
lib/glfw-3.1.1/tests/gamma.exe: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/linklibs.rsp
lib/glfw-3.1.1/tests/gamma.exe: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/objects1.rsp
lib/glfw-3.1.1/tests/gamma.exe: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ianma\Development\RayTracer\bin\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable gamma.exe"
	cd /d C:\Users\ianma\Development\RayTracer\bin\lib\glfw-3.1.1\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gamma.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/build: lib/glfw-3.1.1/tests/gamma.exe

.PHONY : lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/build

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/requires: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/gamma.c.obj.requires
lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/requires: lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/__/deps/getopt.c.obj.requires

.PHONY : lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/requires

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/clean:
	cd /d C:\Users\ianma\Development\RayTracer\bin\lib\glfw-3.1.1\tests && $(CMAKE_COMMAND) -P CMakeFiles\gamma.dir\cmake_clean.cmake
.PHONY : lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/clean

lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ianma\Development\RayTracer\src C:\Users\ianma\Development\RayTracer\src\lib\glfw-3.1.1\tests C:\Users\ianma\Development\RayTracer\bin C:\Users\ianma\Development\RayTracer\bin\lib\glfw-3.1.1\tests C:\Users\ianma\Development\RayTracer\bin\lib\glfw-3.1.1\tests\CMakeFiles\gamma.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glfw-3.1.1/tests/CMakeFiles/gamma.dir/depend


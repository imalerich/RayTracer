# Cmake required.
cmake_minimum_required (VERSION 2.6)
project (RayTracer)

# Version number
set (RayTracer_VERSION_MAJOR 0)
set (RayTracer_VERSION_MINOR 1)

# Set compiler and linker flags for gcc
set (GCC_COVERAGE_COMPILE_FLAGS 	"-std=c++11 -Wall -g -fopenmp")
set (GCC_COVERAGE_LINK_FLAGS		"-static-libgcc -static-libstdc++ -lm")

set (CMAKE_CXX_FLAGS 				"${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set (CMAKE_EXE_LINKER_FLAGS  		"${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# Configure a header file to pass CMake settings
configure_file (
	"${PROJECT_SOURCE_DIR}/RayTracerConfig.h.in"
	"${PROJECT_BINARY_DIR}/RayTracerConfig.h"
)

# Add the binary tree to the search path
include_directories(
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_SOURCE_DIR}/lib/glfw/include"
	"${PROJECT_SOURCE_DIR}/lib/glew/include"
	"${PROJECT_SOURCE_DIR}/lib/soil/include"
)

# Add the executable
add_executable(RayTracer
	src/main.cpp
	src/glutil.cpp

	src/raytracer.cpp
	src/camera.cpp

	src/math/vector.cpp

	src/lights/pointlight.cpp
	src/lights/dirlight.cpp

	src/surfaces/sphere.cpp
	src/surfaces/plane.cpp

	src/io/fileloader.cpp
	src/buffers/VertexBuffer.cpp
	src/buffers/ElementBuffer.cpp
)

# Include additional libraries

IF (WIN32 AND MINGW) 

	target_link_libraries(RayTracer 
		${PROJECT_SOURCE_DIR}/lib/soil/lib/libSOIL.a
		${PROJECT_SOURCE_DIR}/lib/glfw/lib-mingw/libglfw3.a
		${PROJECT_SOURCE_DIR}/lib/glew/lib/libglew32.a
		opengl32
		${OPENGL_glu_LIBRARY}
		glu32
		gdi32
	)

ELSEIF (UNIX AND NOT MINGW)

	target_link_libraries(RayTracer 
		SOIL
		glfw
		GLEW
		GL
		GLU
		X11
		Xxf86vm
		Xrandr
		Xi
		glut
	)

ENDIF()

# add the install targets
install (TARGETS RayTracer DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/RayTracerConfig.h"        
         DESTINATION include)

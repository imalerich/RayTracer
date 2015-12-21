#include "glutil.h"

GLFWwindow * window;
unsigned SCREENW = 3820;
unsigned SCREENH = 2160;

bool initWindow(const char * windowName) {
	if (!glfwInit()) {
		return false;
	}

	// we are going to use OpenGL version 3.2
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// create our window
	window = glfwCreateWindow(SCREENW, SCREENH, windowName, nullptr, nullptr); // windowed mode
	glfwMakeContextCurrent(window);

	// setup glew
	glewExperimental = GL_TRUE;
	glewInit();

	return true;
}

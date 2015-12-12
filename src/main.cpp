#include "prefix.h"

#include <iostream>
#include <stdio.h>
#include <math.h>

#include "glutil.h"
#include "raytracer.h"
#include "io/fileloader.h"
#include "buffers/VertexBuffer.h"
#include "buffers/ElementBuffer.h"

#include "sphere.h"
#include "vector.h"

using namespace std;

float vertices[] = {
	//Position     Color        	  TexCoords
	-1.0f,  1.0f,  1.0f, 1.0f, 1.0f,  0.0f, 0.0f,		// Top-left
     1.0f,  1.0f,  1.0f, 1.0f, 1.0f,  1.0f, 0.0f,		// Top-right
     1.0f, -1.0f,  1.0f, 1.0f, 1.0f,  1.0f, 1.0f,		// Bottom-right
   	-1.0f, -1.0f,  1.0f, 1.0f, 1.0f,  0.0f, 1.0f		// Bottom-left
};


GLuint elements[] = {
   	0, 1, 2,
    2, 3, 0
};

int main() {
	if (!initWindow("RayTracer")) {
		return -1;
	}

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// create our buffers
	VertexBuffer vbo = VertexBuffer(4, sizeof(vertices), vertices);
	ElementBuffer ebo = ElementBuffer(6, sizeof(elements), elements);

	// let's create our vertex buffer that we will load
	GLuint tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	RayTracer rt(SCREENW, SCREENH);
	float * pixels = rt.render_scene(Vector(3.0, 0.0, 0.0));

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, SCREENW, SCREENH, 0, GL_RGB, GL_FLOAT, pixels);
	delete[] pixels;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glGenerateMipmap(GL_TEXTURE_2D);

	// define our shaders
	char buffer[512];
	const char * fragmentSource = openFile("../assets/simple.fs");
	const char * vertexSource = openFile("../assets/simple.vs");

	// create our vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	// check if our shader compiled succesfully
	GLint status;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);

	glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
	fprintf(stdout, buffer);

	// create our fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
	fprintf(stdout, buffer);

	// create our shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	// set input data to the vertex shader
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position"); // Position
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 7*sizeof(float), 0);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "color"); // Color
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 7*sizeof(float), (void*)(2*sizeof(float)));

	GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord"); // TexCoords
	glEnableVertexAttribArray(texAttrib);
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 7*sizeof(float), (void*)(5*sizeof(float)));

	double time = 0.0;

	// game loop
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, ebo.getNumPrimitives(), GL_UNSIGNED_INT, 0);

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
	}

	// terminate glfw
	glfwTerminate();

	return 0;
}
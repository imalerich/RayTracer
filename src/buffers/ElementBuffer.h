#ifndef ELEMENTBUFFER_H
#define ELEMENTBUFFER_H

#include "../prefix.h"

class ElementBuffer {
public:
	ElementBuffer(unsigned Count, unsigned Size, const GLvoid * Data);

	GLuint getBuffer();
	unsigned getNumPrimitives();

private:
	// OpenGL references
	GLuint buffer;

	// retain the element count for rendering purposes
	unsigned count;
};

#endif
#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "../prefix.h"

class VertexBuffer {
public:
	VertexBuffer(unsigned Count, unsigned Size, const void * Data);

	GLuint getBuffer();
	unsigned getNumVertices();

private:
	// OpenGL references
	GLuint buffer;

	// retain the number of vertices for future reference
	unsigned count;
};

#endif
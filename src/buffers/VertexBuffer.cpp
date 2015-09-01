#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(unsigned Count, unsigned Size, const void * Data) {
	// load the data to our graphics device
	count = Count;
	glGenBuffers(1, &buffer); // generate a buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, Size, Data, GL_STATIC_DRAW);
}

GLuint VertexBuffer::getBuffer() {
	return buffer;
}

unsigned VertexBuffer::getNumVertices() {
	return count;
}

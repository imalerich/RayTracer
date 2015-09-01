#include "ElementBuffer.h"

ElementBuffer::ElementBuffer(unsigned Count, unsigned Size, const GLvoid * Data) {
	count = Count;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Size, Data, GL_STATIC_DRAW);
}

unsigned ElementBuffer::getNumPrimitives() {
	return count;
}

GLuint ElementBuffer::getBuffer() {
	return buffer;
}
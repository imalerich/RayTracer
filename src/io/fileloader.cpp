#include "fileloader.h"
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

char * openFile(const char * filename) {
	std::ifstream file(filename, std::ios::in | std::ios::binary | std::ios::ate);
    if (file.is_open())
    {
        unsigned size = file.tellg();
        char* buffer = new char[size+1];

        //copy the data into the buffer
        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();

        //null-terminate the string
        buffer[size] = '\0';

        return buffer;
    }

    return nullptr;
}
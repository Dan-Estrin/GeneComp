#ifndef FILEHEADER_H
#define FILEHEADER_H
unsigned int BufferSize(const char* filename);
void ReadFile(const char* filename, char* const data, unsigned int &dataLength);
#endif
#include <stdio.h>
#include <fstream>

/// @brief calculates size of the buffer needed to account for a full difference in 
/// genetic sequence
/// @param filename name of the file
/// @return returns 0 in the event that the file could not open. otherwise returns the file size in bytes
unsigned int BufferSize(const char* filename){
    std::fstream file(filename);
    if (file.fail()){
        return 0x0;
    }
    file.seekg(0,std::ios_base::end);
    unsigned int fsize = int(file.tellg());
    file.close();
    return fsize;
}

void read_file(const char* path, char* data, int dataLength){
    FILE *fp = fopen(path, "rt");
    fread(data, 1, dataLength, fp);
    fclose(fp);
}
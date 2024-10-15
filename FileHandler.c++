#include <stdio.h>
/// @brief calculates size of the buffer needed to account for a full difference in 
/// genetic sequence
/// @param filename name of the file 
/// @return returns 0 in the event that the file could not open. otherwise returns the file size in bytes
/// incremented by 1 in order to prepare the array for having the NUL char inserted on read_file call
unsigned int BufferSize(const char* filename){
    FILE* fp;
    if((fp = fopen(filename, "rt"))){
        fseek(fp, 0L, SEEK_END);
        unsigned int sz = ftell(fp);
        fclose(fp);
        return sz;
    }
    return 0;
}

/// @brief writes the data of the file with path filename to the data buffer
/// @param filename string containing the path of the file to be read
/// @param data reference to the allocated segment of memory that data will be written to
/// @param dataLength size of the file to be read in bytes
/// @note automatically terminates the array with NUL '\0' character to prevent leaks
void ReadFile(const char* filename, char* &data, unsigned int &dataLength){
    FILE *fp;
    if((fp = fopen(filename, "rt"))){
        fread(data, 1, dataLength, fp);
        fclose(fp);
        data[dataLength] = '\0';
    }
}

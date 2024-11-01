#include <stdio.h>
/// @brief calculates size of the buffer needed to account for a full difference in 
/// genetic sequence
/// @param filename name of the file 
/// @return returns 0 in the event that the file could not open. otherwise returns the file size in bytes
/// incremented by 1 in order to prepare the array for having the NUL char inserted on ReadFile call
unsigned int BufferSize(const char* filename){
    FILE* fp = fopen(filename, "rt");
    if(fp != nullptr){
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
/// @return if filename was valid returns 1, otherwise returns 0
void ReadFile(const char* filename, char* const data, unsigned int &dataLength){
    FILE* fp = fopen(filename, "rt");
    if(fp != nullptr){
        fread(data, 1, dataLength, fp);
        fclose(fp);
        data[dataLength] = '\0';
    }
}
/*
/// @brief Reads absolute filepaths from config for parent and child
/// @param parentPath array to store the filepath for the parent
/// @param offspringPath array to store the filepath for the child
/// @return if the config file is valid, returns 1, otherwise returns 0 
char ReadConfig(char* &parentPath, char* &offspringPath){
    FILE *fp;
    if(!(fp = fopen(".\\config.json", "rt"))){
        return 0;
    }

    char buff;
    do{
        buff = getc(fp);
    }while(buff != ':');

    buff = getc(fp);
    buff = getc(fp);
    unsigned int index = 0;

    do{
        *(parentPath+index) = buff;
        buff = getc(fp);
        index++;
    }while(buff != '"');

    do{
        buff = getc(fp);
    }while(buff != ':');

    buff = getc(fp);
    buff = getc(fp);
    index = 0;

    do{
        *(offspringPath+index) = buff;
        buff = getc(fp);
        index++;
    }while(buff != '"');

    return 1;
}*/
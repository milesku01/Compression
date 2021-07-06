#ifndef FILE_READER
#define FILE_READER

#include <iostream>
#include <fstream>
#include <string>


class FileReader {
    public: 
        std::string readFileToString(std::string fileName);
}; 

#endif 
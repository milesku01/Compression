#ifndef FILE_WRITER
#define FILE_WRITER

#include <iostream>
#include <fstream>
#include <string>


class FileWriter {
    public: 
        bool appendStringToFile(std::string fileName, std::string toWrite);
        bool writeStringToFile(std::string fileName, std::string toWrite);
}; 

#endif 
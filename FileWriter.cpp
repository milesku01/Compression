#include "FileWriter.h"

bool FileWriter::appendStringToFile(std::string fileName, std::string toWrite) {
    std::ofstream file; //TODO exception handling

    file.open(fileName, std::ios::app); 

    if (file.is_open()) {
        file.write(toWrite.data(), toWrite.size()); 
        file.close();

        return true;
    } else {

        std::cout << "Unable to open"; 
    } 

}

bool FileWriter::writeStringToFile(std::string fileName, std::string toWrite) {
    std::ofstream file(fileName); //TODO exception handling

    if (file.is_open()) {
        file.write(toWrite.data(), toWrite.size()); 
        file.close();

        return true;
    } else {

        std::cout << "Unable to open"; 
    } 

}
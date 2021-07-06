#include "FileReader.h"

std::string FileReader::readFileToString(std::string fileName) {
    std::string text; 

    std::ifstream file(fileName); //TODO exception handling

    if (file.is_open()) {
        while (std::getline(file, text)){
            std::cout << text << '\n';
        }
        file.close();
    } else {

        std::cout << "Unable to open"; 
    }
    return text; 
}

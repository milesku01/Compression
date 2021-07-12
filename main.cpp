#include <iostream>
#include "FileReader.h"
#include "FileWriter.h"

int main() {
    //comment
    FileReader fr;
    FileWriter fw; 

   // std::string name = fr.readFileToString("../test.txt"); //executed in build file
    fw.appendStringToFile("../test.txt", "This string"); 

    fw.writeStringToFile("../test2.txt", "This is the new string");
    
}

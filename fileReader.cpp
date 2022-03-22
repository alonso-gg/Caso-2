#include "main.h"

string readFile(string fileName){
    ifstream fileToRead(fileName.c_str());
    string fileContent;
    string fileLine;
    while (getline(fileToRead,fileLine)) {
        fileContent += fileLine;
    }
    fileToRead.close();
    return fileContent;
}
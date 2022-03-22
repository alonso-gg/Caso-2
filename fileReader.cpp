#include "main.h"

/* ITCR Campus Central Cartago
Ingeniería en computación - Análisis de algoritmos 
I Semestre 2022
Caso 2
Alonso Garita Granados

Lectura del archivo de texto, **no es objeto de evaluación para el caso**
*/

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
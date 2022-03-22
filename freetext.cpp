#include "main.h"
#define PRIME 3

/* ITCR Campus Central Cartago
Ingeniería en computación - Análisis de algoritmos 
I Semestre 2022
Caso 2
Alonso Garita Granados

Free text
	Se implementó el algoritmo de Rabin Karp usando como primo el 3, esto para que los valores hash
    no exedan el máximo valor para los enteros sin signo.
*/

unsigned int hashFunc(string hashString){
    unsigned int hashKey = 0; //2 asigaciones
    for(int i=0; i < hashString.length(); i++) //3 tiempos * hashString.length()
        hashKey += (hashString[i]) * pow(PRIME, i);
    //1 asignación, 1 acceso, 3 operaciones y 2 parámetros = 7 * hashString.length()
    return hashKey; //1 retorno
    //f(m) = 10m + 3 -> O(m) | m: largo del hashString = largo del pattern
}

unsigned int nextHashFunc(char oldChr, char newChr, int length, unsigned int prevKey){
    unsigned int hashKey = ((prevKey-oldChr)/PRIME) + (newChr * pow(PRIME, length-1));
    //1 asignación, 7 operaciones, 2 parámetros y 1 retorno = 11
    return hashKey;
    //f(m) = 11 -> O(c)
}

list<int>* searchRabinKarp(string text, string pattern){
    int patLength = pattern.length(); //2 tiempos
    unsigned int targetKey = hashFunc(pattern); //2 tiempos + (10m + 3)
    unsigned int compKey = hashFunc(text.substr(0, patLength)); //4 tiempos + (10m + 3)
    list<int>* indexes = new list<int>; //1 asignación

    int i = 0; //1 asingación
    do{ //se repite n-m veces | n: largo de text | m: largo del pattern

        if(compKey==targetKey){ //1 comparación
            //cout << "CompKey: " << compKey << endl;
            //cout << "Pattern: " << text.substr(i, patLength) << endl;
            if(text.substr(i, patLength)==pattern) //2 parámetros y 1 comparación
                indexes->push_back(i); //1 parámetro
        }

        i++; //2 timepos

        compKey = nextHashFunc(text[i-1], text[i+patLength-1], patLength, compKey); //8 tiempos + (11)
 
        
    }while(i < text.length()-patLength); //3 tiempos

    //1 return
    return indexes;
    
    //f(n) = 11 + 2(10m + 3) + 29(n-m)
    //f(n) = 11 + 20m + 6 + 29n - 29m
    //f(n) = 29n - 9m + 17
    //Notación: O(n-m)
}

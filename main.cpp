#include "main.h"
#define chronoNanoS std::chrono::duration_cast<std::chrono::nanoseconds>
#define chronoMilliS std::chrono::duration_cast<std::chrono::milliseconds>
#define chronoS std::chrono::duration_cast<std::chrono::seconds>

typedef std::chrono::high_resolution_clock Clock;

/* ITCR Campus Central Cartago
Ingeniería en computación - Análisis de algoritmos 
I Semestre 2022
Caso 2
Alonso Garita Granados

Main
    En el main se hacen pruebas a los tres algoritmos del caso. Se pueden cambiar por cualquier otra
    prueba para la revisión.
*/

void fillInRevOrder(int* arrayCollection[]){
    for(int i=0; i<10; i++){
        int* arr = arrayCollection[i];
        int length = (i+1)*1000;
        for(int j=0; j<length; j++){
            arr[j] = length-j;
        }
    }
}

void fillInOrder(int* arrayCollection[]){
    for(int i=0; i<10; i++){
        int* arr = arrayCollection[i];
        int length = (i+1)*1000;
        for(int j=0; j<length; j++){
            arr[j] = j+1;
        }
    }
}

int main(){
    //Arreglos de prueba (desde [1000] hasta [10000])
    int arr1[1000], arr2[2000], arr3[3000], arr4[4000], arr5[5000], arr6[6000], arr7[7000], arr8[8000], arr9[9000], arr10[10000];
    int* arrays[] = {arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr10};
    //Comparación de tiempos
    double timeAnt;
    double strictOofNAnt;

    //Quicksort O(n^2)
    timeAnt = 1;
    strictOofNAnt = 1;
    fillInRevOrder(arrays);

    cout << endl << "Quicksort O(n^2)" << endl;
    cout << "n\tT (ms)\tO(n^2)\tT ratio\tO ratio\tRatios dif." << endl;
    for(int i=0; i<10; i++){
        int* arr = arrays[i];
        int length = (i+1)*1000;

        auto start_time = Clock::now();
        //Pivote: 0=último, 1=primero 
        quickSort(arr, 0, length-1, 0); //Algoritmo a probar
        auto end_time = Clock::now();

        int time = chronoMilliS(end_time-start_time).count();
        int strictOofN = pow(length/1000, 2);
        cout << ((i+1)*1000) << "\t";
        cout << time << "\t";
        cout << strictOofN << "\t";
        cout << time/timeAnt << "\t";
        cout << strictOofN/strictOofNAnt << "\t";
        cout << abs((time/timeAnt)-(strictOofN/strictOofNAnt)) << "\t"<< endl;

        timeAnt = time;
        strictOofNAnt = strictOofN;
    }

    //Quicksort O(n*logn)
    timeAnt = 1;
    strictOofNAnt = 1;
    fillInRevOrder(arrays);

    cout << endl << "Quicksort O(n logn)" << endl;
    cout << "n\tT (ns)\tO(nlgn)\tT ratio\tO ratio\tRatios dif." << endl;
    for(int i=0; i<10; i++){
        int* arr = arrays[i];
        int length = (i+1)*1000;

        auto start_time = Clock::now();
        //Pivote: 2=centro, 3=aleatorio
        quickSort(arr, 0, length-1, 3); //Algoritmo a probar
        auto end_time = Clock::now();

        int time = chronoNanoS(end_time-start_time).count();
        int strictOofN = (length/100) * log2(length/100);
        cout << ((i+1)*1000) << "\t";
        cout << time << "\t";
        cout << strictOofN << "\t";
        cout << time/timeAnt << "\t";
        cout << strictOofN/strictOofNAnt << "\t";
        cout << abs((time/timeAnt)-(strictOofN/strictOofNAnt)) << "\t"<< endl;

        timeAnt = time;
        strictOofNAnt = strictOofN;
    }

    //Insertsort O(n^2)
    timeAnt = 1;
    strictOofNAnt = 1;
    fillInRevOrder(arrays);

    cout << endl << "Insertsort O(n^2)" << endl;
    cout << "n\tT (ms)\tO(n^2)\tT ratio\tO ratio\tRatios dif." << endl;
    for(int i=0; i<10; i++){
        int* arr = arrays[i];
        int length = (i+1)*1000;

        auto start_time = Clock::now();
        insertionSort(arr, length); //Algoritmo a probar
        auto end_time = Clock::now();

        int time = chronoMilliS(end_time-start_time).count();
        int strictOofN = pow(length/1000, 2);
        cout << ((i+1)*1000) << "\t";
        cout << time << "\t";
        cout << strictOofN << "\t";
        cout << time/timeAnt << "\t";
        cout << strictOofN/strictOofNAnt << "\t";
        cout << abs((time/timeAnt)-(strictOofN/strictOofNAnt)) << "\t"<< endl;

        timeAnt = time;
        strictOofNAnt = strictOofN;
    }

    //Insertsort O(n)
    timeAnt = 1;
    strictOofNAnt = 1;
    fillInOrder(arrays);

    cout << endl << "Insertsort O(n)" << endl;
    cout << "n\tT (ns)\tO(n)\tT ratio\tO ratio\tRatios dif." << endl;
    for(int i=0; i<10; i++){
        int* arr = arrays[i];
        int length = (i+1)*1000;

        auto start_time = Clock::now();
        insertionSort(arr, length); //Algoritmo a probar
        auto end_time = Clock::now();

        int time = chronoNanoS(end_time-start_time).count();
        int strictOofN = length/1000;
        cout << ((i+1)*1000) << "\t";
        cout << time << "\t";
        cout << strictOofN << "\t";
        cout << time/timeAnt << "\t";
        cout << strictOofN/strictOofNAnt << "\t";
        cout << abs((time/timeAnt)-(strictOofN/strictOofNAnt)) << "\t"<< endl;

        timeAnt = time;
        strictOofNAnt = strictOofN;
    }

    //Freetext, prueba funcional
    //Archivo usado: "BIBLIA COMPLETA x3.txt" (11 MB)
    string texto = readFile("BIBLIA COMPLETA x3.txt");

    //Prueba funcional
    string patBuscar = "mos";

    auto start_time = Clock::now();
    list<int>* resultados = searchRabinKarp(texto, patBuscar);
    auto end_time = Clock::now();

    cout << endl << "Patron buscado: " << patBuscar << endl;
    cout << "Posiciones de ocurrencia (limitado a 1000 impresiones): " << endl;
    int j = 0;
    for(int i : *resultados){
        cout << i << " ";
        j++;
        if(j==1000) break;
    }

    //Recorrer todas las posiciones (puede que no se muestren todas)
    /*for(int i : *resultados){
        cout << i << " ";
    }*/

    cout << "Apariciones totales: " << resultados->size() << endl;
    int time = chronoMilliS(end_time-start_time).count();
    cout << "Tiempo de ejecucion (ms): " << time << endl;
    
    //Prueba del O(n-m)
    patBuscar = "";
    timeAnt = 1;
    strictOofNAnt = 1;

    cout << endl << "Prueba de O(n-m) " << endl;
    cout << "n\tm\tT (ms)\tO(n-m)\tT ratio\tO ratio\tRatios dif." << endl;
    for(int i=0; i<10; i++){
        for(int j=0; j<(i+1)*3; j++){
            patBuscar += "a";
        }

        auto start_time = Clock::now();
        list<int>* resultados = searchRabinKarp(texto, patBuscar);
        auto end_time = Clock::now();

        int time = chronoMilliS(end_time-start_time).count();
        int strictOofN = texto.size() - patBuscar.size();

        cout << texto.size() << "\t";
        cout << patBuscar.size() << "\t";
        cout << time << "\t";
        cout << strictOofN << "\t";
        cout << time/timeAnt << "\t";
        cout << strictOofN/strictOofNAnt << "\t";
        cout << abs((time/timeAnt)-(strictOofN/strictOofNAnt)) << "\t"<< endl;

        timeAnt = time;
        strictOofNAnt = strictOofN;

        patBuscar = "";
    }

    return 0;
}

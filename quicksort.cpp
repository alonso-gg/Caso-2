#include "main.h"

/* ITCR Campus Central Cartago
Ingeniería en computación - Análisis de algoritmos 
I Semestre 2022
Caso 2
Alonso Garita Granados

Quicksort
	Este quicksort está implementado para crear particiones con base en el último elemento, sin embargo al
	elegir otro pivote (primer elemento, el del centro o aleatorio) se realiza un swap con el último. Este
	tiempo es constante, así que no afecta al comportamiento del algoritmo.
*/

void swap(int *p1, int *p2){
	int aux = *p1;
	*p1 = *p2;
	*p2 = aux;
	 //3 asignaciones | C4 = 3
}

int partition(int arr[], int first, int end, int pivot){
	int i = first;
	int j = first; // 2 asignaciones | C2 = 2

	while(i <= end){ //1 comparación
		if(arr[i] > pivot){ //1 acceso y 1 comparación
			i++; //1 asignación y 1 suma | C3.1 = 2
		}
		else{
			swap(&arr[i], &arr[j]); //2 parámetros y 2 accesos
			i++; //1 asignación y 1 suma = 2
			j++; //1 asignación y 1 suma = 2
			//C3.2 = 8
		}
		//C3 = 8
	}

	//1 resta y 1 retorno | C5 = 2
	return j-1;
}

void quickSort(int arr[], int first, int end, int pivOption){
	//1 comparación, se ejecuta al menos 2n-1 veces en el peor de los casos (orden invertido)
	//C0 * (2n-1) = 2n-1
	if(first < end){
        //Pivot option : (0-end | 1-first | 2-middle | 3-random)
		srand(time(0));
		int pivRandom = first+(rand()%(end-first+1));
        if(pivOption==1)
            swap(&arr[first], &arr[end]);
		else if(pivOption==2)
            swap(&arr[(first+end)/2], &arr[end]);
        else if(pivOption==3){
            swap(&arr[pivRandom], &arr[end]);
        }
		//No se cuentan estos tiempos pues sólo sirve para definir el pivote
        
        int pivot = arr[end]; //1 asignación y 1 acceso = 2
        int pos = partition(arr, first, end, pivot); //1 asignación, 3 parámetros = 4
        
        quickSort(arr, first, pos-1, pivOption); // 3 parámetros, 1 resta = 4
        quickSort(arr, pos+1, end, pivOption); // 3 parámetros, 1 suma = 4
		//C1 * (n-1) = 14(n-1)
		//Se ejecuta al menos n-1 veces en el peor de los casos (orden invertido)
	}
}
#include "main.h"

/* ITCR Campus Central Cartago
Ingeniería en computación - Análisis de algoritmos 
I Semestre 2022
Caso 2
Alonso Garita Granados

Insertsort
*/

void insertionSort(int arr[], int n){
   int aux, j;
   //1 asignación
   for(int i = 1; i<n; i++){ //1 comparación, 1 suma, 1 asignación = 3
      aux = arr[i]; //1 acceso, 1 asignación = 2
      j = i; //1 asignación
      //C1 * (n-1) = 6(n-1)

      while(j > 0 && arr[j-1]>aux) { // 3 comparaciones, 1 resta, 1 acceso = 5
         arr[j] = arr[j-1]; //2 accesos, 1 asignación, 1 resta = 4
         j--; //1 resta, 1 asignación = 2
         //C2 * S -> analizando el algoritmo, notamos que S = sum(k) desde k=1 hasta n, y por propiedades
         //matemáticas sabemos que S = (n(n-1))/2.
         //C2 * (n(n-1))/2 = 11 * (n(n-1))/2
      }

      arr[j] = aux; //1 acceso, 1 asignación = 2
      //C3 * (n-1) = 2(n-1)
   }

   /* f(n) = 1 + C1(n-1) + C2(n(n-1))/2 + C3(n-1)
      f(n) = 1 + 6(n-1) + 11(n(n-1))/2 + 2(n-1)
      f(n) = 11n2/2 + 5n/2 - 7 -> cuando es el peor caso donde el orden está invertido
      O(n2) -> es cuadrático tanto para el peor como para el caso promedio

      Si el arreglo ya está ordenado, entonces C2 se ejecuta 0 veces:
      f(n) = 1 + C1(n-1) + C3(n-1)
      f(n) = 1 + 6(n-1) + 2(n-1)
      f(n) = 8n-7
      O(n) -> alcanza un crecimiento lineal sólo cuando el arreglo ya está ordenado
   */
}
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <list>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;

void quickSort(int arr[], int first, int end, int pivOption);
void swap(int arr[] , int pos1, int pos2);
int partition(int arr[], int first, int end, int pivot);

void insertionSort(int arr[], int n);

list<int>* searchRabinKarp(string text, string pattern);
unsigned int hashFunc(string hashString);
unsigned int nextHashFunc(char oldChr, char newChr, int length, unsigned int prevKey);

string readFile(string ruta);

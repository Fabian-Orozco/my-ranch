/**
 * Copyright 2021 <fabian.orozcochaves@ucr.ac.cr>
 * Análisis de algoritmos y estructuras de datos - 2021 II Ciclo - B95690.
 * Nota: uso de tildes omitido para evitar errores de interpretación con C++
 * 
 * El main realiza la creacion, inicializacion de cuatro arreglos, los randomiza,
 * ordena (tomando el tiempo que toma hacerlo) y además verifica que 
 * el ordenamiento sea correcto.
 * 
 * Compilar con: g++ main.cpp Ordenador.h -o tarea
 * Ejecutar con: ./tarea
 */
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <random>

#include "Ordenador.h"

using namespace std;

void randomize(int* array, int size) {
  random_device dev;
  mt19937 rng(dev());
  for (int i = 0; i < size; ++i) {
    uniform_int_distribution<mt19937::result_type> dist6(-size*10,size*10);
    array[i] = dist6(rng);
  }
}

void test(int* A, int n) {
for (int i = 1; i < n ; i ++)
  if( A [ i ] < A [i -1] )
    cout << " ¡Fallo! " << endl;
}

template <typename T>
void duracionEnSegundos(T start, T end) {
  cout 
  << chrono::duration_cast<chrono::seconds>(start - end).count() << "." 
  << chrono::duration_cast<chrono::milliseconds>(start - end).count() << "s";
}

int main() {
  int sizeA = 50000, sizeB = 100000, sizeC = 150000, sizeD = 200000;

  int A[sizeA]; randomize(A, sizeA);
  int B[sizeB]; randomize(B, sizeB);
  int C[sizeC]; randomize(C, sizeC);
  int D[sizeD]; randomize(D, sizeD);
  Ordenador ordenador;

  int* arreglos[4] = {A,B,C,D};
  for (int arrActual = 0; arrActual < 4; ++arrActual) {
    int* array = arreglos[arrActual];
    int size = 0;
    if (arrActual == 0){cout << "Arreglo A | 50000\n";  size = 50000;}
    if (arrActual == 1){cout << "Arreglo B | 100000\n"; size = 100000;}
    if (arrActual == 2){cout << "Arreglo C | 150000\n"; size = 150000;}
    if (arrActual == 3){cout << "Arreglo D | 200000\n"; size = 200000;}
    
    auto selectionStart = chrono::system_clock::now();
    ordenador.seleccion(array, size);
    auto selectionEnd = chrono::system_clock::now();
    
    cout << "\n   Selection duration: " 
    << chrono::duration_cast<chrono::nanoseconds>(selectionEnd - selectionStart).count() 
    << " ns == ";
    duracionEnSegundos(selectionEnd, selectionStart);
    test(array, size);

    randomize(array, size);

    auto insertionStart = chrono::system_clock::now();
    ordenador.insercion(array, size);
    auto insertionEnd = chrono::system_clock::now();

    cout << "\n   Insertion duration: " 
    << chrono::duration_cast<chrono::nanoseconds>(insertionEnd - insertionStart).count() 
    << " ns == ";
    duracionEnSegundos(insertionEnd, insertionStart);
    test(array, size);
    randomize(array, size);

    auto mergeStart = chrono::system_clock::now();
    ordenador.mergesort(array, size);
    auto mergeEnd = chrono::system_clock::now();

    cout << "\n   MergeSort duration: " 
    << chrono::duration_cast<chrono::nanoseconds>(mergeEnd - mergeStart).count() 
    << " ns == ";
    duracionEnSegundos(mergeEnd, mergeStart);
    test(array, size);

    

    cout << endl << endl;
  }
}
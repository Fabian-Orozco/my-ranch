/**
 * Copyright 2021 <fabian.orozcochaves@ucr.ac.cr>.
 * Analisis de algoritmos y estructuras de datos - 2021 II Ciclo - B95690. T1P1.
 * Nota: uso de tildes omitido para evitar errores de interpretación con C++.
 * 
 * Se utiliza INT_MAX como centinela el cual sustituye al valor ∞ utilizado 
 * en el libro, para ello se incluye la biblioteca <limits.h>.
 * 
 * Se adjunta a cada implementacion la linea de pseudocodigo como buena
 * practica de programacion.
 */
#ifndef Ordenador_h
#define Ordenador_h

#include <limits.h> // para utilizar INT_MAX como centinela (sustituye a inf).

class Ordenador{
	private:
	// Defina aqu� los m�todos auxiliares de los algoritmos de ordenamiento solamente.
    // Puede definir cuantos m�todos quiera.

	void mergeSort(int* arr, int inicio, int fin){
        // if p < r
        if (inicio < fin) {
            // q = [(p + r) / 2]
            int mitad = (inicio + fin) / 2;

            // mergeSort(A,p,q)
            mergeSort(arr, inicio, mitad);
            // mergeSort(A,q + 1, r)
            mergeSort(arr, mitad + 1, fin);
            // merge(A,p,q,r)
            merge(arr, inicio, mitad, fin);
        }
    }

    void merge(int* arr, int izq, int mitad, int der) {
        // p = izquierda, q = mitad, r = derecha, A = arr
        // n1 = q - p + 1
        const int subArr1 = mitad - izq + 1;
        // n2 = r - q
        const int subArr2 = der - mitad;
        // let L[1..n1 + 1] and R[1..n2 + 1] be new arrays
        int* izqArray = new int[subArr1 + 1];
        int* derArray = new int[subArr2 + 1];

        // for i = 1 to n1
        for (int i = 0; i < subArr1; ++i) {
            // L[i] = A[p + i - 1]
            izqArray[i] = arr[izq + i];
        }
        // for j = 1 to n2
        for (int j = 0; j < subArr2; ++j) {
            // R[j] = A[q + j]
            derArray[j] = arr[mitad + 1 + j];
        }

        // L[n1 + 1] = inf
        izqArray[subArr1] = INT_MAX;
        // R[n2 + 1 ] = inf
        derArray[subArr2] = INT_MAX;
        // i = 1 
        int indexSubArr1 = 0;
        //j = 1
        int indexSubArr2 = 0;

        // k = p
        for (int indexMergeArr = izq; indexMergeArr <= der; indexMergeArr++) {
            // if L[i] <= R[j]
            if (izqArray[indexSubArr1] <= derArray[indexSubArr2]) {
                // A[k] = L[i]
                arr[indexMergeArr] = izqArray[indexSubArr1];
                // i = i + 1
                ++indexSubArr1;
            // else 
            } else {
                // A[k] = R[j]
                arr[indexMergeArr] = derArray[indexSubArr2];
                // j = j + 1
                ++indexSubArr2;
            }
        }
        // liberacion de memoria dinamica.
        delete [] izqArray;
        delete [] derArray;
    }

	public:
	Ordenador(){;}
	~Ordenador(){;}
	
	// Si piensa no implementar algunos de los m�todos de ordenamiento, no los borre,
	// simplemente d�jelos con el cuerpo vac�o para evitar errores de compilaci�n, ya
	// que se va a ejecutar el mismo �main� para todas las tareas.
    // Implemente los algoritmos en este archivo  (no en un CPP aparte).
	void seleccion(int *A, int n) {
        // Para i = 1...n
        for (int i = 0; i < n - 1; ++i) {
            // m = i
            int min = i;
            // Para j = i + 1...n
            for (int j = i + 1; j < n; ++j) {
                // si A[j] < A[m] // m = j
                if (A[j] < A[min]) min = j;
            }
            // t = A[i];
            int aux = A[i];
            // A[i] = A[m];
            A[i] = A[min];
            // A[m] = aux;
            A[min] = aux;
        }
	}

	void insercion(int *A, int n) {
		int j, key, i;
        // for j = 2 to A.length
		for (j=1; j < n; ++j) {
            //key = A[j]
            key = A[j];
            // insert A[j] into the sorted
                // sequence A[1...j-1]
            //i = j - 1
            i = j-1;
            // while i > 0 and A[i] > key
            while (i >= 0 && A[i] > key) {
                // A[i+1] = A[i]
                A[i+1] = A[i];
                // i = i-1
                --i;
            }
            // A[i+1] = key
            A[i+1] = key;
        }
	}

	void mergesort(int* A, int n) {
        mergeSort(A, 0, n-1);
    }
	void heapsort(int *A, int n);
	void quicksort(int *A, int n);
	void radixsort(int *A, int n);
};
#endif

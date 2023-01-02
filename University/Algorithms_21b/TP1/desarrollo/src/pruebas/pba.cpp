# include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void monticularizar(int* A, int size);
int extraerMaximo(int* A, int& size);
void corregirCima(int* A, int k);

void imprimir(int* array, int size) {
  for(int actual = 1; actual <= size; ++actual) {
    cout << " " << array[actual];
  }
}

void print(int* array, int size) {
  cout << "[";
  imprimir(array, size);
  cout << " ]" << endl;
}

    // Ordenar(A)
	void heapSort(int* A, int size) {
        cout << "entra a heapSort" << endl;
        A--;
        // Monticularizar(A)
        monticularizar(A,size);
        //   i = A.length
        int i = size;
        // while not Vacío(A)
        while (i > 0) {
            // A[i--] = Extraer-Máximo(A)
            A[i--] = extraerMaximo(A,i);
        }
    }
    // Monticularizar(A)
    void monticularizar(int* A, int size) { //  Convierte el arreglo A en un montículo.
        cout << "----------Monticularizar----------" << endl;
        // n = length(A)
        int n = size;
        cout << setw(10) << "n: " << n << endl; 

        // for k = n/2 rounddown to 1
        for(int k=floor(n/2)-1; k > 0; --k){
            cout << "--------------------------------------------------------------------------------k1: " << k << endl;
            // CORREGIR-CIMA(A,k)
            corregirCima(A,k);
        }
    }

    int max(int* A, int k) {
        cout << "\n-------------------Max-------------------" << endl;
        cout << "     "  << "k: " << k;

        int pMax = k;
        int max = A[k];

        cout << "     " << "Actual:  A[" << k << "]   "<< A[k];
        cout << "     "  << "hi:      A[" << 2*k << "]   " << A[2*k];
        if (max < A[2*k]) { pMax = 2*k; }
        cout << "     "  << "hd:      A[" << 2*k+1 << "]   " << A[2*k+1];
        if (max < A[2*k+1]) { pMax = 2*k+1; }
        cout << "     " << "\n    pMax: " << pMax << endl << endl;
        return pMax;
    }

    // Corregir-Cima(A, k)
    void corregirCima(int* A, int k) {
        cout << "\n-------------------CorregirCima-------------------" << endl;
        cout << "            " << endl; print(A,3);

        cout << "       " << "k2: " << k << endl;

        // j = arg máx { A[ k, hi(k), hd(k)] }
        int j = max(A,k);
        cout << "       " << "j: " << j << endl;
        // if k != j
        if (k != j && j < k) {
            cout << "       " << "regresa a corregirCima: "  << endl;

        // intercambie( A[k], A[j] )
            cout << "       " << "k: " << k << "  j  " << j << endl;
            cout << "       " << "A[k]  " << A[k] << "A[j]  " << A[j] << endl; 
            std::swap(A[k], A[j]);
            cout << "       " << "hace swap1: "  << endl;
        // Corregir-Cima(A, j)
            corregirCima(A,j);
            cout << "       " << "sale de corregirCima2: "  << endl;
        }
        cout << "            " << endl; print(A,3);
    }

    // Extraer-Máximo(A)
    int extraerMaximo(int* A, int& size) { // Devuelve el máximo y lo saca del montículo.
        cout << "\n----------------Entra a extraerMaximo---------------" << endl;
        // m = A[1]
        int m = A[1];
        cout << "   " << "maximo actual: " << m << endl;

        // A[1] = A[A.length−−]
        // int n = size;
        cout << "   " << "A[1]" << A[1] << endl;
        A[1] = A[ size-- ];
        cout << "   " << "A[1]" << A[1] << endl;

        // Corregir-Cima(A, 1)
        corregirCima(A, 1);
        // return m
        return m;
    }
	void heapsort(int* A, int n) {
        cout << "entra a HS" << endl;
        heapSort(A,n);
    }

int main(){
    int A[] = {1,3,2};
    int n = 3;
    print(A,n);

    heapsort(A,n);
    print(A,n);

    return 0;
}
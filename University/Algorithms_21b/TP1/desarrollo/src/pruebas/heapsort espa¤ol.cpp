
    // Ordenar(A)
	void heapSort(int* A, int size) {
        // cout << "entra a heapSort" << endl;
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
        // cout << "entra a monticularizar" << endl;
        // n = length(A)
        int n = size;
         cout << "n: " << n << endl; 

        // for k = n/2 rounddown to 1
        for(int k=floor(n/2); k > 1; --k){
            // cout << "k 1: " << k << endl;
            // CORREGIR-CIMA(A,k)
            corregirCima(A,k);
        }
    }

    int max(int* A, int k) {
        // cout << "entra a max" << endl;
        // cout << "k 3: " << k << endl;

        int pMax = k;
        int max = A[k];
        if ( A[ 2*k ] ) { // si existe el hijo izquierdo
        // cout << "entra a if: " << A[2*k] << endl;

            int hi = A[2*k];
            if (max < hi) {
                pMax = 2*k;
            }
        }
        
        if (A[ 2*k + 1 ] ) { // si existe el hijo derecho
        // cout << "entra a if: " << A[2*k+1] << endl;

            int hd = A[2*k+1];
            if (max < hd) {
                pMax = 2*k+1;
            }
        }
        // cout << "sale de max: " << pMax << endl;
        
        return pMax;
    }

    // Corregir-Cima(A, k)
    void corregirCima(int* A, int k) {
        // cout << "entra a corregirCima" << endl;
        // cout << "k 2: " << k << endl;

        // j = arg máx { A[ k, hi(k), hd(k)] }
        int j = max(A,k);
        // cout << "j: " << j << endl;
        // if k != j
        if (k != j) {
            // cout << "regresa a corregirCima: "  << endl;

        // intercambie( A[k], A[j] )
            // cout << "k: " << k << "  j  " << j << endl;
            // cout << "A[k]  " << A[k] << "A[j]  " << A[j] << endl; 
            std::swap(A[k], A[j]);
            // cout << "hace swap1: "  << endl;
        // Corregir-Cima(A, j)
            corregirCima(A,j);
            // cout << "sale de corregirCima2: "  << endl;
        }
    }

    // Extraer-Máximo(A)
    int extraerMaximo(int* A, int size) { // Devuelve el máximo y lo saca del montículo.
        // cout << "entra a extraerMaximo" << endl;
        // m = A[1]
        int m = A[1];
        // A[1] = A[A.length−−]
        int n = size;
        A[1] = A[ n-- ];
        // Corregir-Cima(A, 1)
        corregirCima(A, 1);
        // return m
        return m;
    }


	void heapsort(int* A, int n) {
        // cout << "entra a HS" << endl;
        heapSort(A,n);
    }
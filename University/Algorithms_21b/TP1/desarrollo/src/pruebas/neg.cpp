void countingSort(int* A, int m, bool ascending, int size) {
	int i, n = size, exp = 1;
	int *b = new int[n];

	if (ascending == true) {
		while (m / exp > 0) {
			int auxiliar[10];
			for (int i = 0; i < 10; ++i)
				auxiliar[i] = 0;
			for (i = 0; i < n; i++)
				auxiliar[(A[i] / exp) % 10]++;
			for (i = 1; i < 10; i++)
				auxiliar[i] += auxiliar[i - 1];
			for (i = n - 1; i >= 0; i--)
				b[--auxiliar[(A[i] / exp) % 10]] = A[i];
			for (i = 0; i < n; i++)
				A[i] = b[i];
			exp *= 10;
		}
	} else {
		// Este es el mismo algoritmo pero para ordenar en orden desciente
		while (m / exp > 0) {
			int auxiliar[10];
			for (int i = 0; i < 10; ++i)
				auxiliar[i] = 0;
			for (i = 0; i < n; i++)
				auxiliar[9 - A[i] / exp % 10]++;
			for (i = 1; i < 10; i++)
				auxiliar[i] += auxiliar[i - 1];
			for (i = n - 1; i >= 0; i--)
				b[--auxiliar[9 - A[i] / exp % 10]] = A[i];
			for (i = 0; i < n; i++) {
				A[i] = b[i];
			}
			exp *= 10;
		}
	}
	delete[] b;
}

void radixsort(int *A, int n) {
	int i, nNeg = 0, length = n, j = 0, k = 0, max, min, posi = 0;
	int indice = 0;
	// Busca cuantos numeros son negativos en el arreglo
	for (i = 0; i < length; i++) {
		if (A[i] < 0) {
			nNeg++;
		} else {
			posi++;
		}
	}
	//Crea arreglos con numeros negativos y positivos si estos existen
	int *negNumbers = new int[nNeg];
	int *posNumbers = new int[posi];
	for (i = 0; i < length; i++) {
		if (A[i] < 0) {
			negNumbers[j] = A[i];
			j++;
		} else {
			posNumbers[k] = A[i];
			k++;
		}
	}
	if (nNeg != 0) {
		//Buscar valor minimo
		min = negNumbers[0];
		// Convierte los valores negativos A positivos (temporalmente)
		negNumbers[0] *= -1;
		for (i = 1; i < nNeg; i++) {
			negNumbers[i] *= -1;
			if (negNumbers[i] > min)
				min = negNumbers[i];
		}
		// Llama metodo sort (ultimo parametro es true si se quiere orden ascendiente y false desciente)
		countingSort(negNumbers, min, false, nNeg);
		// Convierte los valores de los numeros negativos ordenados desciendietemente A negativos
		for (i = 0; i < nNeg; i++) {
			negNumbers[i] *= -1;
			A[indice] = negNumbers[i];
			indice++;
		}
		delete[] negNumbers;
	}
	if (posi != 0) {
		// Busca valor maximo
		max = posNumbers[0];
		for (i = 1; i < posi; i++) {
			if (posNumbers[i] > max)
				max = posNumbers[i];
		}
		// Llama metodo sort (ultimo parametro es true si se quiere orden ascendiente y false desciente)
		countingSort(posNumbers, max, true, posi);
		for (i = 0; i < posi; i++) {
			A[indice] = posNumbers[i];
			indice++;
		}
		delete[] posNumbers;
	}
}

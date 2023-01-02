#ifndef Ordenador_h
#define Ordenador_h

class Ordenador{
	private:
	// Defina aqu� los m�todos auxiliares de los algoritmos de ordenamiento solamente.
    // Puede definir cuantos m�todos quiera.
	
	public:
	Ordenador();
	~Ordenador();
	
	// Si piensa no implementar algunos de los m�todos de ordenamiento, no los borre,
	// simplemente d�jelos con el cuerpo vac�o para evitar errores de compilaci�n, ya
	// que se va a ejecutar el mismo �main� para todas las tareas.
    // Implemente los algoritmos en este archivo  (no en un CPP aparte).
	void seleccion(int *A, int n);
	void insercion(int *A, int n);
	void mergesort(int *A, int n);
	void heapsort(int *A, int n);
	void quicksort(int *A, int n);
	void radixsort(int *A, int n);
};
#endif

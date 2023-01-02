#ifndef LINKED_LIST_llist
#define LINKED_LIST_llist
#include <iostream>

// Nodos de la lista:
template <typename T>
class llnode{
public:
    // Esta clase es para ser usada por otras clases.
    // Por eficiencia los atributos se dejan publicos.
    T key;
    llnode<T> *prev, *next;
    //enum colors color;
    
    // Constructor por omision.
    llnode(){
    };
    
    // Inicializacion de los datos miembro.
    llnode (const T& k, llnode<T> *w = NULL, llnode<T> *y = NULL):key(k), prev(w), next(y) {};
    
    ~llnode(){
        
    }
};

// Lista enlazada con nodo centinela:
template <typename T>
class llist{
public:
    // Constructor (crea una lista vacia)
    llist(){
    };
    
    // Destructor (borra la lista)
    ~llist(){
    };
    
    // Busca la llave iterativamente. Si la encuentra, devuelve un
    // apuntador al nodo que la contiene; sino devuelve NULL.
    llnode<T>* listSearch(const T& k){
    };
    
    // Inserta el nodo x en la lista.
    void listInsert(llnode<T>* x){
    };
    
    // Saca de la lista la llave contenida en el nodo apuntado por x.
    // Devuelve la direccion del nodo eliminado para que se pueda
    // disponer de el.
    llnode<T>* listDelete(llnode<T>* x){
    };
    
    // Devuelve el nodo centinela. (Para efectos de revision de la tarea).
    llnode<T> * getNil() const{
        return this->nil;
    };
    
private:
    
    llnode<T> *nil;        // nodo centinela
    
};

#endif    // LINKED_LIST_llist

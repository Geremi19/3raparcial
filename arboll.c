#include <stdio.h>
#include <stdlib.h>

struct nodo{
    struct nodo* hijo_izq;
    struct nodo* hijo_der;
    int dato;
};

struct nodo* nuevoNodo(int dato){
    size_t tam_nodo = sizeof(struct nodo); //size_t es un tipo de dato y sizeof mide el tamaño del struct
    struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo); //mallo = memory allocation, aloja un valor en nuevo_nodo
    nuevo_nodo -> dato = dato;
    nuevo_nodo -> hijo_izq = NULL;
    nuevo_nodo -> hijo_der = NULL;
    return nuevo_nodo;
}

void insertarNodo(struct nodo* nd, int dato){
    if(dato > nd->dato){
        if(nd -> hijo_der == NULL){
            nd -> hijo_der = nuevoNodo(dato);
        }else{
            insertarNodo(nd -> hijo_der, dato);
        }
    }else{
        if(nd -> hijo_izq == NULL){
            nd -> hijo_izq = nuevoNodo(dato);
        }else{
            insertarNodo(nd -> hijo_izq, dato);
        }
    }
}

int raiz = 0 ;
void  busqueda ( struct nodo* nd, int n){
	raiz++;
	if (n == nd-> dato){
		printf ( " \n %d se encuentra en el nivel %d \n ", n, raiz);
	} else if (n < nd-> dato && nd-> hijo_izq != NULL ){
		busqueda (nd-> hijo_izq , n);
	} else  if (n > nd-> dato && nd-> hijo_der != NULL ){
		busqueda (nd-> hijo_der , n);
	} else {
		printf ( " \n %d Nodo no encontrado \n " , n);
	}
}



void preorden(struct nodo* nd) {
    if (nd != NULL) {
        printf("%d,",nd ->dato);
        preorden(nd -> hijo_izq);
        preorden(nd->hijo_der);
    }
}
void inorden(struct nodo *nd) {
    if (nd != NULL) {
        inorden(nd->hijo_izq);
        printf("%d,", nd->dato);
        inorden(nd->hijo_der);
    }
}
void postorden(struct nodo *nd) {
    if (nd != NULL) {
        postorden(nd->hijo_izq);
        postorden(nd->hijo_der);
        printf("%d,", nd->dato);
    }
}
int main(){
    struct nodo* raiz = NULL;
    raiz = nuevoNodo(8);
    insertarNodo(raiz, 3);
    insertarNodo(raiz, 20);
    preorden(raiz);
    printf("\n");
    inorden(raiz);
    printf("\n");
    postorden(raiz);
    printf ( " \n Ingrese el numero que desea buscar \n " );
	scanf ( " %d ", &n);
	busqueda (raiz, &n);
    return 0;
}
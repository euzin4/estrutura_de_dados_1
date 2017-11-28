#include <stdio.h>
#include <stdlib.h>
#define Tam 8

typedef struct _nodo{
    int chave;
    struct _nodo *next;
}nodo;
typedef struct _lista{
    nodo *inicio[Tam];
}lista;


int main(){
    lista *lst;
    int i;

    //terminar
}

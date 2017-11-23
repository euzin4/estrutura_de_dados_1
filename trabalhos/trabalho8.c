#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct _ins{
    int val;
    struct _ins *first;
    struct _ins *next;
}NodoH;

void hash(int *vet){
    int val1,hs;

    hs=val1%TAM;
    vet[hs]=
}
void menu(int *vet){
    int m;
    printf("\tMENU\n");
    printf("1-inserir dados\n");
    printf("2-exibir dados\n");
    scanf("%d",&m);
    while(1){
        switch(m){
        case 1:
            hash(vet);
            break;
        /*case 2:
            display(vet);
            break;*/
        default:
            printf("opcao invalida!\n");
            aux(vet);
        }
    }
}
void aux(int *vet){
    menu(vet);
}

int main(){
    int vet[TAM];
    int i;
    NodoH *nodo;

    for(i=0;i<10;i++){
        vet[i]=(nodo=(NodoH*) malloc(sizeof(NodoH)));
        nodo->first=nodo;
    }
    menu(vet);
}

#include <stdio.h>
#include <stdlib.h>

int insertion(int *vet){
    int i,aux;

    for(i=1;i<6;i++){
        aux=vet[i];
        while(vet[i]<vet[i-1]){
            aux=vet[i-1];
            vet[i-1]=vet[i];
            vet[i]=aux;
        }
    }
}
void display(int *vet){
    int i;

    for(i=0; i<6; i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}

int main(){
    int vet[6]= {4,9,2,1,3,7};

    display(vet);
    insertion(vet);         //função
    display(vet);
}

#include <stdio.h>
#include <stdlib.h>

void selection(int *vet, int tam) {
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++){
     min = i;
     for (j = (i+1); j < tam; j++){
       if(vet[j] < vet[min])
         min = j;
     }
     if (vet[i] != vet[min]){
       aux = vet[i];
       vet[i] = vet[min];
       vet[min] = aux;
     }
  }
}
void display(int *vet){
    int i;

    for(i=0;i<5;i++){
        printf("%d",*(vet+i));
    }
    printf("\n");
}

int main(){
    int vet[5]={3,7,1,8,1};
    int tam=5;

    display(vet);
    selection(vet,tam);
    display(vet);
    return 0;
}

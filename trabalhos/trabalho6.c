#include <stdio.h>
#include <stdlib.h>

void selection(int *vet, int tam) {
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++)
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(*(vet+j) < *(vet+min))
         min = j;
     }
     if (*(vet+i) != *(vet+min)) {
       aux = *(vet+i);
       *(vet+i) = *(vet+min);
       *(vet+min) = aux;
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

int main()
{
    int *vet;
    int i;

    vet=(int *) malloc(5*sizeof(int));
    *(vet+0)=5;
    *(vet+1)=3;
    *(vet+2)=6;
    *(vet+3)=1;
    *(vet+4)=0;
    display(vet);
    selection(vet,5);
    display(vet);
    return 0;
}

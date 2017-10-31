#include <stdio.h>
#include <stdlib.h>

void insertion(int *vet){
    int cont,pos,aux;

    for(cont=1;cont<5;cont++){  // cont começa na posição 1 do vetor e vai até a ultima posição;
        pos = cont; // pos recebe a posição que está passando no "for";
        while (vet[pos]<vet[pos-1]) // Enquanto o valor que está passando na posição "pos" for menor que a posição "pos" menos 1, ocorre a troca;
        { // Ocorre a troca;
            aux=vet[pos];
            vet[pos]=vet[pos-1];
            vet[pos-1]=aux;
            pos--; // pos decrementa 1;
            if (pos == 0){ // Quando "pos" chegar na posição 0, primeira posição do vetor, o laço while para;
                break;
            }
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
    int vet[5]={9,7,2,4,5};

    display(vet);
    insertion(vet);
    display(vet);
}

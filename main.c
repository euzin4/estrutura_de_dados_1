#include <stdio.h>
#include <stdlib.h>

int bubble(int *vet){
    int i,j,aux;

    for(i=0; i<6; i++){
        for(j=0; j<6; j++){
            if(vet[j]>vet[j+1]){
                if(j+1!=6){
                    aux=vet[j+1];
                    vet[j+1]=vet[j];
                    vet[j]=aux;
                }
            }
        }
    }
    return *vet;
}
void display(int *vet){
    int i;

    for(i=0; i<6; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
}
int main(){
    int vet[6]= {4,9,2,1,3,7};

    display(vet);
    *vet=bubble(vet);
    display(vet);
}

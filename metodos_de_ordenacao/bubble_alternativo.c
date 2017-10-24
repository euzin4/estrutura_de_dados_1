#include <stdio.h>
#include <stdlib.h>

int bubble(int *vet){
    int j,aux;

    for(j=0; j<6; j++){
        if(vet[j]>vet[j+1]){
            if(j+1!=6){
                aux=vet[j+1];
                vet[j+1]=vet[j];
                vet[j]=aux;
                j=-1;
            }
        }
    }
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
    bubble(vet);
    display(vet);
}

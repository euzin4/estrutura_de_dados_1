#include <stdio.h>
#include <stdlib.h>

void selection(int *vet){
    int menor,cont,temp,troca;

    for(cont=0;cont<4;cont++){ //Percorre todo o vetor até 4, pois a ultima posição não precisa testar pois ja estara ordenada;
        menor=cont; // Menor valor recebe a posição que está passando;

        for (temp=cont+1;temp<5;temp++){ // Percorre o vetor da posição cont+1 até o final;
            if (vet[temp]<vet[menor]){ // Testa se a posição que está passando é menor que o menor valor;
                menor=temp; // menor recebe a posição do menor valor;
            }
        }
        if (menor!=cont){ // Se a posição for diferente da que está passando, ocorre a troca;
            troca=vet[cont];
            vet[cont]=vet[menor];
            vet[menor]=troca;
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
    int vet[5]={3,7,1,8,1};

    display(vet);
    selection(vet);
    display(vet);
}

#include <stdio.h>
#include <stdlib.h>
#define TAM 10
void bubble(int *vet){
    int i,j,aux;

    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            if(vet[j]>vet[j+1]){
                if(j+1!=TAM){
                    aux=vet[j+1];
                    vet[j+1]=vet[j];
                    vet[j]=aux;
                }
            }
        }
    }
}
void display(int *vet){
    int i;

    for(i=0; i<TAM; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
}
void inserir(int *vet){
    int i;

    printf("Insira os valores\n");
    for(i=0;i<TAM;i++){
        printf("valor %d:",i+1);
        scanf("%d",&vet[i]);
    }
    bubble(vet);
}
// x => chave | *vet => vetor ordenado | e => limite inferior (esquerda) | d => limite superior (direita)
//int x, int v[], int e, int d
void bbin(int *vet){
    int x,e,d;

    printf("Procurar o numero:");
    scanf("%d",&x);
    e=vet[0];
    d=vet[TAM-1];
    pbin(x,vet,e,d);
}
int pbin (int x, int *vet, int e, int d){
 int meio = (e + d)/2;
 if (vet[meio] == x)
    return meio;
 if (e >= d)
    return -1; // não encontrado
 else
     if (vet[meio] < x)
        return pbin(x,vet,meio+1,d);
     else
        return pbin(x,vet,e,meio-1);
}

int main(){
    int vet[TAM]={10,9,8,7,6,5,4,3,2,1};

    //inserir(vet);
    bubble(vet);
    bbin(vet);
}

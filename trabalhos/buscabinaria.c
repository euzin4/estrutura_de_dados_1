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
void bbin(int *vet){
    int x,e,d;

    printf("Procurar o numero:");
    scanf("%d",&x);
    e=0;
    d=TAM-1;
    pbin(x,vet,e,d);
}
// x => chave | *vet => vetor ordenado | e => limite inferior (esquerda) | d => limite superior (direita)
void pbin (int x, int *vet, int e, int d){
 int meio = (e + d)/2;
 if (vet[meio] == x){
    printf("Valor encontrado na posicao %d\n",meio);
    return;
}
 if (e >= d){
    printf("Valor não encontrado!\n");
    return;
}
 else
     if (vet[meio] < x)
        pbin(x,vet,meio+1,d);
     else
        pbin(x,vet,e,meio-1);
}

int main(){
    int vet[TAM];

    inserir(vet);
    display(vet);
    bbin(vet);
}

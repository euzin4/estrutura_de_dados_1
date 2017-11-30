#include <stdio.h>
#include <stdlib.h>
#define Tam 8

typedef struct _nodo{
    int chave;
    struct _nodo *next;
}nodo;
typedef struct _lista{
    nodo *inicio[Tam];
    nodo *nodo[Tam];
}lista;

void add(lista *lst){
    int val,pos;

    system("cls");
    printf("Digite o valor:");
    scanf("%d",&val);
    pos=val%Tam;
    lst->nodo[pos]->chave=val;
    lst->nodo[pos]->next=(nodo*) malloc(sizeof(nodo));
    lst->nodo[pos]=lst->nodo[pos]->next;
    lst->nodo[pos]->chave=-1;
    lst->nodo[pos]->next=NULL;
    system("cls");
    printf("Valor adicionado!\n\n");
}
void display(lista *lst){
    int val,pos,opc,i,verif=0;

    system("cls");
    printf("1-Buscar posicao do valor\n");
    printf("2-Listar posicao do vetor\n");
    printf("3-Listar vetor completo\n");
    scanf("%d",&opc);
    switch(opc){
        case 1:
            system("cls");
            printf("Digite o valor: ");
            scanf("%d",&val);
            pos=val%Tam;
            lst->nodo[pos]=lst->inicio[pos];
            while(lst->nodo[pos]->chave!=-1){
                if(lst->nodo[pos]->chave==val)
                    verif=1;
                lst->nodo[pos]=lst->nodo[pos]->next;
            }
            if(verif==1)
                printf("Valor na posicao [%d] do vetor\n\n",pos);
            if(verif==0)
                printf("Valor nao encontrado!\n\n");
        break;
        case 2:
            system("cls");
            printf("Digite a posicao: ");
            scanf("%d",&pos);
            lst->nodo[pos]=lst->inicio[pos];
            while(lst->nodo[pos]->chave!=-1){
                if(lst->nodo[pos]->chave!=-1)
                    verif=1;
                lst->nodo[pos]=lst->nodo[pos]->next;
            }
            if(verif==0){
                printf("Posicao [%d] do vetor: vazia!",pos);
                printf("\n\n");
            }
            if(verif==1){
                printf("Valores na posicao [%d] do vetor: ",pos);
                lst->nodo[pos]=lst->inicio[pos];
                while(lst->nodo[pos]->chave!=-1){
                    printf("%d; ",lst->nodo[pos]->chave);
                    lst->nodo[pos]=lst->nodo[pos]->next;
                }
            printf("\n\n");
            }
        break;
        case 3:
            system("cls");
            for(i=0;i<Tam;i++){
                lst->nodo[i]=lst->inicio[i];
                printf("Posicao [%d]: ",i);
                if(lst->nodo[i]->chave==-1){
                    printf("Vazia");
                }else{
                    while(lst->nodo[i]->chave!=-1){
                        printf("%d; ",lst->nodo[i]->chave);
                        lst->nodo[i]=lst->nodo[i]->next;
                    }
                }
                printf("\n");
            }
            printf("\n");
        break;
    }
}
void menu(lista *lst){
    int opc;

    while(opc!=3){
        printf("\tMENU\n");
        printf("1-Adicionar item\n");
        printf("2-Buscar item\n");
        printf("3-sair\n");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                add(lst);
                break;
            case 2:
                display(lst);
                break;
            case 3:
                printf("\nAte logo!\n");
                break;
            default:
                system("cls");
                printf("Opcao invalida!\n\n");
        }
    }
}

int main(){
    lista *lst;
    int i;

    lst=(lista*) malloc(sizeof(lista));
    for(i=0;i<Tam;i++){
        lst->inicio[i]=(nodo*) malloc(sizeof(nodo));
        lst->inicio[i]->chave=-1;
        lst->inicio[i]->next=NULL;
        lst->nodo[i]=lst->inicio[i];
    }
    menu(lst);
    return 0;
}

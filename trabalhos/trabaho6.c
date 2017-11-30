#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _produto{
    int codigo;
    char nome[20];
    float preco;
} TpProduto;
typedef struct _nodo{
    TpProduto info;
    struct _nodo *next;
    struct _nodo *prev;
} TpNodo;
typedef struct _lista{
    int nItens;
    TpNodo *first;
    TpNodo *last;
} TpLista;

void selection(TpLista *novo){
    int h,h1,h1min,i,j,atual;
    int min,proximo;
    TpNodo atu,men;

    if(novo->nItens > 1){
        for (i=0; i < novo->nItens-1;i++){
            novo->last=novo->first;
            for(h=0;h<i;h++){   //vai para o nodo que será testado
                novo->last=novo->last->next;
            }
            //copia os dados do nodo atual
            min=novo->last->info.codigo;
            atu.next=novo->last->next;
            atu.prev=novo->last->prev;
            for (j=(i+1);j < novo->nItens;j++){
                novo->last=novo->first;
                for(h1=0;h1<j;h1++){    //passa pelos nodos para achar o menor codigo
                    novo->last = novo->last->next;
                }
                proximo=novo->last->info.codigo;
                if(proximo < min){   //copia os dados do nodo com codigo menor
                    min=proximo;
                    men.next=novo->last->next;
                    men.prev=novo->last->prev;
                    h1min=h1;
                }
            }
            novo->last=novo->first;
            for(h=0;h<i;h++){   //volta para o nodo que esta sendo testado
                novo->last=novo->last->next;
            }
            atual=novo->last->info.codigo;
            if (atual != min){  //faz o reaponteiramento dos nodos
                if(men.prev == novo->last){ //caso os nodos estejam um ao lado do outro
                    if(atu.next->prev == novo->first){  //caso o nodo a ser reaponteirado for o primeiro da lista
                        novo->first=men.next->prev;
                    }
                    if(atu.prev != NULL){
                        atu.prev->next=atu.next;
                    }
                    men.prev->prev=atu.next;
                    atu.next->next=men.prev;
                    men.next->prev=men.prev;
                    men.prev->next=men.next;
                    atu.next->prev=atu.prev;
                }else{  //caso os nodos não estejam um ao lado do outro
                    if(atu.next->prev == novo->first){  //caso o nodo a ser reaponteirado for o primeiro da lista
                        novo->first=men.next->prev;
                    }
                    if(atu.prev != NULL){
                        atu.prev->next=men.next->prev;
                    }
                    atu.next->prev->prev=men.prev;
                    atu.next->prev->next=men.next;
                    atu.next->prev=men.next->prev;
                    men.prev->next=novo->last;
                    men.next->prev->prev=atu.prev;
                    men.next->prev->next=atu.next;
                    men.next->prev=novo->last;
                }
            }
        }
        system("cls");
        printf("Lista ordenada!\n\n");
    }else{
        system("cls");
        printf("Itens insuficientes!\n\n");
    }
    menu(novo);
}
void insertion(TpLista *novo){
    int i,j;
    TpNodo ant,atu;

    if(novo->nItens > 1){
        for(i=1;i < novo->nItens;i++){
            novo->last=novo->first->next;   //inicia no segundo nodo da lista
            for(j=1;j<i;j++){
                novo->last = novo->last->next;  //passa para o nodo de testes
            }
            while(novo->last->info.codigo < novo->last->prev->info.codigo && novo->last->prev->info.codigo!=NULL){
                //copias de endereços
                atu.next=novo->last->next;
                atu.prev=novo->last->prev;
                ant.next=novo->last->prev->next;
                ant.prev=novo->last->prev->prev;
                //reaponteiramento
                novo->last->prev->next=atu.next;
                novo->last->next->prev=atu.prev;
                novo->last->next=atu.prev;
                if(novo->last->prev->prev != NULL){
                    novo->last->prev->prev->next=ant.next;
                }
                novo->last->prev->prev=ant.next;
                novo->last->prev=ant.prev;
                //após o reaponteiramento o nodo atual vai uma "casa" para trás
                if(novo->last->prev == NULL){
                    novo->first=novo->last;
                    break;
                }
            }
        }
        system("cls");
        printf("Lista ordenada!\n\n");
    }else{
        system("cls");
        printf("Itens insuficientes!\n\n");
    }
    menu(novo);
}
void push(TpLista *novo){
    TpNodo *aux;
    int codigo=0;

    system("cls");
    while(codigo == 0){
        printf("Codigo (diferente de zero): ");
        scanf("%d",&codigo);
    }
    if(codigo != 0){
        novo->last->info.codigo = codigo;
    }
    printf("Nome: ");
    getchar();
    fgets(novo->last->info.nome,19,stdin);
    printf("Preco: ");
    scanf("%f",&novo->last->info.preco);
    aux=novo->last;
    novo->last->next=(TpNodo*) malloc(sizeof(TpNodo));
    novo->last=novo->last->next;
    novo->last->prev=aux;
    novo->last->next=NULL;
    novo->last->info.codigo=0;
    novo->nItens+=1;
    system("cls");
    menu(novo);
}
void display(TpLista *novo){
    int i=0;
    system("cls");
    novo->last=novo->first;
    if(novo->last->next==NULL){
        printf("Lista vazia!\n\n");
    }
    else{
        printf("Lista: %d produto(s)\n\n",novo->nItens);
        while(novo->last->next!=NULL && novo->nItens!=i){
            printf("Codigo: %d\n",novo->last->info.codigo);
            printf("Nome: %s",novo->last->info.nome);
            printf("Preco: R$%0.2f\n\n",novo->last->info.preco);
            novo->last=novo->last->next;
            i++;
        }
    }
    menu(novo);
}
void pop(TpLista *novo){
    int aux,i=0;
    TpNodo *ant;
    TpNodo *auxi;

    system("cls");
    if(novo->first->next==NULL){
        printf("Lista vazia!\n\n");
    }else{
        printf("Digite o codigo do produto que sera excluido: ");
        scanf("%d",&aux);
        if(novo->first->info.codigo==aux){
            novo->first=novo->first->next;
            novo->first->prev=NULL;
            novo->nItens-=1;
            system("cls");
            printf("Item excluido!\n\n");
        }else{
            novo->last=novo->first;
            while(novo->last->info.codigo!=aux && novo->last->next!=NULL){
                ant=novo->last;
                novo->last=novo->last->next;
            }
            if(novo->last->info.codigo==aux){
                ant->next=novo->last->next;
                auxi=novo->last->next;
                auxi->prev=novo->last->prev;
                novo->nItens-=1;
                system("cls");
                printf("Item excluido!\n\n");
            }else{
                system("cls");
                printf("Este item nao esta na lista!\n\n");
            }
        }
    }
    menu(novo);
}
void menu(TpLista *novo){
    int opc;

    printf("\tMENU\n");
    printf("1-inserir produto na lista\n");
    printf("2-excluir produto da lista\n");
    printf("3-listar dados dos produtos da lista\n");
    printf("4-ordenar via insertion sort\n");
    printf("5-ordenar via selection sort\n");
    //printf("6-ordenar via quick sort ou merge sort\n");
    printf("7-sair\n");
    scanf("%d",&opc);
    switch(opc){
    case 1:
        push(novo);
        break;
    case 2:
        pop(novo);
        break;
    case 3:
        display(novo);
        break;
    case 4:
        insertion(novo);
        break;
    case 5:
        selection(novo);
        break;
    case 7:
        printf("\nAte logo!");
        break;
    default:
        system("cls");
        printf("Opcao invalida!\n\n");
        menu(novo);
    }
}

int main(){
    TpLista *novo;

    novo=(TpLista*) malloc(sizeof(TpLista));
    novo->first=(TpNodo*) malloc(sizeof(TpNodo));
    novo->last=novo->first;
    novo->last->prev=NULL;
    novo->last->next=NULL;
    novo->last->info.codigo=0;
    novo->nItens=0;
    menu(novo);

    return 0;
}

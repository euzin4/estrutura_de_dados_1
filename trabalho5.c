#include <stdio.h>
#include <stdlib.h>

typedef struct _produto
{
    int codigo;
    char nome[20];
    float preco;
} TpProduto;
typedef struct _nodo
{
    TpProduto info;
    struct _nodo *next;
    struct _nodo *prev;
} TpNodo;
typedef struct _lista
{
    int nItens;
    TpNodo *first;
    TpNodo *last;
} TpLista;

void push(TpLista *novo)
{
    TpNodo *aux;

    system("clear");
    printf("Codigo: ");
    scanf("%d",&novo->last->info.codigo);
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
    novo->nItens+=1;
    system("clear");
    menu(novo);
}
void display(TpLista *novo)
{
    int i=0;
    system("clear");
    novo->last=novo->first;
    if(novo->last->next==NULL)
    {
        printf("Lista vazia!\n\n");
    }
    else
    {
        printf("Lista: %d produto(s)\n\n",novo->nItens);
        while(novo->last->next!=NULL && novo->nItens!=i)
        {
            printf("Codigo: %d\n",novo->last->info.codigo);
            printf("Nome: %s",novo->last->info.nome);
            printf("Preco: R$%0.2f\n\n",novo->last->info.preco);
            novo->last=novo->last->next;
            i++;
        }
    }
    menu(novo);
}
void pop(TpLista *novo)
{
    int aux,i=0;
    TpNodo *ant;
    TpNodo *auxi;

    system("clear");
    if(novo->first->next==NULL){
        printf("Lista vazia!\n\n");
    }else{
        printf("Digite o codigo do produto que sera excluido: ");
        scanf("%d",&aux);
        if(novo->first->info.codigo==aux){
            novo->first=novo->first->next;
            novo->first->prev=NULL;
            novo->nItens-=1;
            system("clear");
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
                system("clear");
                printf("Item excluido!\n\n");
            }else{
                system("clear");
                printf("Este item nao esta na lista!\n\n");
            }
        }
    }
    menu(novo);
}
void aux(TpLista *novo)
{
    menu(novo);
}
void menu(TpLista *novo)
{
    int opc;

    printf("1-inserir produto na lista\n2-excluir produto da lista\n3-listar dados dos produtos da lista\n4-sair\n");
    scanf("%d",&opc);
    switch(opc)
    {
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
        printf("\nAte logo!");
        break;
    default:
        system("clear");
        printf("Opcao invalida!\n\n");
        aux(novo);
    }
}
int main()
{
    TpLista *novo;

    novo=(TpLista*) malloc(sizeof(TpLista));
    novo->first=(TpNodo*) malloc(sizeof(TpNodo));
    novo->last=novo->first;
    novo->last->prev=NULL;
    novo->last->next=NULL;
    novo->nItens=0;
    menu(novo);
}

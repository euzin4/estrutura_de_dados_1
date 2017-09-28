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

void push(TpLista *novo){
    printf("Codigo: ");
    scanf("%d",&novo->last->info.codigo);
    printf("Nome: ");
    fgets(novo->last->info.nome,19,stdin);
    printf("Preco: ");
    scanf("%f",&novo->last->info.preco);
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
        //pop(novo);
        break;
    case 3:
        //display(novo);
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
    novo->last=novo->first;
    novo->last=NULL;        //acho que isso está causando erros de segmentação
    novo->nItens=0;

    novo->last->info.codigo=1;
    printf("%d",novo->last->info.codigo);

    menu(novo);
}

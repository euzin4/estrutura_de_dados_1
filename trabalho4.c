#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 100
typedef struct produto
{
    int codigo;
    char nome[TAM];
    float preco;
} tp_produto;
typedef struct nodo
{
    tp_produto produto;
    struct nodo *prox;
    int cont;
} tp_nodo;

void dados(tp_nodo *nodo)
{
    printf("codigo: ");
    scanf("%d",&nodo->produto.codigo);
    printf("nome: ");
    getchar();
    fgets(nodo->produto.nome,99,stdin);
    printf("preco: ");
    scanf("%f",&nodo->produto.preco);
}
void push(tp_nodo *nodo)
{
    if(nodo->cont > 0){
        nodo->prox=(tp_nodo*)malloc(nodo->cont*sizeof(tp_nodo));
    }
    dados(nodo);
    tp_nodo *novo=(tp_nodo*)malloc(sizeof(tp_nodo));
    nodo->prox=novo;
    nodo->cont++;
    menu(nodo);
}
void aux()
{
    menu();
}
void menu(tp_nodo *nodo)
{
    int opc;

    printf("1-inserir produto na lista\n2-excluir produto da lista\n3-listar dados dos produtos da lista\n4-sair\n");
    scanf("%d",&opc);
    switch(opc)
    {
    case 1:
        push(nodo);
        break;
    case 2:
//            pop(nodo);
        break;
    case 3:
//            display(nodo);
        break;
    case 4:
        printf("\nate logo!\n");
        break;
    default:
        printf("opcao invalida!\n");
        aux();
    }
}
int main()
{
    tp_nodo *nodo;

    nodo=(tp_nodo*) malloc(sizeof(tp_nodo));
    nodo->prox=NULL;
    nodo->cont=0;
    menu(nodo);
}

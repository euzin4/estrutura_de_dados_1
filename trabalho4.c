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
} tp_nodo;

void push(tp_nodo *inicio,tp_nodo *fim)
{
    system("clear");
    printf("Codigo:");
    scanf("%d",&fim->produto.codigo);
    printf("Nome:");
    getchar();
    fgets(fim->produto.nome,99,stdin);
    printf("Preco:");
    scanf("%f",&fim->produto.preco);
    fim->prox=(tp_nodo*)malloc(sizeof(tp_nodo));
    fim=fim->prox;
    fim->prox=NULL;
    system("clear");
    menu(inicio,fim);
}
void pop(tp_nodo *inicio,tp_nodo *fim)
{
    int a;
    tp_nodo *anterior;

    system("clear");
    if(inicio->prox==NULL)
    {
        printf("Lista vazia!\n\n");
    }
    else
    {
        system("clear");
        printf("Digite o codigo do produto que sera excluido: ");
        scanf("%d",&a);
        system("clear");
        if (inicio->produto.codigo==a)
        {
            inicio=inicio->prox;
            printf("Item excluido!\n\n");
        }
        else
        {
            fim=inicio;
            while(fim->produto.codigo!=a&&fim->prox!=NULL)
            {
                anterior=fim;
                fim=fim->prox;
            }
            if(fim->produto.codigo==a)
            {
                anterior->prox=fim->prox;
                printf("Item excluido!\n\n");
            }
            else
            {
                printf("Esse codigo nao esta na lista.\n\n");
            }
        }
    }
    menu(inicio,fim);
}
void display(tp_nodo *inicio,tp_nodo *fim)
{
    system("clear");
    if(inicio->prox==NULL)
    {
        printf("Lista vazia!\n\n");
    }
    else
    {
        fim=inicio;
        printf("Lista:\n\n");
        while(fim->prox != NULL)
        {
            printf("Codigo: %d\n",fim->produto.codigo);
            printf("Nome: %s",fim->produto.nome);
            printf("Preco: R$%0.2f\n\n",fim->produto.preco);
            fim=fim->prox;
        }
    }
    menu(inicio,fim);
}
void aux(tp_nodo *inicio,tp_nodo *fim)
{
    menu(inicio,fim);
}
void menu(tp_nodo *inicio,tp_nodo *fim)
{
    int opc;

    printf("1-inserir produto na lista\n2-excluir produto da lista\n3-listar dados dos produtos da lista\n4-sair\n");
    scanf("%d",&opc);
    switch(opc)
    {
    case 1:
        push(inicio,fim);
        break;
    case 2:
        pop(inicio,fim);
        break;
    case 3:
        display(inicio,fim);
        break;
    case 4:
        printf("\nAte logo!");
        break;
    default:
        system("clear");
        printf("Opcao invalida!\n\n");
        aux(inicio,fim);
    }
}
int main()
{
    tp_nodo *inicio,*fim;

    inicio=(tp_nodo*)malloc(sizeof(tp_nodo));
    fim=inicio;
    menu(inicio,fim);
}

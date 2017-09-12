#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 50
typedef struct _produto{//criação de uma struct tipo produto
int cod;
char nome[TAM];
float preco;
}tp_produto;
typedef struct _pilha{//criação de uma struct tipo pilha
tp_produto *info;
int topo;
}tp_pilha;

void push(tp_pilha *pil){
    system("clear");
    if (pil->topo < 4){
        pil->topo+=1;
        printf("valor: ");
        scanf("%d",&pil->info+pil->topo)->cod]);
        system("clear");
    }else{
        printf("Pilha cheia!\n\n");
    }
    menu(pil);
}
void pop(tp_pilha *pil){
    system("clear");
    if (pil->topo==-1){
        printf("A pilha esta vazia!\n\n");
    }else{
        pil->topo-=1;
    }
    menu(pil);
}
void display(tp_pilha *pil){
    system("clear");
    int i;
    if (pil->topo==-1){
        printf("A pilha esta vazia!\n\n");
    }else{
        printf("Valores:\n");
        for(i=0;i<=pil->topo;i++){
            printf("%d\n",pil->info[i]);
        }
        printf("\n");
    }
    menu(pil);
}
void aux(tp_pilha *pil){
    menu(pil);
}
void menu(tp_pilha *pil){
    int menu;
    printf("MENU\n1-Inserir produto na pilha\n2-Excluir um elemento da pilha\n3-Exibir dados dos elementos da pilha\n4-Sair\n");
    scanf("%d",&menu);
    switch(menu){
    case 1:
        push(pil);
        break;
    case 2:
        pop(pil);
        break;
    case 3:
        display(pil);
        break;
    case 4:
        printf("Ate logo!\n");
        break;
    default:
        system("clear");
        printf("Escolha uma opcao valida\n");
        aux(pil);
        break;
    }
}
int main(){
    int qnt;
    tp_pilha *pil;

    printf("quantos produtos deseja inserir na pilha?\n");
    scanf("%d",&qnt);
    pil=(tp_pilha*)malloc(sizeof(tp_pilha));
    pil->info=(tp_produto*)malloc(qnt*sizeof(tp_produto));
    pil->topo= -1;
    menu(pil);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct _pilha{
    int info[MAX];
    int topo;
}tp_pilha;

void push(tp_pilha *pil){
    if (pil->topo < 5){
        pil->topo+=1;
    }else{
        printf("pilha cheia\n");
        getchar();                  //parei aqui
    }
    menu(pil);
}

void menu(tp_pilha *pil){
    int menu;
    printf("MENU\n1-inserir dados\n2-excluir dados\n3-exibir dados da pilha\n4-sair\n");
    scanf("%d",&menu);
    switch(menu){
    case 1:
       push(pil);
    break;
    case 2:
        //pop();
    break;
    case 3:
        //display();
    break;
    case 4:
    break;
    default:
        printf("escolha uma opcao valida");
    }
}

int main()
{
    tp_pilha *pil;

    pil =(tp_pilha *) malloc(sizeof(tp_pilha));
    pil->topo=-1;
    menu(pil);
}

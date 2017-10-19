#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct _pilha{
    int info[MAX];
    int topo;
}tp_pilha;

void push(tp_pilha *pil){
    system("clear");
    if (pil->topo < 4){
        pil->topo+=1;
        printf("valor: ");
        scanf("%d",&pil->info[pil->topo]);
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
    printf("MENU\n1-Inserir dados\n2-Excluir dados\n3-Exibir dados da pilha\n4-Sair\n");
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

int main()
{
    tp_pilha *pil;

    pil=(tp_pilha *)malloc(MAX*sizeof(tp_pilha));
    pil->topo=-1;
    menu(pil);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 50
typedef struct _produto{//criação de uma struct tipo produto
int cod;
char nome[TAM];
float preco;
}tp_produto;
typedef struct _pilha{//criação de uma struct tipo pilha
tp_produto *info;
int topo;
int qnt;
}tp_pilha;

void push(tp_pilha *pil){
    system("cls");
    if (pil->topo < pil->qnt-1){
        pil->topo+=1;
        printf("codigo: ");
        scanf("%d",&pil->info[pil->topo].cod);
        getchar();
        printf("nome: ");
        fgets(pil->info[pil->topo].nome, 49, stdin);
        printf("preco:");
        scanf("%f",&pil->info[pil->topo].preco);
        system("cls");
    }else{
        printf("Pilha cheia!\n\n");
    }
    menu(pil);
}
void pop(tp_pilha *pil){
    system("cls");
    if (pil->topo==-1){
        printf("A pilha esta vazia!\n\n");
    }else{
        pil->topo-=1;
    }
    menu(pil);
}
void display(tp_pilha *pil){
    system("cls");
    int i;
    if (pil->topo==-1){
        printf("A pilha esta vazia!\n\n");
    }else{
        for(i=0;i<=pil->topo;i++){
            printf("item %d\n",i);
            printf("codigo: %d\n",pil->info[i].cod);
            printf("nome: %s",pil->info[i].nome);
            printf("preco: %0.2f\n",pil->info[i].preco);
            printf("\n");
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
        system("cls");
        printf("Escolha uma opcao valida\n");
        aux(pil);
        break;
    }
}
int main(){
    tp_pilha *pil;
    int qntd;

    printf("quantos produtos deseja inserir na pilha?\n");
    scanf("%d",&qntd);
    system("cls");
    pil=(tp_pilha*)malloc(sizeof(tp_pilha));
    pil->info=(tp_produto*)malloc(pil->qnt*sizeof(tp_produto));
    pil->qnt=qntd;
    pil->topo= -1;
    menu(pil);
    return 0;
}

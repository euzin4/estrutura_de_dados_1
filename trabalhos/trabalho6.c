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
    int min,auxcod;
    char nome[20],auxnome[20];
    float preco,auxpreco;

    if(novo->nItens > 1){
        for (i=0; i < novo->nItens-1;i++){
            novo->last=novo->first;
            for(h=0;h<i;h++){   //volta para o nodo que esta sendo testado
                novo->last=novo->last->next;
            }
            min=novo->last->info.codigo;    //copia os dados do nodo atual
            strcpy(nome,novo->last->info.nome);
            preco=novo->last->info.preco;
            for (j=(i+1);j < novo->nItens;j++){
                novo->last=novo->first;
                for(h1=0;h1<j;h1++){    //passa pelos nodos para achar o menor valor
                    novo->last = novo->last->next;
                }
                auxcod=novo->last->info.codigo;
                if(auxcod < min){   //copia os dados do nodo com codigo menor
                    min=auxcod;
                    strcpy(auxnome,novo->last->info.nome);
                    auxpreco=novo->last->info.preco;
                    h1min=h1;
                }
            }
            novo->last=novo->first;
            for(h=0;h<i;h++){   //volta para o nodo que esta sendo testado
                novo->last=novo->last->next;
            }
            atual=novo->last->info.codigo;
            if (atual != min){  //passa os valores do menor codigo para o nodo atual
                novo->last->info.codigo=min;
                strcpy(novo->last->info.nome,auxnome);
                novo->last->info.preco=auxpreco;
                novo->last=novo->first;
                for(h=0;h<h1min;h++){
                    novo->last=novo->last->next;
                }   //passa os dados do nodo atual para onde estava o menor codigo
                novo->last->info.codigo=atual;
                strcpy(novo->last->info.nome,nome);
                novo->last->info.preco=preco;
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
    int codigo;
    char nome[20];
    float preco;

    if(novo->nItens > 1){
        for(i=1;i < novo->nItens;i++){
            novo->last=novo->first->next;
            for(j=1;j<i;j++){
                novo->last = novo->last->next;
            }
            while(novo->last->info.codigo < novo->last->prev->info.codigo){
                codigo = novo->last->info.codigo; //codigo
                novo->last->info.codigo = novo->last->prev->info.codigo;
                novo->last->prev->info.codigo = codigo;
                strcpy(nome,novo->last->info.nome);   //nome
                strcpy(novo->last->info.nome,novo->last->prev->info.nome);
                strcpy(novo->last->prev->info.nome,nome);
                preco = novo->last->info.preco; //preco
                novo->last->info.preco = novo->last->prev->info.preco;
                novo->last->prev->info.preco = preco;
                novo->last = novo->last->prev;  //volta um nodo
                if(novo->last == novo->first){
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

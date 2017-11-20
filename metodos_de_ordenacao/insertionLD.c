/* Lista Dinamicamente encadeada, implementando metodos de ordenacao */
/* Metodo da Insercao ( Insertion Sort ) */
/* Codigo por Jose Luis Tadeu Lins Carnevalli */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

struct linkedList {
       long int value;
       struct linkedList *ptr;
};

void initList( struct linkedList **first );
char menu ();
void insertElem( struct linkedList **first, long int elem );
long int leitura();
void showList( struct linkedList *first );
int countList( struct linkedList *first );
struct linkedList * ptrElement( struct linkedList *first, long int pos );
void removeElement( struct linkedList **first, int pos );
void insertionSort( struct linkedList *first );
void insertionSortDecrescente( struct linkedList *first );

int main () {

    struct linkedList *first;

    initList( &first );

    do{
              switch( menu() ) {
                      case '1':
                           insertElem( &first, leitura() );
                           break;
                      case '2':
                           showList( first );
                           getch();
                           break;
                      case '3':{
                           int pos;
                           printf("\n\nInforme a posicao do elemento que deseja remover: ");
                           scanf("%d",&pos);
                           removeElement( &first, pos );
                      }
                           break;
                      case '4':
                           insertionSort( first );
                           break;
                      case '5':
                           insertionSortDecrescente( first );
                           break;
                      case '6':
                           printf("\n\nA lista possui %ld elementos.", countList( first ) );
                           getch();
                           break;
                      case '7':
                           exit(0);
                      default:
                           printf("\n\nOpcao Invalida. Pressione qualquer tecla para retornar ao MENU...");
                           getch();
              }
    }while( 1 );
    return 0;
}

void initList( struct linkedList **first ) {

     *first = NULL;
}

char menu () {

     system("CLS");
     printf("GERENCIADOR DE LISTA DINAMICAMENTE ENCADEADA\n\n");
     printf("( 1 ) - Inserir Elemento\n");
     printf("( 2 ) - Mostrar Lista\n");
     printf("( 3 ) - Excluir Elemento\n");
     printf("( 4 ) - Ordenar em Ordem Crescente ( Insertion Sort )\n");
     printf("( 5 ) - Ordenar em Ordem Decrescente ( Insertion Sort )\n");
     printf("( 6 ) - Contar Elementos\n");
     printf("( 7 ) - Sair\n\n\t");

     return getche();
}

void insertElem( struct linkedList **first, long int elem ){

     struct linkedList *novo = ( struct linkedList * ) malloc( sizeof( struct linkedList ) );

     novo->value = elem;
     novo->ptr = NULL;

     struct linkedList *aux = *first;

     if( *first == NULL ) {
         *first = novo;
     }else{
           struct linkedList *aux = *first;
           while( aux->ptr != NULL ) {
              aux = aux->ptr;
           }
           aux->ptr = novo;
     }
}

long int leitura() {

     long int num;
     system("CLS");
     printf("Informe o numero que deseja inserir: ");
     scanf("%ld",&num);
     return num;
}

void showList( struct linkedList *first ) {

     system("CLS");
     long int count = 0;
     while( first != NULL ) {
            printf("[%ld]\t%ld\n", count, first->value );
            first = first->ptr;
            count++;
     }
}

int countList( struct linkedList *first ) {

    long int tam = 0;

    while( first != NULL ) {
           first = first->ptr;
           tam++;
    }
    return tam;
}

struct linkedList* ptrElement( struct linkedList *first, long int pos ) {

       if( pos > countList( first ) - 1 || pos < 0 ) {
           printf("\n\nErro. Posicao inexistente.\n\n\a");
           getch();
           return NULL;
       }
       long int cont = 0;
       while( cont < pos  ) {
              first = first->ptr;
              cont++;
       }
       return first;
}

void removeElement( struct linkedList **first, int pos ) {

       if( pos > countList( *first ) - 1 || pos < 0 ) {
           printf("\n\nErro. Posicao inexistente.\n\n\a");
           getch();
           return;
       }

       struct linkedList *elemento;
       struct linkedList *anterior;

       elemento = ptrElement( *first, pos );

       if( pos ) {
           anterior = ptrElement( *first, pos - 1 );

           anterior->ptr = elemento->ptr;
       }else{
           *first = elemento->ptr;
       }

       free( elemento );
}

void insertionSort( struct linkedList *first ) {

     register long int i, j;

     for( j = 1; j < countList( first ); j++ ) {
          i = j - 1;
          long int troca = ptrElement( first, j )->value;

          while( i >= 0 && ptrElement( first, i )->value > troca ) {
                 ptrElement( first, i + 1 )->value = ptrElement( first, i )->value;
                 i--;
          }
          ptrElement( first, i + 1 )-> value = troca;
     }
}

void insertionSortDecrescente( struct linkedList *first ) {

     register long int i, j;

     for( j = 1; j < countList( first ); j++ ) {
          i = j - 1;
          long int troca = ptrElement( first, j )->value;

          while( i >= 0 && ptrElement( first, i )->value < troca ) {
                 ptrElement( first, i + 1 )->value = ptrElement( first, i )->value;
                 i--;
          }
          ptrElement( first, i + 1 )->value = troca;
     }
}

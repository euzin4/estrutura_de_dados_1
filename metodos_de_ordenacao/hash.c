#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/*============================================================================*/
/*                 PROGRAMA PARA INSERIR DADOS NUMA TABELA HASH               */
/*============================================================================*/ 

struct lista_no {
   int    chave; 
   struct lista_no *prox; 
};
typedef struct lista_no LISTA; 

/* ----------------------------- Protótipos ----------------------------------*/

LISTA *criar(void); 
LISTA *insere(LISTA *a, int v, char op);
int hash(int v,int n);
void imprimir(LISTA *a);

/* --------------------------------- MAIN ------------------------------------*/

main(void)
{
  int v, n, x, cont, i =0;
  char op;
  LISTA *p;  
  
/* --------------------------- CRIANDO A TABELA ------------------------------*/

   
       printf("\nEntre com a quantidade de linhas da tabela = ");   
       scanf("%d",&n);  
       LISTA *tab[n];                                  
       for (i = 0; i < n; i++) 
            tab[i] = criar();   
/* ---------------------------------------------------------------------------*/
                       /* ENTRO COM O VALOR DA CHAVE */
  printf("\nDeseja inserir as chaves no inicio ou no final da lista ?(i/f): ");
  scanf("%s",&op); 
                 
  for(cont=0;cont<n;cont++)               
      { printf("\nEntre com o valor da chave = "); 
        scanf("%d",&v);      
        tab[hash(v,n)] = insere(tab[hash(v,n)],v,op);        
      }
/* ---------------------------------------------------------------------------*/
                          /* DESCARREGO A TABELA */
                             
  for(x=0;x<n;x++){
      printf("\n Tab[%d]:%p\n",x,tab[x]);                    
      imprimir(tab[x]); }     
        
getch();
return (0); 
}

/* ---------------------------------------------------------------------------*/
                              /* FUNÇÕES */
                         
LISTA* insere(LISTA * a, int v, char op)
{ 
  LISTA *ant = NULL;   /*  aponta para lista anterior  */
  LISTA *p = a;
              
  while (p != NULL)   /*   faz uma busca na tabela     */
   {
       if (p->chave == v)
          {
            printf("\n registro %d já existe",v);
            break;
          }
       ant = p;
       p = p->prox;       
   }
   
  if (p == NULL)   /* chave não encontrada ---> CRIANDO o NÓ -----------------*/
     {               
        
        p = (LISTA *)malloc(sizeof(LISTA));             
        p->chave = v;
        p->prox = NULL;
                    
        if (ant == NULL)      /* inserção quando a lista esta vazia */
            {a = p;
            return a;}  
        else                 /* quando a lista tem registros, verifica opção de inserção */
            if(op == 'i')    /* se a op = i, insere no início, senão, insere no final    */   
              {a = p;        
               a->prox = ant;            
               return a; } 
            else
              {ant->prox = p;
               return ant;}                  
     }     
}    
/* -------------------------------função hash---------------------------------*/

int hash(int v, int n)
{
  return (v%n);
}
/* --------------------------função imprimir recursiva -----------------------*/

void imprimir(LISTA *a)
{      LISTA *p = a;
       if (p != NULL){  
           printf("\t chave = %d",p->chave);               
           imprimir(p=p->prox); }    
}
/* -------------------------------função criar--------------------------------*/
LISTA *criar()
  { return NULL; 
  }

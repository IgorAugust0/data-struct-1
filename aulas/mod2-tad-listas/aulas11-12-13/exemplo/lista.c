#include<stdlib.h>
#include<stdio.h>
#include "lista.h"

struct no {
    elem info;
    struct no *prox;
};

struct lista {
   No *inicio, *fim;
};

Lista* cria() {
    Lista *li;

    li = (Lista*) malloc(sizeof(Lista));
    li->inicio=NULL;
    li->fim=NULL;

    return li;
}

void inserir(Lista *L, elem *x, int *erro) {
     No *p;
     
     p=(No*) malloc(sizeof(No));
     if (p==NULL) {
        *erro=1;
        return;
     }
     else *erro=0;
     p->info=*x;
     p->prox=NULL;
     if (L->inicio==NULL)
        L->inicio=p;
     else L->fim->prox=p;
     L->fim=p;
}

void finaliza(Lista *L) {
     No *p;
     p=L->inicio;
     while (p!=NULL) {
           L->inicio=L->inicio->prox;
           free(p);
           p=L->inicio;
     }
     L->fim=NULL;
}

int tamanho(Lista *L) {
    No *p;
    int contador=0;
    p=L->inicio;
    while (p!=NULL) {
          contador++;
          p=p->prox;
    }
    return(contador);
}

int esta_na_lista(Lista *L, elem *x) {
    No *p;
     
    p=L->inicio;
    while ((p!=NULL) && (p->info!=*x)) {
          p=p->prox;
    }
    
    if (p!=NULL) return(1);
    else return(0);
}

void imprimir(Lista *L) {
     No *p;
     
     p=L->inicio;
     while (p!=NULL) {
           printf("%c ",p->info);
           p=p->prox;
     }
     printf("\n\n");
     return;
}

void eliminar(Lista *L, elem *x, int *erro) {
     No *p, *anterior;
     int teste=0;
     
     p=L->inicio;
     while ((p!=NULL) && (!teste)) {
           if (p->info!=*x) {
              anterior=p;
              p=p->prox;
           }
           else {
              if (p==L->inicio) {
                 L->inicio=L->inicio->prox;
                 if (L->inicio==NULL) //para o caso de só haver 1 bloco na lista
                    L->fim=NULL;
              }
              else if (p==L->fim) {
                   L->fim=anterior;
                   L->fim->prox=NULL;
              }
              else anterior->prox=p->prox;
              free(p);
              teste=1;
           }
     }
     
     *erro=!teste;
     return;
}

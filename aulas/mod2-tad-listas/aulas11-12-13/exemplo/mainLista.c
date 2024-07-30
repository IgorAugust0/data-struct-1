#include<stdlib.h>
#include<stdio.h>
#include "lista.h"

int main(void) {
    Lista *L;
    elem x;
    int erro;
    
    L = cria();
    
    x='b';
    inserir(L,&x,&erro);
    if (erro) printf("(erro) ");
    x='c';
    inserir(L,&x,&erro);
    if (erro) printf("(erro) ");
    x='e';    
    inserir(L,&x,&erro);
    if (erro) printf("(erro) ");
    x='d';    
    inserir(L,&x,&erro);
    if (erro) printf("(erro) ");
    x='a';    
    inserir(L,&x,&erro);
    if (erro) printf("(erro) ");
    x='f';    
    inserir(L,&x,&erro);
    if (erro) printf("(erro) ");
   
//    printf("A lista tem %d elementos\n",tamanho(&L));    
    printf("A lista tem %d elementos\n",tamanho(L));
           
//    if (esta_na_lista(&L,'b')) printf("O elemento b está na lista\n");
    x='b';
    if (esta_na_lista(L,&x)) printf("O elemento b estah na lista\n");
    else printf("O elemento b nao estah na lista\n");
    
//    eliminar(&L,'b');
    x='b';
    eliminar(L,&x,&erro);
    if (erro) printf("(erro) ");

//    if (esta_na_lista(&L,'b')) printf("O elemento b está na lista\n");        
    x='b';
    if (esta_na_lista(L,&x)) printf("O elemento b estah na lista\n");
       else printf("O elemento b nao estah na lista\n");
    
    printf("\nOs elementos da lista sao: ");
    imprimir(L);
    
    finaliza(L);

    free(L);
    
    return 0;
}

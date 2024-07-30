/* 
A Conjectura de Collatz, também conhecida como Problema 3n + 1, estabelece uma
sequência de números naturais, que a partir de um número inicial n, obedecendo aos
seguintes critérios:

1. se o número for par, seu sucessor na sequência será sua metade, ou seja, n/2;
2. se o número for ímpar, seu sucessor na sequência será uma unidade superior ao seu
triplo, ou seja, 3n + 1;
3. o procedimento é sempre interrompido no número 1.

Por exemplo, se o primeiro número da sequência for n = 6, então obteremos os seguintes valores:
6,3,10,5,16,8,4,2,1

*/

#include <stdio.h>

int collatz(int numero) {
    printf("%d\n", numero);
    // caso base
    if (numero == 1) return 0;
    // números pares
    else if ((numero % 2) == 0)
        return 1 + collatz(numero / 2);
    // número impares
    else
        return 1 + collatz(3 * numero + 1);
}

int main() {
    //variável do número da entrada do usuário
    int numEntrada;

    // leitura da entrada 
    scanf("%d", &numEntrada);

    if (numEntrada <= 0){ // verifica caso se insira um número inválido
        printf("0"); // entrada padrão definida como 0
        return 1;
    } else { // caso não seja um número inválido, prossegue para função
        collatz(numEntrada); //chamada da função com a entrada inserida
    }
    return 0;
}
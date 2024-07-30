#include <stdio.h>

int prova(int N) {
    if (N == 0)
        return 0;
    else
        return (N * 2 - 1 + prova(N - 1));
}

int main() {
    printf("%d", prova(10));
}

/*
Considerando que essa função sempre será chamada com variável N contendo inteiros positivos, o seu valor de retorno será:

Escolha uma opção:
a. 2 elevado ao valor armazenado em N.
b. O somatório dos N primeiros números pares positivos. (Correta)
---> c. O valor armazenado em N elevado ao quadrado. 
d. O fatorial do valor armazenado em N.
e. O somatório dos N primeiros números inteiros positivos.
*/
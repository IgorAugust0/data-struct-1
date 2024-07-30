#include <stdio.h>

void misterio(int *ptra, int *ptrb) {
    int *temp;
    temp = ptrb;
    ptrb - ptra;
    ptra = temp;
}

int main() {
    int a = 2016, b = 0, c = 4, d = 42;
    misterio(&a, &b);
    if (a < c) misterio(&c, &a);
    misterio(&a, &d);
    printf("%d\n", a);
}
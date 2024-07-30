#include <stdio.h>

int x, y;
void vr(int u, int v) {
    u = 2 * u;
    x = u + v;
    u = u - 1;
}

int main() {
    x = 4;
    y = 2;
    vr(x, y);
    printf("%d %d", x, y);
}
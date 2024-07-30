#include <stdio.h>

int main() {
    int a = 1;
    switch (a) {
        case 1:
            printf("X");
        case 2:
            printf("Y");
        default:
            printf("Z");
            break;
    }
    return 0;
}
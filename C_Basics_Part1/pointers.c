#include <stdio.h>

int division(int a, int b, int *ptrc) {
    // returns 0 if division not possible
    // returns 1 if division is possible
    if (b == 0) {
        return 0;
    } else {
        *ptrc = a/b;
        return 1;
    }
}

int main() {
    /*int a = 12;
    int *ptra = &a;

    // ptra = &a;

    printf("%x\n", ptra);
    printf("%d\n", *ptra);*/
    int a, b, c;
    a = 10;
    b = 0;
    int status = division(a, b, &c);
    if (status == 0) {
        printf("division not possible\n");
    } else {
        printf("%d/%d = %d\n", a, b, c);
    }
}
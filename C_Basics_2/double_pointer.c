#include <stdio.h>

int main() {
    int x = 10;
    int *ptr = &x;
    int **pptr;
    pptr = &ptr;
    printf("Value of x: %d\n", x);
    printf("Value of x through ptr: %d\n", *ptr);
    printf("Address of x: %x or %x\n", &x, ptr);
    printf("Address of ptr itself: %x or %x\n", &ptr, pptr);
    printf("Address of x through pptr: %x\n", *pptr);
    printf("Value of x thorough pptr: %d", **pptr);
}
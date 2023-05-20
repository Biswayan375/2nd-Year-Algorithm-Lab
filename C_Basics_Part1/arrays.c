#include <stdio.h>
#include <stdlib.h>

void print_array(int *a, int n) {
    // a[i] -> *(a+i)
    for (int i = 0; i < n; i++)
        // printf("%d\n", *(a+i));
        printf("%d\n", a[i]);
}

int main() {
    /*int a = 10;
    int *ptr = &a;

    short int s = 2;
    short int *sptr = &s;

    printf("%ld\n", sptr);
    sptr = sptr+1;
    printf("%ld\n", sptr);*/
    int *arr;
    int n = 5;
    arr = (int *)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        int num;
        printf("Enter the element:\n");
        scanf("%d", &num);
        *(arr+i) = num;
    }

    printf("The elements are: \n");
    print_array(&arr[0], n);
    free(arr);
}
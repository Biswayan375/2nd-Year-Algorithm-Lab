#include <stdio.h>
#include <stdlib.h>

void console_array(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, *(arr+i));
    }
}

void console_matrix(int **mat, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", *(*(mat+i)+j));       // mat[i][j]
        }
        printf("\n");
    }
}

int main() {
    /*int *arr;
    int n = 5, i;
    arr = (int *)malloc(n*sizeof(int));

    printf("Enter the elements: \n");
    for (i = 0; i < n; i++)
        scanf("%d", (arr+i));
    
    console_array(arr, n);*/
    int **mat;
    int row = 3, col = 3, i, j;
    mat = (int**)malloc(row*sizeof(int*));
    for (i = 0; i < row; i++)
        mat[i] = (int *)malloc(col*sizeof(int));
    printf("Enter the elements: \n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("Enter value for row: %d, col: %d -> ", i, j);
            scanf("%d", (*(mat+i))+j);
        }
    }
    console_matrix(mat, row, col);
}
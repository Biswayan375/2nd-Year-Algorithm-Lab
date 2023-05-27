#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    int std;
};
typedef struct Student Student;

void console_student_details(Student *st, int n) {
    int i;
    printf("Details of students are: \n");
    for (i = 0; i < n; i++) {
        printf("Student%d: Roll:%d, Std:%d\n", i, st[i].roll, st[i].std);
    }
}

int main() {
    // Student x;
    // x.roll = 1;
    // x.std = 4;
    // Student *sptr = &x;
    // printf("Address of x: %x\n", sptr);
    // printf("Accessing through x: Roll=%d, Std=%d\n", x.roll, x.std);
    // printf("Accessing through sptr: Roll=%d, Std=%d\n", sptr->roll, sptr->std);
    // printf("Accessing through sptr: Roll=%d, Std=%d\n", (*sptr).roll, (*sptr).std);
    // Student *sptr = NULL;
    // sptr = (Student *)malloc(sizeof(Student));
    // sptr->roll = 10;
    // sptr->std = 2;
    // printf("Roll: %d, Std: %d\n", sptr->roll, sptr->std);
    Student *arr;
    int n = 3, i;
    arr = (Student*)malloc(n*sizeof(Student));
    printf("Enter details\n");
    for (i = 0; i < n; i++) {
        printf("Enter roll: ");
        scanf("%d", &arr[i].roll);
        printf("Enter std: ");
        scanf("%d", &arr[i].std);
    }

    console_student_details(arr, n);    
}
#include <stdio.h>

struct Employee {
    int age;
    int salary;
};
typedef struct Employee Employee;

int main() {
    /*Employee emp1 = {30, 50000}, emp2 = {32, 45000};
    printf("Details of Employee 1: Age: %d, Salary: %d\n", emp1.age, emp1.salary);
    printf("Details of Employee 2: Age: %d, Salary: %d\n", emp2.age, emp2.salary);

    int b = 10;
    printf("b = %d\n", b);*/
    Employee *empptr;
    Employee emp = {24, 18000};
    empptr = &emp;

    printf("Age: %d, Salary: %d\n", empptr->age, (*empptr).salary);
}
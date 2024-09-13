#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.26:- Write program for exchanging values of two variables using function with call by reference

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int num1 = 10, num2 = 20;
    printf("Before swapping:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n\n", num2);
    swap(&num1, &num2);
    printf("After swapping:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    return 0;
}

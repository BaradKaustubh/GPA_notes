#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.20:- Write a program to interchange given value of two variables using 'call by value' mechanism.
void swap(int, int);
void main()
{
    int n1, n2;
    printf("Enter two numbers to be swapped:- ");
    scanf("%d %d", &n1, &n2);

    printf("\nThe values of n1 and n2 in the main function before calling the swap function are = %d %d.", n1, n2);
    swap(n1, n2);
    printf("\nThe values of n1 and n2 in the main function after calling the swap function are = %d %d.", n1, n2);
}

void swap(int n1, int n2)
{
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
    printf("\nThe values of n1 and n2 in the swap function after swapping are = %d %d", n1, n2);
}

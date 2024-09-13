#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.14:- Write a C program to store 10 number in array and display it.
int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Enter the value for arr[%d]:- ", i);
        scanf("%d", &arr[i]);
    }

    printf("The array elements are:- ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", arr[i]);
    }
}
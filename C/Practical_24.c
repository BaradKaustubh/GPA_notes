#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.24:- Write a program to demonstrate pointer incrementation operation.
int main()
{
    int a = 5, *ptr;
    ptr = &a;
    printf("Before incrementing the address of variable:- %u", ptr);
    ptr++;
    printf("\nAfter incrementing the address of variable:- %u", ptr);
}

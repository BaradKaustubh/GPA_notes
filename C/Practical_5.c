#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.5:- Write a simple C program using increment/decrement operators.

int main()
{
    int num;
    printf("Enter a number:- ");
    scanf("%d", &num);
    num++;
    printf("After Increment:- %d\n", num);
    num--;
    printf("After Decrement:- %d\n", num);
    return 0;
}
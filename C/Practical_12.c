#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.12:- Write a C Program to print sum of first five natural number using do-while loop.

int main()
{
    int sum = 0, i = 1;
    do
    {
        sum = sum + i;
        i++;
    } while (i <= 5);
    printf("Sum of first five naturnal number is %d", sum);
}
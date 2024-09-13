#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.21:- Write a program to find the factorial of given number using the recursion.
int fact(int);
int main()
{
    int x;
    printf("Enter a number to find factorial:- ");
    scanf("%d", &x);
    printf("The Factorial of number %d is %d", x, fact(x));
    return 0;
}
int fact(int x)
{
    if (x == 0)
    {
        return 1;
    }
    return x * fact(x - 1);
}

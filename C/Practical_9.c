#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.9:- Write a progarm to find the smallest number among 3 numbers by using the nested if-else.

int main()
{
    int a, b, c, small;
    printf("Enter Three Number:- ");
    scanf("%d %d %d", &a, &b, &c);
    if (a < b)
    {
        if (b < c)
            small = c;
        else
        {
            if (a < c)
                small = a;
            else
                small = c;
        }
    }
    else
    {
        if (b < c)
            small = b;
        else
            small = a;
    }
    printf("The Smallest Number is %d", small);
}

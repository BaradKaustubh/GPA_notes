#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.7:- Write a program to find wheather given year is leap or not.

int main()
{
    int year;
    printf("Enter a Year:- ");
    scanf("%d", &year);
    if (year % 4 == 0)
    {
        printf("%d is a leap year.", year);
    }
    else
    {
        printf("%d is a not leap year.", year);
    }
    return 0;
}
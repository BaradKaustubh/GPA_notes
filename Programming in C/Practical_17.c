#include <stdio.h>
#include <math.h>
#include <string.h>

// Practical No.17[A] :- Write a program to Reverse a string.
void reverse()
{
    char str[100];
    printf("Enter a string:- ");
    scanf("%s", str);
    strrev(str);
    printf("Reversed String:- %s", str);
}

// Practical No.17[B] :- Write a program to Compare a string.
void compare()
{
    int val;
    char s1[30], s2[30];
    printf("Enter String 1:- ");
    gets(s1);
    printf("Enter String 1:- ");
    gets(s2);
    val = strcmp(s1, s2);
    if (val == 0)
    {
        printf("Same.");
    }
    else
        printf("Not Same.");
}
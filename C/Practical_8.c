#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.8 :- Write a program to display 1-red, 2-green, 3-white and other-yellow.

int main()
{
    int choice;
    printf("Enter a number:- ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("RED.");
    }
    else if (choice == 2)
    {
        printf("GREEN.");
    }
    else if (choice == 1)
    {
        printf("WHITE.");
    }
    else
    {
        printf("YELLOW.");
    }
}
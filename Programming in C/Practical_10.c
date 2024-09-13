#include <stdio.h>
#include <math.h>
#include <string.h>

// Practical No.10:- Write a program to find the entered alphabet is a vowel or consonant using switch case.

int main()
{
    char input;
    printf("Enter a letter:- ");
    scanf("%c", &input);
    switch (input)
    {
    case 'e':
    case 'E':
    case 'a':
    case 'A':
    case 'i':
    case 'I':
    case 'O':
    case 'o':
    case 'u':
    case 'U':
        printf("%c is a vowel.", input);
        break;
    default:
        printf("%c is a consonant.", input);
        break;
    }
}

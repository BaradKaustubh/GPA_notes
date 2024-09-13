#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.13:- Write a program to read the age of 10 persons and count the number of persons in agr group of 18 and 25. Use the loop and continue statement.

int main()
{
    int age[10], i = 0, count = 0;
    for (i = 0; i < 10; i++)
    {
        printf("Enter the age of %d person:- ", i + 1);
        scanf("%d", &age[i]);
    }
    for (i = 0; i < 10; i++)
    {
        if (age[i] >= 18 && age[i] <= 25)
            count++;
    }
    printf("\nThe number of people between the age group of 18 and 25 is %d", count);
}

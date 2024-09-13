#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.15[A]:- Write a program to sort the list of 11 numbers of an array in ascending order.
void A()
{
    int temp = 0, j, i, num[30];
    printf("Enter 11 numbers:- ");
    for (i = 0; i < 11; i++)
    {
        scanf("%d", &num[i]);
    }
    for (i = 0; i < 11; i++)
    {
        for (j = i + 1; j < 11; j++)
        {
            if (num[i] > num[j])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    for (i = 0; i < 11; i++)
    {
        printf("%d  ", num[i]);
    }
}

// Practical No.15[B]:- Write a program to sort the list of 11 numbers of an array in descending order.
void main()
{
    int temp = 0, j, i, num[30];
    printf("Enter 11 numbers:- ");
    for (i = 0; i < 11; i++)
    {
        scanf("%d", &num[i]);
    }
    for (i = 0; i < 11; i++)
    {
        for (j = i + 1; j < 11; j++)
        {
            if (num[i] < num[j])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    for (i = 0; i < 11; i++)
    {
        printf("%d  ", num[i]);
    }
}
int main(){
    A();
    B();
    return 0;
}
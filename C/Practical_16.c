#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical NO.16:- Write a C program to display 3*3 matrix using two dimensional array.
int main()
{
    int arr[3][3], i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter the elements for 3*3 matrix at [%d] [%d] position:- ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
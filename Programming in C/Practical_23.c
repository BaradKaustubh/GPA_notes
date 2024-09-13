#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.23:- Develop a user defined function named "ADD()", call this function in main program.
int ADD(int, int);
int main()
{
    int n1, n2, sum;
    printf("Enter Two numbers:- ");
    scanf("%d %d", &n1, &n2);
    sum = ADD(n1, n2);
    printf("The Sum of two numbers is %d", sum);
    return 0;
}
int ADD(int a, int b)
{
    return a + b;
}

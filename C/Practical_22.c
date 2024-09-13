#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.22:- Write the C program to use math library function 1)sqrt, 2)pow
// 1} sqrt()
int main()
{
    double num, sqroot;
    printf("Enter a number:- ");
    scanf("%lf", &num);
    sqroot = sqrt(num);
    printf("The squareroot of %lf is %lf", num, sqroot);
    return 0;
}

// 2} pow
int main()
{
    double base, power;
    printf("Enter the base number:- ");
    scanf("%lf", &base);
    printf("Enter the power to be raised:- ");
    scanf("%lf", &power);
    printf("When Number %lf is raised to power %lf then it is %lf.", base, power, pow(base, power));
}

#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.19:- Write a program to find area of square using the parameterized function.
// csa = calculate square area.
// sl = side length.
// aos = area of square.
float csa(float sl)
{
    return sl * sl;
}
int main()
{
    float sl, aos;
    printf("Enter the side length of square:- ");
    scanf("%f", &sl);
    aos = csa(sl);
    printf("The Area of Square is %f", aos);
}
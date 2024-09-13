# include <stdio.h>
# include <math.h>
# include <string.h>
// Practical No.4:-Write a simple C program to accept two numbers and perform addition,substraction, multiplication and division.

int main()
{
    float first, second, add, sub, mul, div;
    printf("Enter two number:- ");
    scanf("%f %f", &first, &second);
    add = first + second;
    sub = first - second;
    mul = first * second;
    div = first / second;
    printf("The addition is %f", add);
    printf("The subdtraction %f", sub);
    printf("The multiplication is %f", mul);
    printf("The division is %f", div);
    return 0;
}

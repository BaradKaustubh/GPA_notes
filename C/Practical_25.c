#include <stdio.h>
#include <math.h>
#include <string.h>

// Practical No.25:-  Develop a program to print values of variables and their addresses using
// pointers
int main()
{
    // Declare variables
    int integerVar = 42;
    float floatVar = 3.14;
    char charVar = 'A';
    // Declare pointers
    int *ptrInt = &integerVar;
    float *ptrFloat = &floatVar;
    char *ptrChar = &charVar;
    // Print values and addresses
    printf("Integer Variable:\n");
    printf("Value: %d\n", integerVar);
    printf("Address: %u\n\n", (void *)ptrInt);

    printf("Float Variable:\n");
    printf("Value: %f\n", floatVar);
    printf("Address: %u\n\n", (void *)ptrFloat);

    printf("Character Variable:\n");
    printf("Value: %c\n", charVar);
    printf("Address: %u\n\n", (void *)ptrChar);
    return 0;
}
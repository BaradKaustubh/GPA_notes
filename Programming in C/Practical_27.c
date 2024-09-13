#include <stdio.h>
#include <math.h>
#include <string.h>
// Practical No.27:- Write program to understand file related functions in ‘C’ such as fopen(),
// fclose(), fprintf(), fscanf() etc.

int main()
{
    // Declare a FILE pointer
    FILE *filePointer;
    // Open a file for writing
    filePointer = fopen("example.txt", "w");
    // Check if the file is opened successfully
    if (filePointer == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }
    // Write data to the file using fprintf
    fprintf(filePointer, "Hello, File!\n");
    fprintf(filePointer, "This is a sample file created using C.\n");
    // Close the file
    fclose(filePointer);
    // Open the file for reading
    filePointer = fopen("example.txt", "r");
    // Check if the file is opened successfully
    if (filePointer == NULL)
    {
        printf("Error opening the file for reading.\n");
        return 1;
    }
    // Read data from the file using fscanf and print it
    char buffer[100];
    while (fscanf(filePointer, "%s", buffer) != EOF)
    {
        printf("%s ", buffer);
    }
    // Close the file
    fclose(filePointer);
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <string.h>

// Practical No.18:- Develop a program to create the structure "Book" having the data member b_name,b_page,b_author,b_price. Accept and display this data for 5 book.
int main()
{
    struct Book
    {
        char b_name[20];
        int b_page;
        char b_author[50];
        float b_price;
    };

    struct Book book;
    printf("Enter the name of Book:- ");
    scanf("%s", book.b_name);
    printf("Enter the pages of Book:- ");
    scanf("%d", &book.b_page);
    printf("Enter the name of author of Book:- ");
    scanf("%s", book.b_author);
    printf("Enter the price of Book:- ");
    scanf("%f", &book.b_price);

    printf("The Information is as folows:-\n ");
    printf("Name of Book:-%s\n", book.b_name);
    printf("Number of pages of Book:-%d\n", book.b_page);
    printf("Name of Author of Book:-%s\n", book.b_author);
    printf("Price of Book:-%f\n", book.b_price);
}
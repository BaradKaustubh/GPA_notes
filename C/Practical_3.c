# include <stdio.h>
# include <math.h>
# include <string.h>
// PRACTICAL NO.3 :- Write a simple C program to display our name using basic input, output statements, ID code, email address.
int main(){
    char name[50];
    char idcode[50];
    char email[50];
    char address[50];


    printf("Enter Your Name:-  ");
    scanf("%s", name);
    printf("Enter Your IdCode:-  ");
    scanf("%s", idcode);
    printf("Enter Your Email:-  ");
    scanf("%s", email);
    printf("Enter Your Address:-  ");
    scanf("%s", address);
    
    printf("Your Name:-%s\n",name);
    printf("Your Idcode:-%s\n",idcode);
    printf("Your Email:-%s\n",email);
    printf("Your Address:-%s\n",address);
    return 0;
    } 

#include <iostream>
using namespace std;
int main()
{
    int num = 8;
    cout << "Number:- " << num << endl;
    // Print address of num
    cout << "Address of Number:- " << &num << endl;
    // Pointer initialization.
    int *p = &num;
    // Printing the value at address of num.
    cout << *p << endl;
    // Printing the address of num;
    cout << p << endl;
    // Printing the address of pointer p;
    cout << &p << endl;

    double num2 = 8.7;
    // cout<<"Address of Number:- "<<&num2<<endl;
    double *p2 = &num2;
    cout << "Address:- " << p2 << endl;
    cout << "Value:- " << *p2 << endl;
    cout << "Size of integer:- " << sizeof(num2) << endl;
    cout << "Size of pointer:- " << sizeof(p2) << endl;

    // Pointer to int is created, and pointing to some garbage value.
    int *x;
    cout << *x << endl;
    int num3 = 5;
    // pointer increamentation
    int *y = &num3;
    cout << "Before:- " << *y << endl;
    (*y)++;
    cout << "After:- " << *y << endl;

    int *z = y;
    cout << y << " - " << z << endl;
    cout << *y << " - " << *z << endl;
    return 0;
}
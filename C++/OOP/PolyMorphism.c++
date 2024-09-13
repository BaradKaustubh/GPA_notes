#include <iostream>
#include <string.h>
using namespace std;

// ******************************** POLYMORPHISM ***********************************
// Polymorphism:- Multiple Forms.
// ***************************** TYPES OF POLYMORPHISM ******************************
// 1.COMPILE TIME POLYMORPHISM:-  It is also divided into two types:
// a. Function Overloading.
// b. Operator Overloading.
// 2.RUN TIME POLYMORPHISM:- It has one type:
// a.Method Oveloading.

// **************************** Function overloading *************************
// When we want to access the functions with same name, we need to change its input arguments and by changing it's return type is not allowed, it definately throw an error.
class lop1
{
public:
    void func() { cout << "Hello" << endl; }
    void func(char name[]) { cout << "Name" << endl; }
    void func(int age) { cout << "Age" << endl; }
    void func(double weight) { cout << "Weight" << endl; }
};
int function_overloading()
{
    // Here, We are calling the same function but with different argument and compiler will automatically match the function with suitable argument.
    lop1 obj;
    obj.func();
    char name[10] = "Kaustubh.";
    obj.func(name);
    obj.func(23);
    obj.func(45.5);
    return 0;
}

// **************************** OPERATOR OVERLOADING *****************************
// When we are change the function of an opertor in the another function is called as Operator Overloading.
// Here, For instance we are changing the basic function of add operator(+) into minus(-).
class lop2
{
public:
    int a;
    void operator+(lop2 &obj)
    {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "Output is " << value2 - value1 << endl;
    }
    void operator()() { cout << "I am Bracket."; }
    void operator=(int k) { cout << "I am Bracket."; }
    void operator&(int a) { cout << "I am Bracket."; }
};
int operator_overloading()
{
    lop2 obj1, obj2;
    obj1.a = 8;
    obj2.a = 6;
    obj1 + obj2;
    obj1();
    int a = 5;
    int *k = &a;
    cout << *k;
    return 0;
}

// ****************************** RUNTIME OVERLOADING *****************************
// ***************************** Method Overloading ******************************
// Prerequisites :- 1. Same function name, 2. Same Function arguments, 3. Inheritance.
class animal
{
public:
    void speak() { cout << "Speaking."; }
};
class Dog : public animal
{
public:
    void speak() { cout << "Barking."; }
};
class Horse : public animal
{
public:
    void speak() { cout << "Neighing."; }
};
int method_overloading()
{
    Horse obj1;
    obj1.speak();
    return 0;
}

int main(){
    function_overloading();
    operator_overloading();
    method_overloading();
    return 0;
}
#include <iostream>
#include <string.h>
using namespace std;
// *********************************** ENCAPSULATION **********************************
// It is nothing but creating an class with data members and functions and accessing it using objects.
class Student{
    int roll_no = 2;
    char name;
    public:
    int getRollNo(){return this->roll_no;}
};
int main(){
    Student S1;
    cout<<S1.getRollNo()<<endl;
    cout<<"Everything is working properly."<<endl;
return 0;}

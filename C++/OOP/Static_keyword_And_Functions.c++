#include <iostream>
#include <string.h>
using namespace std;

// ******************************* STATIC KEYWORD *************************
class Hero
{
public:
    static int TimeReamaining;
};
int Hero ::TimeReamaining = 10;
int static_keyword()
{
    // Property of Static Keyword:
    // 1. Data doesn't belongs to object, it belong class.
    // 2. We can access static data with crating an onject by using the Class name and Scope Resolution operator(::).
    // 3. Syntax:- Class_name :: Data_member
    cout << "Time Remaining:- " << Hero::TimeReamaining << endl;

    // We can also access static data by creating an object.
    Hero Suresh;
    cout << "Time Remaining:- " << Suresh.TimeReamaining << endl;

    // We can also change it.
    Hero Ramesh;
    cout << "Time Remaining:- " << Ramesh.TimeReamaining << endl;

    Suresh.TimeReamaining = 20;
    cout << "Time Remaining:- " << Ramesh.TimeReamaining << endl;
    cout << "Time Remaining:- " << Suresh.TimeReamaining << endl;
    return 0;
}

// *************************** STATIC FUNCTIONS ************************
class Hero
{
public:
    int health;
    static int TimeReamaining;
    // This will throw error as health is not a static member.
    // static int Random(){return health;}
    // This will not throw error as TimeRemaining is a static member.
    static int Random() { return TimeReamaining; }
};
int Hero ::TimeReamaining = 5;
int static_function()
{
    cout << Hero::Random() << endl;
    return 0;
}

int main()
{
    static_keyword();
    static_function();
}

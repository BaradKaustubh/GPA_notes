#include <iostream>
#include <string.h>
using namespace std;
// *********************** STATIC AND DYNAMIC MEMORY ALLOCATION ***********************
class Hero
{
public:
    int health;
    char level[20] = "GrandMaster";
    void GetHealth()
    {
        cout << "Health is " << health << endl;
    }
    void SetHealth(int h)
    {
        health = h;
    }
    void GetLevel()
    {
        cout << "Level is " << level << endl;
    }
};
int main()
{
    // Static Memory Allocation
    Hero a;
    a.SetHealth(200);
    a.GetHealth();
    a.GetLevel();
    // Dyanamic Memory Allocation
    cout << endl;
    Hero *b = new Hero;
    (*b).SetHealth(200);
    (*b).GetHealth(); // Here b is address of value and to the actual data we need to defreference it using (*) operator.
    b->GetLevel();    // Here use the arrow operator to deference the object.
    return 0;
}
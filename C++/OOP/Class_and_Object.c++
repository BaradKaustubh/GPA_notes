#include <iostream>
#include <string.h>
using namespace std;
// ************************* BASIC CLASS AND OBJECT ***********************
class Hero
{
    // Properties
    int health;
};
class Hero2
{
    // EMPTY CLASS without any Properties
};

void dummy()
{
    Hero ch1;
    cout << "The size is " << sizeof(ch1) << endl; // Here the size of h1 object is nothing but the size of property i.e. 4 as it is of int type.
    Hero2 ch2;
    cout << "The size is " << sizeof(ch2) << endl;
    // *If the class empty i.e. without any property the 1 byte of memory is allocated to it for rectification purpose.
}

class Hero
{
private:
    // Private Properties
    int health;

public:
    // Public Properties
    char level[12] = "GrandMaster";
    // GetHealth used to access the private data of Hero class i.e. health.
    int GetHealth() { cout << "Health is " << health << endl; }
    // SetHealth Help to set value for private data if no value is assign the 1 is returned.
    void SetHealth(int h) { health = h; }
};
int main()
{
    dummy();
    // Creation of object.
    Hero lop;
    // Accessing the class Properties using object and using Dot Operator(.)
    cout << "Level is " << lop.level << endl;
    // Setting the value for private data health.
    lop.SetHealth(1);
    // Display the private data health using display function.
    lop.GetHealth();
    // Checking the size of class hero.
    cout << "The size of Class is " << sizeof(Hero); // size = 16 bytes because we created and  1 int(4 bytes) and array of 10 character(10 bytes) and (1 bytes of null char) and (1 byte of padding.)
    return 0;
}
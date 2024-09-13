#include <iostream>
#include <string.h>
using namespace std;
// **************************************  CONSTRUCTOR ********************************
class Hero1
{
public:
    int health;
    Hero1()
    {
        cout << "Constructor Called." << endl;
    }
};
int constructor()
{
    // Once we create an object constructor is automatically get called.
    // Object is created Statically
    cout << "Statically." << endl;
    Hero1 lop;
    // Object is created Dynamically
    cout << "Dynamically." << endl;
    Hero1 *h = new Hero1;
    return 0;
}

// **************************** PARAMETERIZED CONSTRUCTOR ****************************
class Hero2
{
public:
    int health;
    char level;
    Hero2(int health)
    {
        this->health = health;
        cout << "This->level is " << &health << endl;
    }
    Hero2(int health, char level)
    {
        this->health = health;
        this->level = level;
    }
    int GetHealth() { return health; }
    char GetLevel() { return level; }
};
int parametrized_constructor()
{
    // Statically.
    Hero2 lop(150);
    cout << "Address of lop is " << &lop << endl;
    cout << "Health is " << lop.GetHealth() << endl;
    // Dynamically.
    Hero2 *lopp = new Hero2(85);
    cout << "Health is " << lopp->GetHealth() << endl;
    // Multiple Arguments.
    Hero2 pol(10, 'A');
    cout << "Health is " << pol.GetHealth() << endl;
    cout << "Level is " << pol.GetLevel() << endl;
    return 0;
}

// ***************************** COPY CONSTRUCTOR *************************
class Hero3
{
public:
    int health;
    char level;
    Hero3(int health, char level)
    {
        this->health = health;
        this->level = level;
    }
    // Creating Copy Constructor.
    Hero3(Hero3
              &temp)
    {
        cout << "Copy Constructor is called." << endl;
        this->health = temp.health;
        this->level = temp.level;
    }
    int GetHealth() { cout << health << endl; }
    char GetLevel() { cout << level << endl; }
};
int copy_constructor()
{
    Hero3
        S(500, 'A');
    cout << "Normal Constructor is called." << endl;
    S.GetHealth();
    S.GetLevel();
    // Copy Constructor is automatically get created when give S to R.
    // Once we created copy constructor manually the automatically generated constructor is get destroyed.
    Hero3
        R(S);
    R.GetHealth();
    R.GetLevel();
    return 0;
}

// **************************** SHALLOW AND DEEP COPY ******************************
class Hero4
{
public:
    int health;
    char level;
    char *name;
    // This is Dynamic memory allocation for name,
    void Name()
    {
        cout << "Simple constructor Called." << endl;
        name = new char[100];
    }
    // This is setter for health and level.
    Hero4(int health, char level)
    {
        this->health = health;
        this->level = level;
        Name();
    }
    // This is setter for name.
    void setname(char name[])
    {
        strcpy(this->name, name);
    }
    // This is getter for all data.
    void display()
    {
        cout << "Health: " << this->health << endl;
        cout << "Level: " << this->level << endl;
        cout << "Name: " << this->name << endl;
        cout << endl
             << endl;
    }
    Hero4(Hero4 &temp)
    {
        cout << "Copy Constructor is called." << endl;
        char *ch = new char(strlen(temp.name) + 1);
        strcpy(ch, temp.name);
        this->name = ch;
        this->health = temp.health;
        this->level = temp.level;
    }
};
int shallow_deep_copy()
{
    Hero4 hero1(200, 'C');
    char name1[100] = "Gulabjamun";
    hero1.setname(name1);
    hero1.display();
    // Use Default Copy Constructor
    Hero4 hero2(hero1);
    // Shallow Copy :- We are accessing the same data using two different names with same addresses.
    // We make change in this object i.e. Hero1
    // Changes made in obj1 reflect in obj2.
    hero1.name[0] = 'J';
    hero1.display();
    // Deep Copy :- We are accessing the same data from two diffrent addresses.
    // Here above, we make change in obj1 i.e. Hero1.
    // That change doesn't reflect in Obj2 i.e. Hero2.
    hero2.display();
    // ******************** COPY ASSIGNMENT OPERATOR ********************
    // Here, we explicitly copying the data from hero1 to hero2.
    hero2 = hero1;
    hero1.display();
    hero2.display();
    return 0;
}

int main(){
    constructor();
    parametrized_constructor();
    copy_constructor();
    shallow_deep_copy();
    return 0;
}
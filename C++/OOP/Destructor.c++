#include <iostream>
#include <string.h>
using namespace std;
// ********************************* DESTRUCTOR **********************************
class Hero{
    public:
    ~Hero(){cout<<"Destructor is Called."<<endl;}
};
int main(){
    // Static 
    Hero a;// For Static Destructor is called automatically.

    // Dynamic
    Hero *b = new Hero();
    // In Dynamic Destructor doesn't get called automatically we need call it manually using the |delete| Keyword with object name.
    delete b;
return 0;}
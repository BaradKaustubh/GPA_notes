#include <iostream>
#include <string.h>
using namespace std;
// ********************************* INHERITANCE *********************************
// It nothing but accessing the data member of parent class or super class by child class or sub class.
class Human{
    public:
    float height;
    int weight;
    int age;
    float get_height(){return this->height;}
    int get_weight(){return this->weight;}
    int get_age(){return this->age;}
    void set_height(int height){this->height = height;}
    void set_weight(int weight){this->weight = weight;}
    void set_age(int age){this->age = age;}
};
class Male:public Human{
    public:
    string *color;
    string *hair;
    string get_color(){return *this->color;}
    string get_hair(){return *this->hair;}
    void set_color(string c[]){this->color = c;}
    void set_hair(string h[]){this->hair = h;}
};
class Human{
    public:
    float height;
    int weight;
    int age;
    float get_height(){return this->height;}
    int get_weight(){return this->weight;}
    int get_age(){return this->age;}
    void set_height(int height){this->height = height;}
    void set_weight(int weight){this->weight = weight;}
    void set_age(int age){this->age = age;}
};
class Male:public Human{
    public:
    string *color;
    string *hair;
    string get_color(){return *this->color;}
    string get_hair(){return *this->hair;}
    void set_color(string c[]){this->color = c;}
    void set_hair(string h[]){this->hair = h;}
};
int main(){
    Male Suresh;
    // These are the function from male class or child class which be definately access by this class.
    string c[6] = "Brown";
    Suresh.set_color(c);
    cout<<"Suresh color is "<<Suresh.get_color()<<endl;
    string h[6] = "Curly";
    Suresh.set_hair(h);
    cout<<"Suresh hairs are "<<Suresh.get_hair()<<endl;
    // These function are from Human class or Parent class which can be accessed by Male or Child class.
    Suresh.set_age(85);
    Suresh.set_weight(50);
    Suresh.set_height(5.5);
    cout<<"Suresh age is "<<Suresh.get_age()<<" Years."<<endl;
    cout<<"Suresh weight is "<<Suresh.get_weight()<<" Kg."<<endl;
    cout<<"Suresh height is "<<Suresh.get_height()<<" feet."<<endl;
    return 0;}  


// // ************************* More about Inheritance ************************
// /*    Parent class               Child class                  Result
// 1.    public                     public                       public
// 2.    public                     protected                    protected
// 3.    public                     private                      private
// 4.    protected                  public                       protected
// 5.    protected                  protected                    protected
// 6.    protected                  private                      private
// 7.    private                    public                       not accessiable
// 8.    private                    protected                    not accessiable
// 9.    private                    private                      not accessiable  */
// class Human{
//     public:
//     float height;
// };
// class Male:private Human{
//     public:
//     string *color;
//     string get_color(){return *this->color;}
//     void set_color(string c[]){this->color = c;}
//     float get_height(){return this->height;}
//     void set_height(float height){this->height = height;}
// };
// int main(){
//     Male Kaustubh;
//     Kaustubh.set_height(5.5);
//     cout<<Kaustubh.get_height();
// return 0;}


// ************************** TYPE OF INHERITANCE ************************

// // 1.SINGLE INHERITANCE:- When only one child class access data from parent class is called Single Inheritance.
// class Animal{
//     public:
//     int age = 7;
//     void speak(){cout<<"Speaking."<<endl;}
// };
// class Dog:public Animal{};
// int main(){
//     Dog d1;
//     d1.speak();
//     cout<<d1.age<<endl;
// return 0;}

// // 2.MULTILEVEL INHERITANCE :- When child class accessing data from parent class and that parent class accessing data from grandparent class is known as Multilevel Inheritance.
// class Animal{
//     public:
//     int age = 7;
//     void speak(){cout<<"Speaking."<<endl;}
// };
// class Dog : public Animal{};//Here, Dog is inherting from animal class in public mode.
// class GermanShephard: public Dog{};//Here, GermanShephard is inherting from Dog class.
// int main(){
//     GermanShephard d1;
//     d1.speak();
//     cout<<d1.age<<endl;
// return 0;}

// // 3. Multiple Inheritance :- When one child class is accessing from two parent class is called Multiple Inheritance.
// class Animal{
//     public:
//     void Barking(){cout<<"Barking."<<endl;}};
// class Human{
//     public:
//     void Speaking(){cout<<"Speaking."<<endl;}};
// class Hybrid :public Animal,public Human{};
// int main(){
//     Hybrid h1;
//     h1.Barking();
//     h1.Speaking();
// return 0;}  

// // 4.Hierarchical Inheritance:- When two or more child class are accessing data from one parent class is called as Hierarchical Inheritance.
// class A{
//     public:
//     void func1(){cout<<"Function 1."<<endl;}};
// class B: public A{
//     public:
//     void func2(){cout<<"Function 2."<<endl;}};
// class C : public A{
//     public:
//     void func3(){cout<<"Function 3."<<endl;}};
// class A{
//     public:
//     void func1(){cout<<"Function 1."<<endl;}};
// class B: public A{
//     public:
//     void func2(){cout<<"Function 2."<<endl;}};
// class C : public A{
//     public:
//     void func3(){cout<<"Function 3."<<endl;}};
// int main(){
//     A obj1;
//     obj1.func1();
//     B obj2;
//     obj2.func1();
//     obj2.func2();
//     C obj3;
//     obj3.func1();
//     obj3.func3();
// return 0;}

// // 5.HYBRID INHERITANCE:- When we combine two or more type of inheritance then it will create Hybrid Inheritance.
// class A{
//     public:
//     void func1(){cout<<"Function of Class A."<<endl;}};//Simple class A.
// class B: public A{
//     public:
//     void func2(){cout<<"Function of Class B."<<endl;}};//Inherited from class A.
// class C{
//     public:
//     void func3(){cout<<"Function of Class C."<<endl;}};//Simple class C.
// class D: public B, public C{
//     public:
//     void func4(){cout<<"Function of Class D."<<endl;}};//Multiple inheritance from Class B and class C.
// int main(){
//     A obj1;
//     obj1.func1();
//     B obj2;
//     obj2.func1();
//     obj2.func2();
//     C obj3;
//     obj3.func3();
//     D obj4;
//     obj4.func1();
//     obj4.func2();
//     obj4.func3();
//     obj4.func4();
// return 0;}

// // *************************** AMBIGUITY ABOUT INHERITANCE **************************
// // When two classes having the same function name and they are called then there is confusion regarding the function that which one is get called. To solve this confusion we use the Scope Resolution(::) to define the class from the function id to be called.
// class A{
//     public:
//     void func(){cout<<"I am A."<<endl;}};
// class B{
//     public:
//     void func(){cout<<"I am B."<<endl;}};
// class C{
//     public:
//     void func(){cout<<"I am C."<<endl;}};
// class D: public A, public B, public C{};
// int main(){
//     D Obj;
//     // Obj.func();// If we call this it will throw an error that function is ambigious.
//     Obj.A::func();
//     Obj.B::func();
//     Obj.C::func();
// return 0;}
# include <iostream>
# include <string.h>
using namespace std;
// ************************* BASIC CLASS AND OBJECT ***********************
// class Hero{
//     // Properties
//     int health;
// };
// class Hero2{
//     // EMPTY CLASS without any Properties
// };
// int main(){
//     Hero ch1;
//     cout<<"The size is "<<sizeof(ch1)<<endl;//Here the size of h1 object is nothing but the size of property i.e. 4 as it is of int type.
//     Hero2 ch2;
//     cout<<"The size is "<<sizeof(ch2)<<endl;
//     // *If the class empty i.e. without any property the 1 byte of memory is allocated to it for rectification purpose.
// return 0;}


// class Hero{
//     private:
//     // Private Properties
//     int health;
//     public:
//     // Public Properties
//     char level[12] = "GrandMaster";
//     // GetHealth used to access the private data of Hero class i.e. health.
//     int GetHealth(){cout<<"Health is "<<health<<endl;}
//     // SetHealth Help to set value for private data if no value is assign the 1 is returned.
//     void SetHealth(int h){ health = h;}
// };
// int main(){
//     // Creation of object.
//     Hero lop;
//     // Accessing the class Properties using object and using Dot Operator(.)
//     cout<<"Level is "<<lop.level<<endl;
//     // Setting the value for private data health.
//     lop.SetHealth(1);
//     // Display the private data health using display function.
//     lop.GetHealth();
//     // Checking the size of class hero.
//     cout<<"The size of Class is "<<sizeof(Hero);// size = 16 bytes because we created and  1 int(4 bytes) and array of 10 character(10 bytes) and (1 bytes of null char) and (1 byte of padding.)
// return 0;}


// // *********************** STATIC AND DYNAMIC MEMORY ALLOCATION ***********************
// class Hero{
//     public:
//     int health;
//     char level[20] = "GrandMaster";
//     void GetHealth(){
//         cout<<"Health is "<<health<<endl;}
//     void SetHealth(int h){
//         health = h;}
//     void GetLevel(){
//         cout<<"Level is "<<level<<endl;}
// };
// int main(){
//     // Static Memory Allocation
//     Hero a;
//     a.SetHealth(200);
//     a.GetHealth();
//     a.GetLevel();
//     // Dyanamic Memory Allocation
//     cout<<endl;
//     Hero *b = new Hero;
//     (*b).SetHealth(200);
//     (*b).GetHealth();// Here b is address of value and to the actual data we need to defreference it using (*) operator.
//     b->GetLevel();// Here use the arrow operator to deference the object.
// return 0;}

// // **************************************  CONSTRUCTOR ********************************
// class Hero{
//     public:
//     int health;
//     Hero(){
//     cout<<"Constructor Called."<<endl;}
// };
// int main(){
//     // Once we create an object constructor is automatically get called. 
//     // Object is created Statically
//     cout<<"Statically."<<endl;
//     Hero lop;
//     // Object is created Dynamically
//     cout<<"Dynamically."<<endl;
//     Hero *h = new Hero;
// return 0;}


// // **************************** PARAMETERIZED CONSTRUCTOR ****************************
// class Hero{
//     public:
//     int health;
//     char level;
//     Hero(int health){this-> health = health;cout<<"This->level is "<<&health<<endl;}
//     Hero(int health, char level){
//         this-> health = health;
//         this-> level = level;}
//     int GetHealth(){return health;}
//     char GetLevel(){return level;}
// };
// int main(){
//     // Statically.
//     Hero lop(150);
//     cout<<"Address of lop is "<<&lop<<endl;
//     cout<<"Health is "<<lop.GetHealth()<<endl;
//     // Dynamically.
//     Hero *lopp = new Hero(85);
//     cout<<"Health is "<<lopp->GetHealth()<<endl;
//     // Multiple Arguments.  
//     Hero pol(10, 'A');
//     cout<<"Health is "<<pol.GetHealth()<<endl;
//     cout<<"Level is "<<pol.GetLevel()<<endl;
// return 0;}

// // ***************************** COPY CONSTRUCTOR *************************
// class Hero{
//     public:
//     int health;
//     char level;
//     Hero(int health, char level){
//         this-> health = health;  
//         this-> level = level;}
//     // Creating Copy Constructor.
//     Hero(Hero &temp){
//         cout<<"Copy Constructor is called."<<endl;
//         this-> health = temp.health;  
//         this-> level = temp.level;}
//     int GetHealth(){cout<<health<<endl;}
//     char GetLevel(){cout<<level<<endl;}
// };
// int main(){
//     Hero S(500, 'A');
//     cout<<"Normal Constructor is called."<<endl;
//     S.GetHealth();
//     S.GetLevel();
//     // Copy Constructor is automatically get created when give S to R.
//     // Once we created copy constructor manually the automatically generated constructor is get destroyed.
//     Hero R(S);
//     R.GetHealth();
//     R.GetLevel();
// return 0;}


// // **************************** SHALLOW AND DEEP COPY ******************************
// class Hero{
//     public:
//     int health;
//     char level;
//     char *name;
//     // This is Dynamic memory allocation for name,
//     void Name(){
//         cout<<"Simple constructor Called."<<endl;
//         name = new char[100];}
//     // This is setter for health and level.
//     Hero(int health, char level){
//         this->health = health;  
//         this->level = level;
//         Name();}
//     // This is setter for name.
//     void setname(char name[]){
//         strcpy(this->name,name);}
//     // This is getter for all data.
//     void display(){
//         cout<<"Health: "<<this->health <<endl;
//         cout<<"Level: "<<this->level<<endl;
//         cout<<"Name: "<<this->name<<endl;
//         cout<<endl<<endl;}
//     Hero (Hero& temp){
//         cout<<"Copy Constructor is called."<<endl;
//         char *ch = new char(strlen(temp.name)+1);
//         strcpy(ch , temp.name);
//         this->name = ch;
//         this->health = temp.health;  
//         this->level = temp.level;}
// };
// int main(){
//     Hero hero1(200,'C');
//     char name1[100] = "Gulabjamun";
//     hero1.setname(name1);
//     hero1.display();
//     // Use Default Copy Constructor
//     Hero hero2(hero1);
//     // Shallow Copy :- We are accessing the same data using two different names with same addresses.
//     // We make change in this object i.e. Hero1
//     // Changes made in obj1 reflect in obj2.
//     hero1.name[0] = 'J';
//     hero1.display();
//     // Deep Copy :- We are accessing the same data from two diffrent addresses.
//     // Here above, we make change in obj1 i.e. Hero1.
//     // That change doesn't reflect in Obj2 i.e. Hero2.
//     hero2.display();

//     // ******************** COPY ASSIGNMENT OPERATOR ********************
//     // Here, we explicitly copying the data from hero1 to hero2.
//     hero2 = hero1;
//     hero1.display();
//     hero2.display();
// return 0;}


// ********************************* DESTRUCTOR **********************************
// class Hero{
//     public:
//     ~Hero(){cout<<"Destructor is Called."<<endl;}
// };
// int main(){
//     // Static 
//     Hero a;// For Static Destructor is called automatically.

//     // Dynamic
//     Hero *b = new Hero();
//     // In Dynamic Destructor doesn't get called automatically we need call it manually using the |delete| Keyword with object name.
//     delete b;
// return 0;}


// // ******************************* STATIC KEYWORD *************************
// class Hero{
//     public:
//     static int TimeReamaining; 
// };
// int Hero :: TimeReamaining = 10;
// int main(){
//     // Property of Static Keyword:
//     // 1. Data doesn't belongs to object, it belong class.
//     // 2. We can access static data with crating an onject by using the Class name and Scope Resolution operator(::).
//     // 3. Syntax:- Class_name :: Data_member
//     cout<<"Time Remaining:- "<<Hero::TimeReamaining<<endl;

//     // We can also access static data by creating an object.
//     Hero Suresh;
//     cout<<"Time Remaining:- "<<Suresh.TimeReamaining<<endl;

//     // We can also change it.
//     Hero Ramesh;
//     cout<<"Time Remaining:- "<<Ramesh.TimeReamaining<<endl;

//     Suresh.TimeReamaining = 20;
//     cout<<"Time Remaining:- "<<Ramesh.TimeReamaining<<endl;
//     cout<<"Time Remaining:- "<<Suresh.TimeReamaining<<endl;
// return 0;}


// // *************************** STATIC FUNCTIONS ************************
// class Hero{
//     public:
//     int health;
//     static int TimeReamaining; 
//     // This will throw error as health is not a static member.
//     // static int Random(){return health;}
//     // This will not throw error as TimeRemaining is a static member.
//     static int Random(){return TimeReamaining;}
// };
// int Hero :: TimeReamaining = 5;
// int main(){
//     cout<<Hero::Random()<<endl;
// return 0;}



// // *********************************** ENCAPSULATION **********************************
// // It is nothing but creating an class with data members and functions and accessing it using objects.
// class Student{
//     int roll_no = 2;
//     char name;
//     public:
//     int getRollNo(){return this->roll_no;}
// };
// int main(){
//     Student S1;
//     cout<<S1.getRollNo()<<endl;
//     cout<<"Everything is working properly."<<endl;
// return 0;}




// // ********************************* INHERITANCE *********************************
// // It nothing but accessing the data member of parent class or super class by child class or sub class.
// class Human{
//     public:
//     float height;
//     int weight;
//     int age;
//     float get_height(){return this->height;}
//     int get_weight(){return this->weight;}
//     int get_age(){return this->age;}
//     void set_height(int height){this->height = height;}
//     void set_weight(int weight){this->weight = weight;}
//     void set_age(int age){this->age = age;}
// };
// class Male:public Human{
//     public:
//     string *color;
//     string *hair;
//     string get_color(){return *this->color;}
//     string get_hair(){return *this->hair;}
//     void set_color(string c[]){this->color = c;}
//     void set_hair(string h[]){this->hair = h;}
// };
// class Human{
//     public:
//     float height;
//     int weight;
//     int age;
//     float get_height(){return this->height;}
//     int get_weight(){return this->weight;}
//     int get_age(){return this->age;}
//     void set_height(int height){this->height = height;}
//     void set_weight(int weight){this->weight = weight;}
//     void set_age(int age){this->age = age;}
// };
// class Male:public Human{
//     public:
//     string *color;
//     string *hair;
//     string get_color(){return *this->color;}
//     string get_hair(){return *this->hair;}
//     void set_color(string c[]){this->color = c;}
//     void set_hair(string h[]){this->hair = h;}
// };
// int main(){
//     Male Suresh;
//     // These are the function from male class or child class which be definately access by this class.
//     string c[6] = "Brown";
//     Suresh.set_color(c);
//     cout<<"Suresh color is "<<Suresh.get_color()<<endl;
//     string h[6] = "Curly";
//     Suresh.set_hair(h);
//     cout<<"Suresh hairs are "<<Suresh.get_hair()<<endl;
//     // These function are from Human class or Parent class which can be accessed by Male or Child class.
//     Suresh.set_age(85);
//     Suresh.set_weight(50);
//     Suresh.set_height(5.5);
//     cout<<"Suresh age is "<<Suresh.get_age()<<" Years."<<endl;
//     cout<<"Suresh weight is "<<Suresh.get_weight()<<" Kg."<<endl;
//     cout<<"Suresh height is "<<Suresh.get_height()<<" feet."<<endl;
//     return 0;}  


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


// ******************************** POLYMORPHISM ***********************************
// Polymorphism:- Multiple Forms.
// ***************************** TYPES OF POLYMORPHISM ******************************
// 1.COMPILE TIME POLYMORPHISM:-  It is also divided into two types:
// a. Function Overloading.
// b. Operator Overloading.
// 2.RUN TIME POLYMORPHISM:- It has one type:
// a.Method Oveloading.

// // **************************** Function overloading *************************
// // When we want to access the functions with same name, we need to change its input arguments and by changing it's return type is not allowed, it definately throw an error.
// class lop{
//     public:
//     void func(){cout<<"Hello"<<endl;}
//     void func(char name[]){cout<<"Name"<<endl;}
//     void func(int age){cout<<"Age"<<endl;}
//     void func(double weight){cout<<"Weight"<<endl;}
// };
// int main(){
//     // Here, We are calling the same function but with different argument and compiler will automatically match the function with suitable argument.
//     lop obj;
//     obj.func();
//     char name[10] = "Kaustubh.";
//     obj.func(name);
//     obj.func(23);
//     obj.func(45.5);
// return 0;}

// // ******************************** OPERATOR OVERLOADING *******************************
// // When we are change the function of an opertor in the another function is called as Operator Overloading.
// // Here, For instance we are changing the basic function of add operator(+) into minus(-).
// class lop{
//     public:
//     int a;
// void operator+(lop &obj){
//     int value1 = this->a;
//     int value2 = obj.a;
//     cout<<"Output is "<<value2 - value1<<endl;}
// void operator() (){cout<<"I am Bracket.";}
// void operator= (int k){cout<<"I am Bracket.";}
// void operator& (int a){cout<<"I am Bracket.";}
// };
// int main(){
//     lop obj1, obj2;
//     obj1.a = 8;
//     obj2.a = 6;
//     obj1 + obj2;
//     obj1();
//     int a = 5;
//     int *k = &a;
//     cout<<*k;
// return 0;}  


// ****************************** RUNTIME OVERLOADING *****************************
// // ***************************** Method Overloading ******************************
// // Prerequisites :- 1. Same function name, 2. Same Function arguments, 3. Inheritance.
// class animal{
//     public:
//     void speak(){cout<<"Speaking.";}};
// class Dog : public animal{
//     public:
//     void speak(){cout<<"Barking.";}};
// class Horse : public animal{
//     public:
//     void speak(){cout<<"Neighing.";}};
// int main(){
//     Horse obj1;
//     obj1.speak();    
// return 0;}
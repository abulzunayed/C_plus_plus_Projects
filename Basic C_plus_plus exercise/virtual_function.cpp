#include<iostream>
using namespace std;

/* NOTES:
1. WHY to use virtual function?
   a. To achieve dynamic polymorphism. Which is the ability to call Derived class function using Base class pointer or reference.

2. HOW to use virtual function?
   a. By declaring function as virtual in Base class and overriding that function in Derived class.
      (Function signature should be same in Base and Dervied class)
   b. Declaring a function as virtual in Base class is enough, Derived class function need not to be declared virtual.
   c. Virtual functions should be accessed using pointer(*) or reference(&) of Base class type to achieve run time polymorphism.

ADITIONAL NOTES:
1. Virtual functions cannot be static and also cannot be a friend function of another class.
2. A class can have virtual destructor but can't have virtual constructor.
3. There are two types of virtual functions in C++.
   a. Virtual Function
   b. Pure Virtual Function
// Virtual function: https://www.youtube.com/watch?v=WdOe1bPf_pg       //
 */

/* 
class Base
{
    public:
    // 1st: without virtual:
             // void eat() { std::cout << "I'm  Base Class."; }
    // 2nd: with virtual:
             virtual void eat() { std::cout << "I'm  Base Class. \n"; }
             void  Eat1() { std::cout << "I'm 2nd_Base class. \n"; } 
              
};

class Derive : public Base
{
    public:
        void eat() { std::cout << "I'm Derive class.  \n"; }             
};

int main()
{   
    Base *b;            // base  class and creating virtual pointing ojbect
// way 1: creat object of derive class
    //Derive dobj;    
    //b= &dobj;            // base  class and virtual pointing ojbect == pointing to the Derive class object

// way 2: creat object of derive class
    new Derive(); 
    b= new Derive();    // base  calss and virtual pointing ojbect == pointing to the Derive class object

// 1st: without virtual:
    //b->eat();           // Now, this is called the function from base class, not derive class although its a derive class object 
// 2nd: with virtual:
    b->eat();           // Now, this is called the function from derive class, not base class although its a pointer of base class 
    b->Eat1();         // additial benifite that can inheritet Base 2nd function as well as  derive class function without deplicate function
    // final way:
    //Base *b = new Derive();

    Base*b;
    Derive oj;
    b=&oj;
    b->eat();   // without duplicate, can access the derive class function using Base class pointer
    b->Eat1();   // without duplicate, can access the derive class function as wel as Base class functions with  
    return 0;
} */

// Pure vitual or abstruct class //

/* SYNTAX: virtual returntype functionname(parameters...) = 0;

NOTES:
0. If some class can have only signature of function but not the body then we use pure virtual functions.
1. Sometimes in Base class we know the function name but not the definition of the function, so we want Derived classes to provide the definition of the function.
2. We can actually give body of pure virtual function.
3. If you have pure virtual function in your class, it means that class is an Abstract class and you can't create an object of that class. (But pointers and Reference can be created)

USE CASE:
1. Used to create abstract classes, which helps in creating interfaces (APIs) */

/* class Animal
{
    public:
    virtual void eat() = 0;  // pure virtual fucntion
};

class Cat: public Animal
{
    public:
    void eat(){ cout<< "Eating Rat\n";}
}; 
class Cow: public Animal
{
    public:
    void eat(){ cout<< "Eating Grass\n";}
};


int main()
{
    Animal *a = new Cat();
    a->eat();

    Animal *b= new Cow();
    b->eat(); 
    return 0;
} */

// 2. We can actually give body of pure virtual function.

class Animal
{
    public:
    virtual void eat() = 0;  // pure virtual fucntion
};

void Animal:: eat()  // when want a body for pure virtual function, this is body of Pure virtual function
{ cout<< "the body of Pure V.function \n";}


class Cat: public Animal
{
    public:
    //void eat(){ cout<< "Eating Rat\n";}  // invalid because already same function exits

    void eat()                     // additaional:this is for body of Pure virtual function
    { Animal::eat();
        cout<< " Here can possivle to give the body of Pure V.function \n"; }
};
class Cow: public Animal
{
    public:
    void eat(){ cout<< "Eating Grass\n";}
};

int main()
{
    Cat c;
    c.eat();
    return 0;
}

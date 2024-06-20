# include<iostream>
using namespace std;

// Functin overriding:Function has same naem, smae parameter, same return type in both base class
// and child/ derive class with different function body(defination.). 
// itis Runtime polymorphysm.   ////

/* class A
{
    public: 
    void display(){ cout<< " its Base class Function"<<endl;}
};
class B: public A         // make it derive or clid class
{
    public: 
    void display(){ cout<< " its child class Function"<<endl;}
};
 int main()
 {
    B ob;
    //ob.display();  // dispaly function has redefined in both classes but call as per mentioned class name (B)
    ob. A::display();  // call function of Base class
    return 0;
 }
 */

// fucntion overloading: two function have same name, same body but parameters are different.

class B       
{
    public: 
    void getData( int a){ cout<< " int value"<<endl;}
    void getData( double a){ cout<< " double value"<<endl;}
};
 int main()
 {
    B ob;
    ob.getData(50);
    ob.getData(22.3456);
    return 0;
 }

/*  In this video we will learn about "Polymorphism in C++" programming language. It's a very important topic on oops.

POINS:
There are two types of Polymorphism
A. Compile Time Polymorphism / Static Binding / Early Binding
  a. Function Overloading---> all same except two different parameters.<----------
  b. Operator Overloading
B. Runtime Polymorphism / Dynamic Binding / Lazy Binding
 a. Function Overriding (Using virtual functions):
 --> all same except different classes with different body/defination becuase functions overide or redeeined in different classes.<----------
 

For more details please watch full video and do let me know if there is any doubts in comment section.
 watch: https://www.youtube.com/watch?v=mv5_l4kuVho&list=TLPQMjAwNTIwMjRMU4frPv6zEQ&index=3
  */
 
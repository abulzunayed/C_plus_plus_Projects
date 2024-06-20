# include<iostream>
using namespace std;

// a.b is used if b is the memeber of a. So, "a" will a object of class.
// a->b is used a shorten form of (*a).b. where (*a) indicate pointer of a object and b is member of object.
class A
{   
    public:
    int b;
    A(){ b=5;
    cout<< " this: "<< this->b<< endl;}
    void print(){ cout<<" print: "<< b<<endl;}

};
int main()
{
    A a= A();
    A *x;
    x= &a;
    cout<< "a.b: "<<a.b<< endl;   
    cout<< "a->b: "<< x->b<<endl;
    cout<< "x : "<< x <<endl;
    cout<< "&a : "<< &a <<endl;
    //out<< "a->b: "<< this->a <<endl; // invalis: it show non-static member. onyl inside class/function works.   
    x->print();
    return 0;
}

#include<iostream>
using namespace std;
// static member variavble: alway give the static/fix last upadate data for all object and classes
// static function can only access to static variable, not normal variable

class Base
{
    public:
    int x;           // initialized with the normal intiger variable
    static int y;    // initialized with the Static intiger variable

    void printX(){ cout<< " Normal function print here: "<< x<<endl;}
    static void printY(){ cout<< " static function print here:"<< y <<endl;}  // static function
};
int Base::y;   // for static variable declaration
int main()
{
    Base b1;
    b1.x=10;
    // 1st way to give static object value
    //b1.y=20;
               // 2nd way to give static object value
    Base ::y=20; 
    //Base ::x=20; // invalid because x is not static

    Base b2;
    b2.x=30;
    b2.y=40;
    cout<<"b1.x: "<< b1.x<< endl;
    cout<<"b2.x: "<< b2.x<< endl;
    cout<<"b1.y: "<< b1.y<< endl; // output both objecta b1 and b2 are same 40 because static always give last update valariable value 
    cout<<"b2.y: "<< b2.y<< endl; // for all variable and classes. 
    b1.printX();
    b2.printY();


    return 0;
}
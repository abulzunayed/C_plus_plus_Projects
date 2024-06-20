#include<iostream>
using namespace std;

 // template function: syntex: template < typename Type_name> return_type function_name( Type_name var1, Type_name var2)


/*  // all variable are same type: 
template <typename T> void addNumber( T x, T  y)
 { cout<< " addition:"<< x+y << endl;}

template <typename T> T substructor( T a, T b)
 { T r= a-b; 
    return r ;}

 int main()
 {
    int x, y; // all variable must be same type but invalid--> int x, float y
    x=20;
    y=4.896592592;  // double but initialize with int
    addNumber( x, y);
    cout<<"sub "<< substructor (x,y);  // but return only int
    return 0;
 } */
 

 /* // different type of varibales:
 template <typename T1, typename T2> void addNumber( T1 x, T2  y)
 { cout<< " addition:"<< x+y << endl;}

template <typename T1, typename T2> T2 substructor( T1 a, T2 b) // important: return type 
 { T2 r= a-b; 
    return r ;}

 int main()
 {
    int x; double y; // Now it is valid--> int x, float y
    x=20;
    y=4.896592592;  // double but initialize with int
    addNumber( x, y);
    cout<<"sub "<< substructor (x,y);  // but return value depond on return type
    return 0;
 } */

 // Template class:
template < typename T > class person 
{   private:
        T a, b;
    public:
    person( T x, T y){ a=x, b=y; }
    T max();
};
template < typename T > T person <T>:: max()
{
    T r;
    r= a>b ? a:b;
    return r;
}
 int main()
 {
    person <int> ob(100, 500);
    cout<< " max: "<< ob.max();
    return 0;
 }
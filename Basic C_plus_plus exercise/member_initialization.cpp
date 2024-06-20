
# include <iostream>
using namespace std;

class circle
{
private:
    double radius;
public:
    circle(double a):radius(a){ };
     double area(){ return radius*radius*3.14159265;}
    friend int mul( int a, circle b);    // 2nd way of friend function
};


class cylinder
{
private:
    double height;
    circle base;

public:
    cylinder(int a, double b):  base(a) ,height(b) { };
    // 2nd way: cylinder(int a, int b){width=a, height=b };
    // 3rd way: cylinder(int a, int b): width(a) { height(b) };
    double volume() {return base.area() * height;}
    friend void printfunction(int a, cylinder b); // 1st way of friend function
    
   
};

void printfunction(int a, cylinder b)  // 1st way of friend function
{ double z = a * b.height;
cout<< " frind function " << z<< endl;
}
int mul(int a, circle b)   // 2nd way of friend function
{ 
    return a* b.radius; 
}

int main () {
  cylinder foo (10,20);

  cout << "foo's volume: " << foo.volume() << '\n';
  printfunction(2, foo);// 1st way of friend function
  circle faa1(5); // 2nd way of friend function
  cout<<" friend function return value "<< mul(3, faa1)<< endl;
  return 0;
}
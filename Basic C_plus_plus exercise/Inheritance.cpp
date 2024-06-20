# include<iostream>
using namespace std;
// inhertance can acces variavle of Base class, only function can be accessable
// derive clase can not access variable of Bass class thorugh constructor
// so we need function in base class, from where can access variable through function of base class

/* class A
{
    public:
    void dispaly_A()
    { cout<< " Display_A(): " << endl;}
};
class B: public A
{
    public:
    void dispaly_B()
    { cout<< " Display_B(): " << endl;}
};
class C: public B
{
    public:
    void dispaly_C()
    { cout<< " Display_C(): " << endl;}
};

int main()
{
     C ob1;
     ob1.dispaly_A();
     ob1.dispaly_B();
     ob1. dispaly_C();
    return 0;
} */

// Constructor work with inheritance//  https://www.youtube.com/watch?v=MmR_qpYthP8
class Menuitem
{
    public:
    string name;
     Menuitem()    // Base class constructor
    {name= "Unknow"; cout<<" Base class constructor"<< endl;}
    Menuitem (string c)
    {name=c; cout<<" Base_Parameter constructor: "<<c<< endl;};             // Base class  Parameteriz constructor
};
class Drink: public Menuitem
{
    public:
    double Ounces;
    using Menuitem:: Menuitem;   // Here, call all constructor of base class//
    Drink () 
    { Ounces=8;
    cout<<" Deriveclass constructor"<< endl;}   // Derive class constructor

    Drink (double a) : Menuitem( " al" )      // Base parameteriz constructor call
    {Ounces=a; cout<<" DErive_Parameter constructor: "<<a<< endl;};             // Derive class  Parameteriz constructor
};
int main()
{   //Drink hor_choco;
    //Drink hor_choco(20); // parametrize constructor
    Drink hor_choco("using all constructor");     // call only base class ojbect

    return 0;

}

/* class Polygon
{
    public:
    int width, height;
    //Polygon( int a, int b): width(a), height(b){};  // invalid because derive clase can not access variable of Bass class
    void set_values (int a, int b)
      { width=a; height=b;}
};
class Rectangle: public Polygon {
  public:
    int area () { return width * height; }
 };

class Triangle: public Polygon {
  public:
    int area () { return width * height / 2; }
  };
int main () {
  // Rectangle rect(4,5);   // invalid because derive clase can not access variable of Bass class though constructor
  // Triangle trgl(4,5);  // so we need function in base class, from where can access variable through function of base class
  Rectangle rect;  
  Triangle trgl;
  rect.set_values (4,5);
  trgl.set_values (4,5);
  cout << rect.area() << '\n';
  cout << trgl.area() << '\n';
  return 0;
} */

// constructor can inhereitet: //
/* class Mother
{
    public:
    Mother(){ cout << "Mother. constructor\n :"<< endl;}  // construct call
    Mother(int c){ cout << "Mother: int parameter\n\n :"<< c<< endl;}
};

class Daughter: public Mother
{
     public:
     Daughter( int a){ cout << "Daughter: int parameter\n\n :"<< a<< endl; }
};
class Son: public Mother
{
     public:
     Son( int b): Mother(b){ cout << "Son: int parameter\n\n :"<< b<< endl; }  // Mother(int a) finction call
};
int main () {
  Daughter kelly(2);
  Son bud(3);
  
  return 0;
} */

//  call vai pointer: single inheritance//
/* class  Memuitem
{
    public:
    string name;
    double calories;
    void print(){ cout<<name<<" ("<< calories<<"cal)"<< endl;}
     
};
class  Drink: public Memuitem
{
    public:
    //string name;
    //double calories;
    double ounces;
    double cal_per_ounce() { return calories/ ounces;}   
};

int main()
{   Memuitem french_fries;
    french_fries. name= " French";
    french_fries.calories=400;
    french_fries.print();

    Drink hot_choco;
    hot_choco.name= "Hot_chocolate",
    hot_choco.calories= 200;
    hot_choco.ounces= 25;
    hot_choco.print();
    cout<< " cal/ ounce: "<< hot_choco.cal_per_ounce()<< endl;

    Memuitem *ptr;   // call via pointer
    ptr=&hot_choco;
    ptr->print();
    return 0;
} */

// Multilevel inheretance
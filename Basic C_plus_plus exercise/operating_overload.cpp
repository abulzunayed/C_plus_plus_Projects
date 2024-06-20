# include <iostream>
using namespace std;

/* 
// 1st example:
class person
{
  private:
   int value;
   public:
   person( ){ value=10;}

   void operator++()
   {
    value=value+5;
   }
   void display();
};

void person::display()
{ cout<< " value: "<< value<< '\n'; }

int main()
{
  person Inc;
  ++Inc;
  Inc.display();
  //cout << " value of Inc "<< Inc<< endl;

  return 0;
} */

/* 
class Complex
{
private:
   int real, imag;
public:
void input()
{
  cout<< " enter your real and image number: ";
  cin>>real;
  cin>> imag;
}
Complex operator+ (Complex obj)
{
  Complex temp;
  temp.real= real+ obj.real;
  temp.imag= imag+ obj.imag;
  return temp;
}
 void display()
 {
  cout<< " real number: "<< real<<'\n';
  cout<< " imag number: "<< imag<<'\n';

 }
};

int main()
{
   Complex com1, com2, res;
   cout<< " enter you 1st number \n";
   com1.input();
   cout<< " enter you t2nd number \n";
   com2.input();
   res= com1+ com2;
   res.display();

  return 0;
} */

// Binary operator overloading

/* class Cvector
{  private:
   int id, age;
   public:
   Cvector(){};
   Cvector(int a, int b): id(a), age(b){};
   Cvector operator+ (Cvector para);
   int display()
   {
    cout<< " res: "<< id<<'\n';
    cout<< " res: "<< age<<'\n';
    int k=this->id; int m= this->age; 
    int c[2]={k,m};
    return c[2];
    };
    void print()
    { cout<< " id: "<< id <<endl;
    cout<< " age: "<< age <<endl;}
    
};
Cvector Cvector:: operator+ (Cvector para)
{
  Cvector temp;
  this->id= id + para.id;
  this->age= age+ para.age;
  return Cvector( id, age);  // with class name we can pass both variable value
}

int main()
{
  Cvector foo(3,1), bar(4,2), res;
  res = foo + bar;
  res.print();
  int v[]={ res.display()};
  cout<< " total result: "<< v[0]<< endl;  
  cout<< " total result: "<< v[1]<< endl; // why does not show the value together.
  return 0;
} */

// uninary operator overloading

/* class Uninary
{
  private:
  int x, y;
  public:
  Uninary(){};
  Uninary(int a, int b): x(a), y(b){};
  void display()
  {
    cout<< " the value: "<< x<< endl;
    cout<< " the value: "<< y<< endl;
  }
  Uninary operator++();
};
Uninary Uninary:: operator++()
{ Uninary temp;
  temp.x=++x;
  temp.y=++y;
  return Uninary(x,y);  // return both variaable
}

int main()
{
  Uninary dar(14, 5);
  ++ dar;
  dar.display();
  return 0;
}
 */

// retionaol opretor overloading
class   Retional

{
private:
  int a, b;
public:
  Retional(){};
  Retional(int x, int y): a(x), b(y) {};
  bool operator<(Retional h);
};
bool Retional:: operator<(Retional h)
{
  if (this->a<h.a){ return true;}
  if( this->a == h.a && b< h.b){ return true;}
  else return false;
}

int main()
{
  Retional var(10,3), dot(3,4);
  if(var<dot) { cout<< " var is big";}
  else {cout<< " dot is big";};
  return 0;
}
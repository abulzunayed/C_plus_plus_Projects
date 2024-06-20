
# include  <iostream>
using namespace std;

// simple class declaration:


class Rectangle
{
 private:
       int width, height;
 public:
/*         // 1s way:
       void setvalue( int, int );
       int area() { return width* height;} */

/*        // 2nd way:
      Rectangle( int a, int b): width(a), height(b){ };  // constructor with argement
      ~Rectangle();
       int area();
 */
      // 3rd way:
      Rectangle(int , int);   
      ~Rectangle();   // destructor
      int area();
};

  //1st way:
// void Rectangle::setvalue (int a, int b) {  width=a; height=b;}

Rectangle:: Rectangle(int a, int b){ width=a, height=b;}
int Rectangle:: area() { return width* height;}
Rectangle:: ~Rectangle(){};   // destructor

int main()
{
/*     // 1s way:
    Rectangle ob1, ob2;
    ob1. setvalue(3,4);
    ob2.setvalue(5,6);
    cout<< "area of ob1: "<< ob1.area()<< endl;
    cout<< "area of ob2: "<< ob2.area()<< endl; */

/*        // 2nd way:
    Rectangle ob1(3,4);
    Rectangle ob2(5,6);
    cout<< "area of ob1: "<< ob1.area()<< endl;
    cout<< "area of ob2: "<< ob2.area()<< endl; */

    // 3rd way:
    Rectangle ob1(3,4), ob2(5,6);
    cout<< "area of ob1: "<< ob1.area()<< endl;
    cout<< "area of ob2: "<< ob2.area()<< endl;
    return 0;
}
# include<iostream>
using namespace std;

// Friend give direct access in private and protected in a Class.
// function in Private, Friend can only access private

/* class class_name
{
    private:
    int d1, d2;
    //void add(int x, int y){ x+y;}   // invalid becausefunction in Private, Friend can only access private
    friend void add( class_name &para1);

    public:
    class_name(){}; // default constructor
    class_name( int a, int b){ d1=a, d2=b;};  // parameter constructor
    void display(){ cout<< "d1: "<< d1<< " d2: "<<d2<<endl;};
    friend void multiply(class_name);
};

void multiply(class_name para)   /// friend function calling
{ 
    int d3;
; cout<< " friend_multiply: "<< d3 <<endl;
}
void add( class_name &para1)
{   para1.d1 +=2; para1.d2 +=3;}  // now Friend function can access private
int main()
{
    class_name ob(24,23);
    ob.display();  // normal function call sytex: object.function();
    multiply(ob);  // Friend function call sytex: function(object); here, object keep in function
    //ob.add();   // invalid because this function declare in private.
    add(ob);       // now Friend function can access private
    ob.display();
    return 0;
} */

// Friend can access  private memeber //
// For friend class, we need to declare in both classes. 

class  cost;  // friend function decoration derive class

class revenue
{
    private:
    int rev;
    friend bool profit( revenue rr, cost cc);// For friend class, we need to declare in both classes. 
    
    public:
    revenue (int r){ rev=r;}
};

class cost
{
    private:
    int cos;
    friend bool profit( revenue rr, cost cc); // For friend class, we need to declare in both classes. 
    public:
    
    cost (int c){ cos=c;};
};
 bool profit( revenue rr, cost cc)  // For friend class, we need to declare in both classes. 
 {
    if (rr.rev > cc.cos) return true;
    else return false;
 }int main()
 {
  revenue reven(500);
  cost total_cost(300);
  if (profit( reven,total_cost)) {cout<< "Profit"<< endl;}
  else cout<< "Profit"<< endl;
  return 0;
 }

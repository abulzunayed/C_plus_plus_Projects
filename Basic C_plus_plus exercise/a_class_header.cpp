# include "a_class_header.h"
# include <iostream>

using namespace std;

sally::sally()    // constructor
{
   cout<< " I am constrructor"<<endl;
}
sally::~sally()
{
    cout<<" i am deconstructor"<<endl;
}
void sally::printcrap()
{
    cout<< "hello"<< endl;
}

void sally::setName(char x)
{name2=x;}
char sally:: getName()
{ return name2;}

void sally:: printshiz()
{ cout<<"i am normal variable "<< endl;}

void sally:: printshiz2() const     // constant object
{ cout<<"i am const variable "<< endl;}



/* sally::sally( int a,  int b): regvar(a), canstvar(b)  {  } // need constructor to use member initializer

void sally:: print2( )
{
    cout<< " regular variable: "<< regvar<< endl;
    cout<< " const variable: "<< canstvar<< endl;
}
 */
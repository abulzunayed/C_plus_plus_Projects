# include <iostream>
# include"a_class_header.h"
# include "a_class_header.cpp"


using namespace std;

int main()
{
    sally  object;
    sally *pointer=&object;
    object.printcrap();
    pointer->printcrap(); 

    sally bo2;
    bo2.setName('a');
    cout<< " 2nd object: "<<bo2.getName()<< endl;
   
    sally ob3;
    ob3.printshiz();
    const sally ob4;   // constant object
    ob4.printshiz2();

    
/*     sally so(4, 4);   // Memeber initializers
    so.print2();
 */
    return 0;
}
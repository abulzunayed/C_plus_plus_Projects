# include <iostream>
using namespace std;
/* 
For Loop vs Whiel Loop:
// For Loop: A "For" Loop is used to repeat a specific block of code a known number of times. 
            Performance-wise, For loops are generally faster than While loops
// While Loop: A "While" Loop is used to repeat a specific block of code an unknown number of times, until a condition is met.
                It comes with a danger: sometimes your while loop will never stop!
   */              

# define PRINT(x) std::cout<<"print value: "<<x<<std::endl;  // my own define function
int main()
{   // For loop
    int i=0;
    PRINT(i);
    bool condition=true;
   for ( ; condition; )     
   {
    cout<< "Hello"<<endl;
    i++;
    if(!(i<1))
    condition=false;
   } 

    //for(int i=0; i<5; i++) { cout<< "hello stop"<<endl;}

    //while loop 
    int j=0;
    while ((j<5))
    {
        cout<< "hello"<<j<<endl;
        j++;
        if (j>3)
        {
            cout<< "Use Break"<<endl;
            //break; // breal the loop
            return 0;  // now return the zero value and break the loop
        }
    }
    
}
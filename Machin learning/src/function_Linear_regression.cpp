#include <iostream>
#include <stdlib.h>
#include <vector>
#include "../include/function_linear_regression.h"     ////  //  step2: main.cpp--> call *.h -->this extra.cpp 

using namespace std;

void display1(vector<double> error1)
{ for( auto &e: error1)
    cout<< "value of Error: "<< e << endl;
}

bool custom_sort(double a, double b) 
{
    double  a1=abs(a-0);
    double  b1=abs(b-0);
    return a1<b1;
}

void Test_data(double b0, double b1)
{
    cout<<"Enter a test x value: ";
    double test;
    cin>>test;
    double pred=b0+b1*test;
    cout<<endl;
    cout<<"The value predicted by the model= "<<pred<<endl;
    
}


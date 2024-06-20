#include<iostream>
using namespace std;

int main()
{
    try{                             // check the exception
        int mum_age=3;
        int son_age=34;
        if(son_age>mum_age){ throw 99;}          // also possible to throw outside the exception value
        else { cout<< " Here is no exception occurs"<<endl;}
    }
    catch( int x)                                   // catch the exception throwing value
    {cout<< " catch the exception number: "<< x <<endl;}

    // 2nd way to do the catch:
    catch( ...)                         // Here dot dot indicates the any kind of thowing exception value istead of int data
    {cout<< " catch any kind of exception throwing value. "<< endl;}

    return 0;
}
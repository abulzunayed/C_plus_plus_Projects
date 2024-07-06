#include <iostream>
#include <vector>
#include "../include/function_linear_regression.h"  //  step1: main--> call header file *.h
#include "../stdc++.h" // header file for all c++ libraries

using namespace std;

void display1(vector<double> error1);

int main()
{
/*Intialization Phase*/
double x[] = {1, 2, 4, 3, 5};
double y[] = {1, 3, 3, 2, 5};
vector<double>error; // for storing the error values
double err;    // for calculating error on each stage
double b0 = 0; // intializing Intercept b0
double b1 = 0; // initializing slop or regression coefficient b1
double alpha = 0.01; // initializing our learning rate

/*Training Phase*/
for (int i = 0; i < 20; i ++) {   // since there are 5 values and we want 4 epochs so run for loop for 20 times
    int idx = i % 5;   //for accessing index after every epoch
    double p = b0 + b1 * x[idx];  //calculating prediction
    err = p - y[idx]; // calculating error
    b0 = b0 - alpha * err; // updating b0
    b1 = b1 - alpha * err * x[idx];// updating b1
    cout<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"error="<<err<<endl;// printing values after every updation
    error.push_back(err);
}

// Display all error value:
//display1(error);


sort(error.begin(),error.end(),custom_sort);// sorting to get the minimum value
cout<<"Final Values are: "<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"error="<<error[0]<<endl;

/*Testing Phase*/
Test_data(b0, b1);



}
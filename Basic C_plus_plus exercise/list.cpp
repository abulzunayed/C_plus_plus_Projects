#include<iostream>
using namespace std;
# define PRINT(x) cout<< " variable value :"<<x<<endl;
# include <list>

/* int main()
{
    int arr[]= {22, 33, 4, 5, 39};
    int sum=0;
    for (int i=0; i<=2; i++)
    sum +=arr[i];
    cout<<"sum :" << sum<<endl; 
    return 0;
} */

/*  int main()
 {   
    //int arr2d[2][5]= {{22, 33, 4, 5, 39},{20, 39, 49, 59, 69}};
    int arr2d[2][5]= {22, 33, 4, 5, 20, 39, 49, 59, 69};
    int arr2[2][5]= {22, 33, 4, 5, 20, 39, 49, 59, 69};
    int sum2d=0;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<< " 2d arra:"<< arr2d[i][j]<<endl;
            sum2d +=arr2d[i][j];
            int multi=arr2d[i][j] + arr2[i][j];
            cout<< " arra sum:"<< sum2d<<endl;
            cout<< " arra mult:"<< multi<<endl;
        }
    }
 } */
    
    // pointer array
/* int main()
{
    int*p;
    for(int i=0; i<2; i++)
    {       p=arr2[i];
            cout<< " arra:"<< arr2[i]<<endl;
            cout<< "pointer arra:"<< *(p+i)<<endl;
    } 
} */

// List: stL: we need to add iteration for List

/* // print out elemenet for array/ vector7/list/map:
for( const auto& e: ob1)
{ cout<< e<<" ";} */

#include<list>

int main()
{  
     list<int> ob1={ 5,6,7,9};
     list<int> ob2={ 3,5,9,8};
    

     // 1st way of list iteration:
      //  list<int>:: iterator it;
      //  it= ob1.begin();    // declare list with iteration with starting point

     // 2nd way list iteration: auto can replace list<int>:: iterator it;
     auto it= ob1.begin();    // declare List iteration with starting point
     for( it; it !=ob1.end(); it++)
     { cout<< *it<<" \t";}
    cout<<endl;

     list<int> ob3= { 5,6,7,9};
    ob3.push_back(2);
    ob3.push_front(100);
   
     for( auto it= ob3.begin(); it !=ob3.end();  it++) // // declare List iteration with starting point inside Loop
     { cout<< *it<<" ";}
    cout<<endl;
// insert():
     for (auto it= ob3.begin(); it != ob3.end(); it++)
     {  if( *it ==9){ ob3.insert(it, 200);} }

     for( auto it3= ob3.begin(); it3 !=ob3.end(); it3++)
     { cout<< *it3<<" ";}
    cout<<endl;
     // pop():
     for (auto it= ob3.begin(); it != ob3.end(); it++)
     {  if( *it ==9){ ob3.pop_front( );} }

    for( auto it3= ob3.begin(); it3 !=ob3.end(); it3++)
     { cout<< *it3<<" ";}
    cout<<endl;

// merger:
    ob1.merge(ob2);
    for( auto it3= ob1.begin(); it3 !=ob1.end(); it3++)
     { cout<< *it3<<" ";}
    cout<<endl;
    
// print out elemenet for array/ vector7/list/map:
for( const auto& e: ob1)
{ cout<< e<<" ";}

return 0;

}
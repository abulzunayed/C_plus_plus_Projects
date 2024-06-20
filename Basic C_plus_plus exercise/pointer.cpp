# include <iostream>
using namespace std;

// document: https://cplusplus.com/doc/tutorial/pointers/
// pointer assigning Rule:
// Rule :First, always pointer must be assigned by reference value using & symble
// -->invalid, bacause point can not assigned by value.

/* int main()
{  int par=10;
   int *p;
   p=&par;        // Rule :First, always pointer must be assigned by reference value using &
   //*p=par;      // -->invalid, bacause point can not assigned by value.
   cout<<par<<endl;
   cout<<&par<<endl;
   cout<<*p<<endl;
   cout<<p<<endl;
    return 0;
} */

// array pointer assigning Rule:
// Rule :First, pointer can assigned by reference value but for array, do not need & symble, 
// because array can always be implicitly converted to the pointer of the proper type. 
//array= pointer_arr;  // --> invalid, because array can not assign pointer.

/* int main()
{   int array[10];
    int *pointer_arr;    // declare pointer for array
    pointer_arr = array;  // Rule :First, pointer assigned by reference value but for array, do not need & symble 
    //array= pointer_arr;  // --> invalid, because array can not assign pointer.
    *pointer_arr=5;
    cout<<"*pointer_arr :"<<*pointer_arr<<endl;
    cout<<"*pointer_arr :"<<array[0]<<endl;
    *(pointer_arr+1)= 6;
    cout<<"*pointer_arr+1:"<<*(pointer_arr+1)<<endl;
    cout<<"*pointer_arr+1 :"<<array[1]<<endl;
    return 0;
} */

/* 
// pointer use:
int main()
{
    // point: Blank memory slot that can indicate any variable address.
   // pointer use: that store the address of another variable.and has no own value,
   // pointer vs reference: pointer can store address of multople variables 
   //                     but reference can store only specific addrees of one variable.
   // Benifir of pointer: we can call or change any other variables or value without assiang new variable using pointer
   //   E.g: dynamic memory allowcation for array, list. // https://www.youtube.com/watch?v=rtgwvkaYt1A
   // after assigning pointer(ptr=&var), then  var==*ptr== value;      &var== ptr==address


   int var=8;
   cout<<"pointer: "<< &var<<endl;  // &---> indicate address
   int *pointer=&var;  // assing and exchange address
   cout<<"pointer: "<< pointer<<endl; // without *--> indicate address
   cout<<"pointer: "<< *pointer<<endl; // *--> indicate value

   int*ptr=nullptr;  // Null pointer.--> address blank but value zero
  // cout<<"null pointer address: "<<*ptr<<endl;  // indicate blank addrees.
   //cout<<"null pointer: "<<ptr<<endl;  // value contains zero.
   int bar=5;
   ptr=&bar;
   cout<<" ba addres  :"<<&bar<<endl;
   cout<<" new addres  value:"<<*ptr<<endl;
   cout<<" new addres :"<<ptr<<endl;
   
    void *ptr1; // pointer with no return type.

} */


// smart pointer:
    // smart pointer: shared_ptr<int>, new int (), Auto prt, unique ptr,
    // smart pointer: works only Heap memeory, not stack memeory.
    // benifits: dynamic memeory use instead of stack and get lacal variable value from external calling function
    // pointer vs smart pointer: when use stack memory for normal variable, we use normal pointer. 
    // smart pointer need for dynamic meemory, e.g get value from lacal variable of internal function 
    //                       instead of global variable from main()

/* 
 #include <memory>  // need for using smart pointer  
 // use " new" memory allocation:
int *getdata()
{
   // int a=5;  // invalide bacuse this variable created internally in this function, can return value to outside of function
   // return &a;
   int *a= new int(5);     // manually Heap memory allocation using "new"
    return a;
}
int main()
{
    int *b= getdata();
    cout<< *b<<endl;
    delete b;   // for "new", we need "delete"
    return 0;
} */

/* 
// shared pointer:
# include <memory>
shared_ptr<int> getdata()
{
    std::shared_ptr<int> a= std::make_shared<int>(5);
    return a;
}
int main()
{
    shared_ptr<int>b= getdata();
    cout<< *b<<endl;
    return 0;
} */

/* // auto pointer:
# include <memory>
auto getdata()
{
    auto a= 5;
    return a;
}
int main()
{
    auto b= getdata();
    cout<< b<<endl;

    return 0;
} 
 */
/* 
// unique pointer:
# include <memory>
# define PRINT(x) std::cout<<"print value: "<<x<<std::endl;  // my own dife function
unique_ptr<int> getdata()
{
    unique_ptr<int> a= make_unique<int>(5);
    return a;
}
int main()
{
    unique_ptr<int>b= getdata();
    PRINT(*b);  // get value
    PRINT(&b);  // get address

    return 0;
} */

/* 
    // 3 type of memory menagementin C++:
    stack: create static variable and for evry functio call
    Heap: dynamic memory allowcaton,
    "new" allowcate memory on Heap and "delete" is deallowcated.

    memory leak: occure when memory is not deloacated, even after it is no longer use.
    To solve this problem , we use smart pointer.

     */

/* 
    // pass by Reference  with pointer
    // pass by value: when function call, it copy the vaue of parameter and pass to function.
    //    do not effect on the variable .
     //Pass by reference : instead of copy, it passes the reference of variable and
     //    directly change the value throught the reference addresss. 
    void passByReference(int *x)
    {
        *x=99;
    }
    void passByValue(int x)
    {
        x=100;
    }
    int main ()
    {
        int a =23;
        int b=24;
        passByReference((&a));   // reference value has pass
        passByValue(b);           // pass by value
        cout<< " pass by reference: "<<a << endl;
        cout<< " pass by value: "<<b << endl;

    } 

 */

/* 
// // calling pointer function declaration: ( or pointer to function)
int addition(int a,  int b) {return (a+b);}
int substruction(int a, int b) { return (a-b);}
int multiplication( int a, int b) { return (a*b);}
int dividation( int a, int b) { return a/b;}
int opertaion( int x, int y, int (*function_call)(int, int))   // pointer function calling
//int opertaion( int x, int y, int (function_call)(int, int))  // normal function calling
{
    int g; 
    g= (*function_call)(x,y);
    return g;
}
int  main()
{
    int m,n, k, L;
    int (*minus) ( int, int)= substruction; // pointer function declaration
    m= opertaion (7,5, addition);  // normal function  calling
    n= opertaion (20, m, minus);   // calling function vai pointer
    k= opertaion (20, m, multiplication);
    int (*divide)(int, int)= dividation;  // pointer function declaration
    L= opertaion ( 20, 2, divide);
    cout<< " function return value: "<< m<< endl;
    cout<< " function return value: "<< n<< endl;
    cout<< " function return value: "<< k<< endl;
    cout<< " function return value: "<< L<< endl;
}
 */

// Pointer to class:
/* 
class Rectangle
{
  int width, height;
  public:
  Rectangle( int a, int b): width(a), height(b){ };
  int area() { return width* height;}
  
};

int main()
{
    Rectangle ob1(3,4);
    Rectangle *foo, *bar, *baz, *bar1;
    foo= &ob1;                                 // pointer to class
    bar= new Rectangle(5,6);                  // smart pointer to class
    baz= new Rectangle[2] { {2,5}, {3, 5}};    //  smart pointer to class

    Rectangle ob2(2,4);   // 2nd object
    bar1 = &ob2;                  // pointer to 2nd object

     cout<< " area: "<< ob1.area()<< endl;   // normal variabble calling
     cout<< " area: "<< foo->area()<< endl;   // pointer variabble calling
     cout<< " area: "<< bar->area()<< endl;   // smart pointer variabble calling
     cout<< " area: "<< baz[0].area()<< endl; // samrt pointer array variabble calling
     cout<< " area: "<< baz[1].area()<< endl; // samrt pointer array variabble calling

     cout<< " area: "<< bar1->area()<< endl;   // pointer variable calling for 2nd object
     delete bar;
     delete baz;
     //delete bar1;   // get warning because this is now smart pointer
     
     cout<< " area: "<< foo->area()<< endl;   // pointer variabble calling for reference
} */


// pointer to pointer
/* int main()
{
    // double pointer
   int data=50;
    int *p;
    p=&data;
    cout<< " value:  "<< *p<<'\n';
    cout<< " value:  "<<  p<<'\n';
    int ** double_pr;
    double_pr=&p;
    cout<< " value:  "<< **double_pr<<'\n';
    cout<< " value:  "<<  double_pr<<'\n';
    **double_pr=200;                        // cnage ing point pointer value
    cout<< " value:  "<< **double_pr<<'\n';
    cout<< " value:  "<<  double_pr<<'\n';

    return 0;
} */

// passing pointer to the function:

/* long get_secend( unsigned long *p) // teaking parameter as pointer--> because *p=sec=value;  p=&sec=address
{
    *p= time(NULL);
     return *p;
}
int main ()
{
    unsigned long sec;
     unsigned long sec1=get_secend(&sec);          // Passing reference to the function
    cout<< " current time: "<<sec<<'\n';
    cout<< " current time: "<<get_secend(&sec)<<'\n';
    cout<< " current time: "<<sec1<<'\n';
    return 0;
} */

// Function which access a pointer/ array:

/* //double get_average( int arr[], int size)   // passing parameter as normal array
double get_average( int *arr, int size)    // passing parameter as pointer
{
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (sum/size);
}
int main()
{
    int balance[5]= {2,4,5,7,9};
    double avg=get_average( balance, 5);
    cout<< " average value: "<<avg<<'\n';
    return 0;
} */

// Return pointer from  function :

/* int *get_random()             // whole function return address of array.
{
    static int r[10];   // declare static array
    srand( (unsigned int )time(NULL) );
    for (int i = 0; i < 10; i++)
    {
        r[i]= rand(); cout<<" in function value "<< r[i]<<endl;
    }
    return r;  // return array but whole function return address of array.
    
}
int main()
{  int *p;
    // 1st way: 
    p = get_random();   // get_random provide reference address of array, so do not need & symble, e.g p=&var or p=array.
    for (int i = 0; i < 10; i++)
    {
        cout<< " *(p+ "<<i<<"):"<< *(p+i)<<endl;
    }
    return 0;
}
 */

// Return value from  function and convert to pointer:

/* int get_random()             // whole function return address of array.
{
    static int r[10];   // declare static array
    srand( (unsigned int )time(NULL) );
    for (int i = 0; i < 10; i++)
    {
        r[i]= rand(); cout<<" in function value "<< r[i]<<endl;
    }
    return r[10];  // return array but whole function return address of array.
    
}
int main()
{  int *p;
    // 2nd way: 
    int f= get_random();
    p=&f;  // get_random provide reference address of array, so do not need & symble, e.g p=&var or p=array.
    for (int i = 0; i < 10; i++)
    {
        cout<< " *(p+ "<<i<<"):"<< *(p+i)<<endl;
    }
    return 0;
}
 */


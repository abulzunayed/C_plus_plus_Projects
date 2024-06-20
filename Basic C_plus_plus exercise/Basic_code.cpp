
# include<iostream>

// Bais Arithmathic and if-else statement.
/* 
// void function call
void display()
{
    std::cout<< " Hello void function caller "<< std:: endl;
}
// return function call
int multiplay(int a, int b)
{   int c= a*b;
    std::cout<< " c "<< c<<std:: endl;
    return c;
}
int main()
{   int a=8;
    int b=20;
   
    bool comparision=a==6;
    if(comparision)
    {
       display(); 
    }
    int d= multiplay(a,b);
    std:: cout<< " mult"<< d<< std:: endl;
    return 0;
} */

// if else 
int main()
{
    int x= 2;
    while (x<7)     // for while loop use break condition to stop the loop
    {
    if (x<=4){ std::cout<< x<< std:: endl; x=x+1;}
  
    else  {x=x+1; std::cout<< "this is else"<< std:: endl;}
    
    }
    
return 0;
}
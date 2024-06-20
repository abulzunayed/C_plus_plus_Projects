#include<iostream>
# include <cstdlib>
# include <ctime>
# include <list>

int main()
{   
// set seed to 10
srand(time(0));
  
for ( int i=0; i<10; i++)
{
  // generate random number
  int random = rand();
  std:: cout << random % 6<<std::endl;

}
  return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int a= 10;
  int* p= &a;
  cout<<p<<endl;
   cout<<*p<<endl;
  cout<<++p<<endl;
  cout<<*p<<endl;
  cout<<p+2<<endl;
}


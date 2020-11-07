#include "std_lib_facilities.h"
#include "my.h"

void print_foo()
{
  cout << foo << endl;
}

void print(int i)
{
  cout << i << endl;
}

void swap_v(int a, int b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void swap_r(int& a, int& b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}

/*void swap_const(const int& a, const int& b)
{
  int temp;
  temp = a;  // This won't work because you can't assign a value to a variable that is const.
  a = b;
  b = temp;
}*/
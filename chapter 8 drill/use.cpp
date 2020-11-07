#include "my.h"
#include <iostream>

int foo;

int main()
{
  int x = 7;
  int y = 9;
  swap_v(x, y); // This compiles but doesn't swap the 2 values.
  std::cout << "Return by value(int):\n";
  print(x);
  print(y);
  std::cout << "Return by reference(int):\n";
  swap_r(x, y); // This compiles and gives us the correct results. Because we return by reference wich means a in the function is an alias for x and b is an alias for y.
  print(x);
  print(y);
  // swap_const(x, y); // This won't work because you can't assign a value to a variable that is const.
  const int cx = 7;
  const int cy = 9;
  std::cout << "Return by value(const):\n";
  swap_v(cx, cy);  // This will compile but won't give us the correct results.
  print(cx);
  print(cy);
  std::cout << "Return by reference(const):\n";
  //swap_r(cx, cy); // This won't work since the parameters we are giving are constants.
  print(cx);
  print(cy);
  double dx = 7.7;
  double dy = 9.9;
  std::cout << "Return by value(double):\n";
  swap_v(dx, dy); // Compiles, but doesn't swap the values. Also cuts off the value after the comma(.) since we are giving doubles as parameters when we should be giving integers.
  print(dx);
  print(dy);
  std::cout << "Return by reference(double):\n";
  //swap_r(dx, dy); // This will not compile since we are giving doubles as parameters when integers(as refernce) are required.
  print(dx);
  print(dy);
  foo = 7;
  print_foo();
  print(99);
}
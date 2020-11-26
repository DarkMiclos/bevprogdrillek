#include "std_lib_facilities.h"

void print_array10(ostream &os, int *a)
{
  for (int i = 0; i < 10; ++i)
  {
    os << a[i] << endl;
  }
}

void print_array(ostream &os, int *a, int n)
{
  for (int i = 0; i < n; ++i)
  {
    os << a[i] << endl;
  }
}

void print_vector(ostream &os, vector<int> v)
{
  for (auto const &i : v)
  {
    os << i << endl;
  }
}


int main()
{
  int *p1 = new int[10]{ 100, 101, 102, 103,
    104, 105, 106, 107, 108, 109 };
  cout << "p1 elemei(using new):\n";
  print_array10(cout, p1);

  int *p2 = new int[11]{ 100, 101, 102, 103, 104,
    105, 106, 107, 108, 109, 110 };
  cout << "p2 elemei(using new):\n";
  print_array(cout, p2, 11);

  int *p3 = new int[20]{ 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
  cout << "p3 elemei(using new):\n";
  print_array(cout, p3, 20);

  vector<int> v1 { 100, 101, 102, 103,
    104, 105, 106, 107, 108, 109 };
  cout << "p1 elemei(using vector):\n";
  print_vector(cout, v1);

  vector<int> v2{ 100, 101, 102, 103, 104,
    105, 106, 107, 108, 109, 110 };
  cout << "p2 elemei(using vector):\n";
  print_vector(cout, v2);

  vector<int> v3{ 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
  cout << "p3 elemei(using vector):\n";
  print_vector(cout, v3);

  delete[] p3;
  delete[] p2;
  delete[] p1;
  return 0;
}
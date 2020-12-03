#include "std_lib_facilities.h"

void print_array(ostream &os, int *a, int n)
{
  for (int i = 0; i < n; ++i)
  {
    os << a[i] << endl;
  }
}

int main()
{
  int *p1 = new int(7);
  cout << "p1 memory adress: " << p1 << " p1 value: " << *p1 << endl;

  int *p2 = new int[7] { 1, 2, 4, 8, 16, 32, 64 };
  cout << "p2 memory adress: " << p2 << endl;
  cout << "p2 values:\n";
  print_array(cout, p2, 7);

  int *p3 = p2;
  p2 = p1;
  p2 = p3;

  cout << "p1 memory adress: " << p1 << "value that p1 points to: " << *p1 << endl;
  cout << "p2 memory adress: " << p2 << "value that p2 points to " << *p2 << endl;

  delete p1;
  delete[] p2;

  p1 = new int[10]{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
  p3 = new int[10];
  delete[] p3;
  p3 = p1;
  cout << "p3 values:\n";
  print_array(cout, p3, 10);

  delete[] p3;
  vector<int> v1 = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
  vector<int> v2(v1.size());

  for (int i = 0; i < v1.size(); ++i)
  {
    v2[i] = v1[i];
  }

  cout << "v2 elemei:\n";
  for (auto const &i : v2)
  {
    cout << i << endl;
  }

  return 0;
}

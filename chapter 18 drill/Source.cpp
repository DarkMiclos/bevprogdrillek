#include "std_lib_facilities.h"

int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

int fact(int n)
{
  try
  {
    if (n <= 0)
    {
      error("The factorial value is 0 or lower.");
    }
    else
    {
      while (n > 1)
      {
        return n * fact(n - 1);
      }
    }
  }
  catch (exception &e)
  {
    cerr << e.what() << endl;
    return 1;
  }
  catch (...)
  {
    cerr << "Some error xd." << endl;
    return 0;
  }
}

void f(int a[], int n)
{
  int la[10];
  for (int i = 0; i < n; ++i)
  {
    la[i] = a[i];
  }
  cout << "Basic arrays elements:\n";
  for (auto const &i : la)
  {
    cout << i << endl;
  }
  int *p = new int[n];
  for (int i = 0; i < n; ++i)
  {
    p[i] = a[i];
  }
  cout << "Free store array elements:\n";
  for (int i = 0; i < n; ++i)
  {
    cout << p[i] << endl;
  }
  delete[] p;
}

int main()
{
  cout << "call f with ga\n";
  f(ga, 10);
  int aa[10];
  for (int i = 1; i < 11; ++i)
  {
    aa[i - 1] = fact(i);
  }
  /*cout << "aa elemei:\n";
  for (auto const &i : aa)
  {
    cout << i << endl;
  }*/
  cout << "call f with aa\n";
  f(aa, 10);
  return 0;
}
#include "std_lib_facilities.h"

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
  return n;
}

vector<int> gv{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(vector<int> v)
{
  vector<int> lv(v.size());
  for (int i = 0; i < v.size(); ++i)
  {
    lv[i] = gv[i];
  }
  cout << "Elements of lv\n";
  for (auto const &i : lv)
  {
    cout << i << endl;
  }
  vector<int> lv2(v);
  cout << "Elements of lv2\n";  
  for (auto const &i : lv2)
  {
    cout << i << endl;
  }

}

int main()
{
  cout << "Call f with gv as the argument:\n";
  f(gv);
  vector<int> vv;
  for (int i = 1; i < 11; ++i)
  {
    vv.push_back(fact(i));
  }
  cout << "Call f with vv as the argument:\n";
  f(vv);
  return 0;
}

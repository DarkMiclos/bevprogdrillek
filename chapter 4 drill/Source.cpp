#include "std_lib_facilities.h"

int main()
{
  vector<double> data;
  double temp = 0, temp_conv, largest = 0, smallest = 0, sum = 0;
  string unit;
  bool is_valid = true;
  int ctr = 0;
  cout << "Please give me numbers!\n";
  cout << "To terminate the program enter |\n";
  while (cin >> temp >> unit)
  {
    if (unit == "cm")
    {
      temp_conv = temp / 100;
    }
    else if (unit == "m")
    {
      temp_conv = temp;
    }
    else if (unit == "in")
    {
      temp_conv = temp * 0.0254;
    }
    else if (unit == "ft")
    {
      temp_conv = temp * 0.0254 * 12;
    }
    else
    {
      is_valid = false;
      cout << "Invalid unit!\n";
      cout << "Please enter a valid unit(cm, m, in, ft).\n";
    }
    if (is_valid)
    {
      cout << "The entered value is: ";
      cout << temp << ' ' << unit << endl;
      if (temp_conv < largest)
      {
        cout << "The smallest value so far" << endl;
        smallest = temp_conv;
      }
      if (smallest < temp_conv)
      {
        cout << "The largest value so far" << endl;
        largest = temp_conv;
      }
      sum += temp_conv;
      data.push_back(temp_conv);
      ++ctr;
    }
    is_valid = true;
    /*
    if(a == b)
    {
      cout << "The numbers are equal.\n";
    }
    if (abs(a - b) < 0.01)
    {
      cout << "The numbers are almost equal.\n";
    }
    */
  }
  cout << "The smallest value is: " << smallest << endl;
  cout << "The largest value is: " << largest << endl;
  cout << "Number of values: " << ctr << endl;
  sort(data);
  cout << "The values: " << endl;
  for (double number : data)
  {
    cout << number << " m" << endl;
  }
  return 0;
}
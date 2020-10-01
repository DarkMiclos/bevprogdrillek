#include "std_lib_facilities.h"

double convert(double &temp_conv,double temp,const string unit)
{
  constexpr double cm_to_m = 100;
  constexpr double in_to_m = 0.0254;
  constexpr double ft_to_m = 0.0254 * 12;
  if(unit == "cm")
  {
    temp_conv = temp /cm_to_m;
  }
  else if(unit == "m")
  {
    temp_conv = temp;
  }
  else if(unit == "in")
  {
    temp_conv = temp * in_to_m;
  }
  else if(unit == "ft")
  {
    temp_conv = temp * ft_to_m;
  }
  return temp_conv;

}

bool is_valid(const std::string& unit)
{
  if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft")
  {
    return true;
  }
  return false;
}

int main()
{
  vector<double> data;
  double temp = 0, temp_conv, largest = 0, smallest = 0, sum = 0;
  string unit;
  bool is_first = true;
  int ctr = 0;
  cout << "Please give me numbers!\n";
  cout << "To terminate the program enter |\n";
  while (cin >> temp >> unit)
  {
    if (is_valid(unit) == true)
    {
      convert(temp_conv, temp, unit);
      cout << "The entered value is: ";
      cout << temp << ' ' << unit << endl;
      if (temp_conv < smallest || is_first)
      {
        cout << "The smallest value so far" << endl;
        smallest = temp_conv;
      }
      else if (temp_conv > largest || is_first)
      {
        cout << "The largest value so far" << endl;
        largest = temp_conv;
      }
      sum += temp_conv;
      data.push_back(temp_conv);
      ++ctr;
      is_first = false;
    }
    else
    {
      cout << "Invalid unit!\n";
      cout << "Please enter a valid unit(cm, m, in, ft).\n";
    }
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

#include "std_lib_facilities.h"

class Year
{
  int year;
  static constexpr int min = 0;
  static constexpr int max = 2222;
public:
  class Invalid{};
  Year(int y) : year(y) { if (y < min || y > max) throw Invalid{}; }
  int get_year() { return year; }
  int increment() { return year++; }
};

Year operator++(Year& y)
{
  return y.increment();
}

ostream& operator<<(ostream& os, Year y)
{
  return os << y.get_year();
}

Vector<string> months =
{
  "January", "February", "March", "April", "May", "June", "July", 
  "August", "September", "Oktober", "November", "December"
};

enum class Month
{
  jan, feb, mar, apr, may, jun, jul, aug, szept, okt, nov, dec
};

Month operator++(Month m)
{
  m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
  return m;
}

ostream& operator<<(ostream& os, Month m)
{
  return os << months[int(m)];
}


class Date
{
  Year year;
  Month month;
  int day;
public:
  class Invalid{};
  Date(Year y, Month m, int d) : year(y), month(m), day(d) { if (!is_valid()) throw Invalid{}; }
  bool is_valid();
  void add_day(int n);
  Year get_year() { return year; }
  Month get_month() { return month; }
  int get_day() { return day; }
  int set_day(int n);
  Year set_year(int n);
};

Year Date::set_year(int n)
{
  year = n;
  return year;
}

int Date::set_day(int n)
{
  day = n;
  if (day > 31 || day < 1)
  {
    error("Invalid day");
  }
  return day;
}

bool Date::is_valid()
{
  if (day > 31 || day < 1) return false;
  return true;
}

void Date::add_day(int n)
{
  day += n;
  if (day > 31)
  {
    ++month;
    day -= 31;
    if (month == Month::dec)
    {
      ++year;
    }
  }
}

int main()
try{
  Date today{ Year{2020 }, Month::nov, 12 };
  cout << today.get_year() << ". " << today.get_month() << ' ' << today.get_day() << ".\n";
  Date tomorrow = today;
  tomorrow.add_day(1);
  cout << tomorrow.get_year() << ". " << tomorrow.get_month() << ' ' << tomorrow.get_day() << ".\n";
  today.set_year(2002);
  cout << today.get_year() << endl;
  today.set_day(35);
  cout << today.get_day() << endl;
  return 0;
}
catch (Date::Invalid)
{
  cout << "Invalid date" << endl;
  return 1;
}
catch (Year::Invalid)
{
  cout << "Invalid year\n";
  return 2;
}
catch (exception& e)
{
  cerr << e.what() << endl;
  return 3;
}
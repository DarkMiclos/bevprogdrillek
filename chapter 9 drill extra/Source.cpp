#include "std_lib_facilities.h"

namespace UDChrono
{

  class Day
  {
  private:
    int day;

    static constexpr int min = 1;
    static constexpr int max = 31;

  public:
    class Invalid : public exception {};

    Day(int d)
      :
      day(d)
    {
      if (d < min || d > max)
      {
        throw Invalid{};
      }
    }

    int get_day() const
    {
      return day;
    }

    void set_day(int new_day)
    {
      day = new_day;
    }

    Day& operator=(int n)
    {
      day = n;
      return *this;
    }
  };

  ostream& operator<<(ostream& os, Day d)
  {
    return os << d.get_day(); //
  }

  bool operator<(Day d, int n)
  {
    if (d.get_day() < n)
    {
      return true;
    }
    return false;
  }

  bool operator>(Day d, int n)
  {
    if (d.get_day() > n)
    {
      return true;
    }
    return false;
  }

  Day operator+=(Day& d, int n)
  {
    d.set_day(d.get_day() + n);
    return d;
  }

  Day& operator-=(Day& d, int n)
  {
    d.set_day(d.get_day() - n);
    return d;
  }

  class Year
  {
  private:
    int year;

    static constexpr int min = 0;
    static constexpr int max = 2222;

  public:
    class Invalid : public exception {};

    Year(int y)
      :
      year(y)
    {
      if (y < min || y > max)
      {
        throw Invalid{};
      }
    }
    int get_year() const
    {
      return year;
    }

    int increment()
    {
      return year++;
    }
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
  private:
    Year year;
    Month month;
    Day day;

  public:
    class Invalid : public exception {};

    Date()
      :
      year(Year{ 2002 }),
      month(Month::mar),
      day(Day{ 1 })
    {
    }

    Date(Year y, Month m, Day d)
      :
      year(y),
      month(m),
      day(d)
    {
      if (!is_valid()) throw Invalid{};
    }

    bool is_valid();

    void add_day(int n);

    Year get_year() const
    {
      return year;
    }

    Month get_month() const
    {
      return month;
    }

    Day get_day() const
    {
      return day;
    }

    Day set_day(int n);

    Month set_month(Month m);

    Year set_year(int n);
  };

  Year Date::set_year(int n)
  {
    year = n;
    return year;
  }

  Month Date::set_month(Month m)
  {
    month = m;
    return month;
  }

  Day Date::set_day(int n)
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
    if (day > 31 || day < 1)
    {
      return false;
    }
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

}//End of UDChrono!

int main()
{
  try
  {
    UDChrono::Date today{ UDChrono::Year{ 2020 }, UDChrono::Month::nov, 12 };
    cout << "Today:" << today.get_year() << ". " << today.get_month() << ' ' << today.get_day() << ".\n";
    UDChrono::Date tomorrow{ today };
    tomorrow.add_day(1);
    cout << "Tomorrow" << tomorrow.get_year() << ". " << tomorrow.get_month() << ' ' << tomorrow.get_day() << ".\n";
    UDChrono::Date Auto{};
    cout << "Auto date: " << Auto.get_year() << ", " << Auto.get_month() << ' ' << Auto.get_day() << ".\n";
    UDChrono::Date copy{ today };
    cout << "Copy of today: " << copy.get_year() << ", " << copy.get_month() << ' ' << copy.get_day() << ".\n";
    vector<UDChrono::Date> dates(10);
    for (const auto& date : dates)
    {
      cout << "Date: " << date.get_year() << ". " << date.get_month() << ' ' << date.get_day() << ".\n";
    }
    today.set_year(2002);
    cout << today.get_year() << endl;
    today.set_month(UDChrono::Month::jan);
    cout << today.get_month() << endl;
    today.set_day(35);
    cout << today.get_day() << endl;
    return 0;
  }
  catch (UDChrono::Date::Invalid&)
  {
    cout << "Invalid date" << endl;
    return 1;
  }
  catch (UDChrono::Year::Invalid&)
  {
    cout << "Invalid year\n";
    return 2;
  }
  catch (UDChrono::Day::Invalid&)
  {
    cout << "Invalid Day\n";
  }
  catch (exception& e)
  {
    cerr << e.what() << endl;
    return 3;
  }
  return 0;
}
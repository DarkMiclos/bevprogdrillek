#include "std_lib_facilities.h"

struct Point
{
  double x, y;
  Point() = default;
  Point(double x, double y)
    :
    x(x),
    y(y)
  {
  }
};

ostream &operator<<(ostream &out, Point const &point)
{
  out << '(' << point.x << ',' << point.y << ')';
  return out;
}

istream &operator>>(istream &in, vector<Point> &processed_points)
{
  char c;
  for (Point point; in >> c >> point.x >> c >> point.y >> c; processed_points.push_back(point));
  return in;
}

bool operator==(Point const &p1, Point const &p2)
{
  return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(Point const &p1, Point const &p2)
{
  return !(p1 == p2);
}

int main()
{
  vector<Point> original_points;
  cout << "Please enter seven (x,y) pairs: ";
  auto i = 0ull;
  for (Point point; i < 7; cin >> point.x >> point.y, original_points.push_back(point), ++i);
  ofstream out("mydata.txt", ios::out);
  for (auto const &point : original_points)
  {
    out << point << endl;
  }
  out.close();
  ifstream in("mydata.txt", ios::in);
  vector<Point> processed_points;
  in >> processed_points;
  if (original_points.size() != processed_points.size())
  {
    cout << "Something is wrong!\n";
  }
  else
  {
    int i = 0;
    for (; i < original_points.size(); ++i)
    {
      if (original_points[i] != processed_points[i])
      {
        cout << "Something is wrong!\n";
        break;
      }
    }
    if (i == original_points.size())
    {
      cout << "The 2 vectors are the same!\n";
      cout << "original_points: \n";
      for (auto const &point : original_points)
      {
        cout << point << endl;
      }
      cout << "processed_points: \n";
      for (auto const &point : processed_points)
      {
        cout << point << endl;
      }
    }
  }
  return 0;
}
#include "std_lib_facilities.h"

int main()
{
  int birth_year = 2002, birth_month = 3, birth_day = 1, a, b, c, d;
  cout << showbase << dec << birth_year << "\tdecimal\n" << hex << birth_year << "\thexadecimal\n" << oct << birth_year << "\tdecimal" << endl;
  cout << dec << birth_year << '.' << birth_month << '.' << birth_day << endl;
  cin >> a >> oct >> b >> hex >> c >> d;
  cout << a << '\t'<< b << '\t' << c << '\t' << d << '\n';
  cout << noshowbase << dec;
  float num = 1234567.89;
  cout << num << '\t' << fixed << num << '\t' << scientific << num << endl;
  cout << "|Miki|" << setw(8) <<"|Nem|" << setw(10) << "|Nem|\n"
    << "|Zsolti|" << setw(8) << "|tudok|" << setw(10) << "|Tudok|\n"
    << "|Norbi|" << setw(9) << "|Ennyi|" << setw(10) << "|Ennyi|\n"
    << "|Arpi|" << setw(9) << "|Telo|" << setw(12) << "|Emailt|\n"
    << "|Szabi|" << setw(10) << "|Szamot|" << setw(7) << "|Sem|\n";
  return 0;
}
#include "std_lib_facilities.h"

int main()
{
  cout << "Enter the name of the person you want to write to: ";
  string first_name;
  cin >> first_name;
  cout << "Dear " << first_name << "," << endl;
  cout << "  How are you? I am fine. We should meet up sometime.\n";
  cout << "Name a friend that both of you know: ";
  string friend_name;
  cin >> friend_name;
  cout << "Have you seen " << friend_name << " lately?" << endl;
  char friend_sex = 0;
  cout << "Press f if this friend is female and m if male: ";
  cin >> friend_sex;
  if (friend_sex == 'f')
  {
    cout << "If you see " << friend_name << " please ask her to call me." << endl;
  }
  if (friend_sex == 'm')
  {
    cout << "If you see " << friend_name << " please ask him to call me." << endl;
  }
  cout << "Please enter the age of the recipient: ";
  int age;
  cin >> age;
  cout << "I hear you just had a birthday and you are " << age << " years old." << endl;
  try
  {
    if (age <= 0 || age >= 110)
    {
      throw runtime_error("you're kidding!");
    }
    else if (age < 12)
    {
      cout << "Next year you will be " << age + 1 << "." << endl;
    }
    else if (age == 17)
    {
      cout << "Next year you will be able to vote." << endl;
    }
    else if (age > 70)
    {
      cout << "I hope you are enjoying retirement." << endl;
    }
  }
  catch (const std::runtime_error &ex)
  {
    std::cerr << ex.what() << std::endl;
    return -1;
  }
  cout << "Yours sincerely,\n\nLockar Miklos" << endl;

  return 0;
}
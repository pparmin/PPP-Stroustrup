#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

inline void keep_window_open() { char ch; cin>>ch; }

int main() 
{
  cout << "Please enter your first name \n";
  string first_name;
  cin >> first_name;
  cout << "Hello, " << first_name << "\n";
  cout << "Enter the name of the person you want to write to and a missing friend: \n";
  string friend_name; 
  string missing_friend;
  cin >> friend_name;
  cin >> missing_friend;
  cout << "What sex is the missing friend (m/f): ";
  char friend_sex = 0;
  cin >> friend_sex;
  cout << "Please enter the age of the recipient: ";
  int age = 0;
  cin >> age;

  if (age <= 0 || age >= 110) {
    cerr << "error: You've got to be kidding. \n";
	  //keep_window_open();		// for some Windows environments
    exit(1);
  }
  
  cout << "Dear " << friend_name << ", \n"; 
  if (age < 12) {
    cout << "Next year you will be " << age + 1 << " years old!\n";
  } else if (age == 17) {
    cout << "Next year you will be able to vote! \n";
  } else if (age > 70) {
    cout << "I hope you are enjoying retirement! \n";
  }

  cout << "How are you? I've really been missing " << missing_friend << "\n";

  if (friend_sex == 'm') {
    cout << "If you see " << missing_friend << " please ask him to call me.\n";
  } else if (friend_sex == 'f') {
    cout << "If you see " << missing_friend << " please ask her to call me.\n";
  }

  cout << "Yours sincerely, \n" << first_name << '\n';
}


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

inline void keep_window_open() { char ch; cin>>ch; }

int main () {
  cout << "Please enter your first name \n";
  string first_name;
  cin >> first_name;
  cout << "Hello, " << first_name << ". What's your age?\n";
  double age;
  cin >> age;
  cout << first_name << ", You are " << age << " years old! \n";
  return 0;
}

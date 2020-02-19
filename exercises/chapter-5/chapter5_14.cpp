#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// function to convert the initial string to lowercase 
string convertToLower (string s) 
{
  string sToLower;
  for(int i = 0; i < s.size(); ++i) {
    //cout << "char: " << tolower(int(s[i])) << endl;
    sToLower += tolower(int(s[i]));
  }

  return sToLower;
}

// check whether weekday exists within vector
bool nameInVector(vector<string> names, string weekday) 
{
  for (string entry : names) {
    if (entry == weekday) {
      return true;
    }
  }
  return false;
}

int main()
{
  vector<int> monday, tuesday, wednesday, thursday, friday, saturday, sunday;
  vector<vector<int> > weekdays;
  vector<string> acceptedNames = {"monday", "tuesday", "wednesday", "thursday", "friday",
  "saturday", "sunday", "mon", "tue", "wed", "thu", "fri", "sat", "sun"};
  string weekday;
  int value;

  weekdays.push_back(monday);
  weekdays.push_back(tuesday);
  weekdays.push_back(wednesday);
  weekdays.push_back(thursday);
  weekdays.push_back(friday);
  weekdays.push_back(saturday);
  weekdays.push_back(sunday);


  cout << "Please input a day of the week and a corresponding value: \n";

  while(cin >> weekday >> value) {
    weekday = convertToLower(weekday);
    cout << "converted: " << weekday << endl;
    if (nameInVector(acceptedNames, weekday)) {
      if ()
      cout << "name: " << weekday << " exists in vector and is therefore valid.\n";
    }
    //weekday = convertToLower(weekday);
  }

}
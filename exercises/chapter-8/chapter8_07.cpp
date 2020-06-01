/* Exercise 07: */


#include <iostream>
#include <vector>
#include <string>
using namespace std;

// read names into vector or return false if keyword is mentioned
bool read_names(vector<string>& names)
{
  string name;
  cout << "Please enter five names. When you are done, move forward by typing 'exit'" << endl;
  while(cin >> name) { 
    if (name == "exit") break;
    
    names.push_back(name);
  }
  return false;
}

// read ages into vector or return false if keyword is mentioned
bool read_ages(vector<string>& ages)
{
  string age;
  cout << "Please enter the age of all five people. Move forward by typing 'exit' again" << endl;
  while(cin >> age) { 
    if (age == "exit") break;
    
    ages.push_back(age);
  }
  return false;
}

int main()
{
  string name;
  vector<string> names;
  vector<string> ages;

  read_names(names);
  read_ages(ages);
  cout << "NAMES: " << endl;
  for (string n : names) {
    cout << n << endl;
  }
    cout << "AGES: " << endl;
  for (string n : ages) {
    cout << n << endl;
  }
}
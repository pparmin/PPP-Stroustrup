/* Exercise 02: Print a vector of ints to cout */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string print(const vector<int>& numbers) 
{
  string r = "";
  for (const int& n : numbers) {
    r += to_string(n) + " ";
  }
  return r;
}

int main()
{
  vector<int> numbers = { 0, 7, 123516, 5712, 19, 281 };
  cout << print(numbers) << endl;
  return 0;
}
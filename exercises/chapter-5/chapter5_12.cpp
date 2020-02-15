/* Exercise 12 & 13: Bulls & Cows

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
  string test = "Let me split this";
  vector<string> result; 
  for (int i = 0; i < test.end(); i++) {
    cout << "W: " << test[i] << endl;
  }
  //boost::split(results, test, isDelimiter())
  /*

  vector<int> numbers = {1, 2, 3, 4};
  vector<int> i_vec;
  int input = 0;
  int c_input;

  cout << "Please enter a number: \n";
  cin >> input;
  string str = to_string(input);

  for (int i = 0; i < str.end(); )

  cout << "Conversion: " << str << endl;
  for (int i = 0; i < str.size(); ++i) {
    cout << "nr " << i << ": " << str[i] << endl;
    c_input = stoi(str[i]);
    cout << "c_input: " << c_input << endl;
    i_vec.push_back(c_input);
  }

  /*for (int n : i_vec) {
    cout << "c: " << n << endl;
  }*/

  return 0;
}
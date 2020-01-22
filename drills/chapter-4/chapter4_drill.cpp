/*
Here you can find the solutions to all the drills (1 - 11) of chapter 4. If code
covers multiple drills the code is always going to cover the last version of.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

inline void keep_window_open() { char ch; cin>>ch; }

/* Drill number 1 - 5 

int main() 
{
  double a, b;

  while (cin >> a >> b) {
    //cout << "First Number: " << a << " Second Number: " << b << endl;
    double difference = std::abs(a - b);
    cout << "difference: " << difference << endl;

    if (a < b) {
      cout << "The smaller number is: " << a << endl;
      cout << "The larger number is: " << b << endl;
      //difference = b - a;
    } else if (a == b) {
      cout << "Both numbers are equal. \n";
    } else {
      cout << "The smaller number is: " << b << endl;
      cout << "The larger number is: " << a << endl;
      //difference = a - b;
    }

    if (difference <= (1.0/100)) {
      cout << "Both numbers are almost equal.\n";
    }
  }
}*/

/* Drill number 6 - 10 */

int main() 
{
  constexpr double CM_TO_M = 0.01;
  constexpr double IN_TO_M = 0.0254;
  constexpr double FT_TO_M = 0.03048;

  int number_of_values;
  double value;
  double largest = 0;
  double smallest = 0;
  string unit;

  vector<double> values;

  while (cin >> value >> unit) {
    if (largest == 0 && smallest == 0) {
      largest = value; 
      smallest = value;
    }

    number_of_values++;

    if (unit == "cm") {
      values.push_back(value * CM_TO_M);
      value = value * 0.01;
    } else if (unit == "m") {
      values.push_back(value);
    } else if (unit == "in") {
      values.push_back(value * IN_TO_M);
      value = value * 0.0254;
    } else if (unit == "ft") {
      values.push_back(value * FT_TO_M);
      value = value * 0.3048;
    } else {
      number_of_values--;
      cout << "Unit not known \n";
    }
    
    if (value > largest) {
      largest = value;
    } else if (value < smallest) {
      smallest = value;
    } 
  }
  
  sort(values.begin(), values.end());

  cout << "Number of values: " << number_of_values << endl; 
  cout << "List of values: " << endl; 
  for (int i = 0; i < values.size(); i++) {
    cout << values[i] << endl;
  }

  cout << "Smallest number: " << smallest << endl
       << "Largest number: " << largest << endl;
}
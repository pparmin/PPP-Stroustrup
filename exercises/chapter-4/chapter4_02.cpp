#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/* Exercise 2: Calculate median of a sequence of numbers 
(both even/odd sequences) 

Description: 
If we define the median of a sequence as "a number so that exactly as many elements
come before it in the sequence as come after it", fix the program in §4.6.3 so that
it always prints out a median. 
*/

int main() 
{
  vector<double> values;

  for(double value; cin >> value;) {
    values.push_back(value);
  }
  sort(values.begin(), values.end());
  for (double value : values) {
    cout << value << endl;
  }

  // check whether even or odd
  if (values.size() % 2 != 0) {
    cout << "Median for odd amount of numbers: " << values[values.size()/2] << endl;
  } else if (values.size() % 2 == 0) {
    cout << "Median for even amount of numbers: " << (values[values.size()/2] + values[values.size()/2 - 1]) / 2 << endl;
  }
}
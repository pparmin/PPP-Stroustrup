#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/* Exercise 6: Digit to spelled-out converter 

Description: 
Make a vector holding the ten string values "zero", "one" ... "nine". Use that in
a program that converts a digit to its corresponding spelled-out value.
*/

int main()
{
  vector<string> spelled_out {"zero", "one", "two", "three", "four", "five", "six",
                              "seven", "eight", "nine"};
  vector<string> digits {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  string number;

  cout << "Please give a number from 0 - 9 or \"zero\"-\"nine\": \n";
  
  while (cin >> number) {
    bool was_found = false;

    for (int i = 0; i <= spelled_out.size(); i++) {
      if (spelled_out[i] == number) {
        cout << digits[i] << endl;
        was_found = true;
      } else if (digits[i] == number) {
        cout << spelled_out[i] << endl;
        was_found = true;
      } 
    }

    if (!was_found) {
      cout << "Input faulty or number not in range.\n";
    }
  }
  return 0;
}
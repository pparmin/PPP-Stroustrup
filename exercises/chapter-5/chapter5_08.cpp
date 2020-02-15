/* Exercise 8 & 9 & 10: 

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void error(string s) 
{
  throw runtime_error(s);
}

int main()
{
  try
  {
    vector<double> values;
    double sum = 0;
    double value = 0;
    int n = 0;
    cout << "Please enter the number of values you want to sum: \n";
    cin >> n;
    if (n == 0) {
      error("No numbers given as input.");
    }

    cout << "Please enter some integers (press '|' to stop): \n";
    while (cin >> value)
    {
      values.push_back(value);
    }

    if (n > values.size())
    {
      error("The number of values for summation is greater than the overall amount of values.");
    }

    for (int i = 0; i < values.size(); ++i) {

    }

    cout << "The sum of the first " << n << " numbers ( ";
    for (int i = 0; i < n; ++i) {
      cout << values[i] << " ";
      sum += values[i];
    }
    cout << ") is: " << sum << endl; 
    //cout << "The sum of the first " << n << " numbers is: " << sum << endl;
    return 0;
  }
  catch (exception& e) {
    cerr << "Runtime Error: " << e.what() << endl;
    return 1;
  }
}
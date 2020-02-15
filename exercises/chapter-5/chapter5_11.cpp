/* Exercise 11: Fibonacci

Description: Write a program that writes out the first so many values of the Fibonacci series. Find the
largest Fibonacci number that fits in an int.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() 
{
  vector<int> fibonacci = {1, 1};
  int n_of_iterations;
  int fn;

  cout << "Please enter the amount of desired iterations for the series: \n";
  cin >> n_of_iterations;

  // largest fibonacci number is reached at 45 iterations
  if (n_of_iterations > 45) {
    cout << "Runtime Error: Integer type can't hold values after 45 iterations.\n";
    return 1;
  }

  // Fibonacci formula: Fn = F(n-1) + F(n - 2)
  for (int n = 2; n <= n_of_iterations; n++) {
    fn = fibonacci[n - 1] + fibonacci[n - 2];
    fibonacci.push_back(fn);
  }

  cout << "Fibonacci sequence: ";
  for (int number : fibonacci) {
    cout << number << " ";
  }
  cout << '\n';
  return 0;
}
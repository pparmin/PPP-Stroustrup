#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

inline void keep_window_open() { char ch; cin>>ch; }

/* Mile to kilometers converter

int main()
{
  cout << "Please enter the number of miles: ";
  double miles = 0; 
  cin >> miles;

  double kilometers = miles * 1.60934;
  cout << "The number of kilometers for " << miles << " miles is: "
       << kilometers << '\n';
}*/

/* Larger, smaller, sum, difference, product, ratio 

int main () 
{
  cout << "Please enter two integer values: "; 
  double i1 = 0;
  double i2 = 0;
  cin >> i1 >> i2;

  if (i1 > i2) {
    cout << "Larger number is: " << i1 << '\n';
    cout << "Smaller number is " << i2 << '\n';
  } else {
    cout << "Larger number is: " << i2 << '\n';
    cout << "Smaller number is " << i1 << '\n';
  }

  int difference = i1 - i2;
  cout << "Difference: " << difference << '\n';

  int sum = i1 + i2; 
  cout << "Sum: " << sum << '\n';

  int product = i1 * i2;
  cout << "Product: " << product << '\n';

  double ratio = i1 / i2;
  cout << "Ratio: " << ratio << '\n';
}*/

/* Even & Odd 

int main() 
{
  cout << "Please enter an integer value: \n";
  int value = 0;
  cin >> value;

  if (value % 2 == 0) 
  {
    cout << value << " is even!\n";
  } else if (value % 2 != 0) {
    cout << value << " is odd!\n";
  }
}*/

/* Operator and two Operands 
int main()
{
  cout << "Please enter an operator and two operands: \n";
  string operation = " ";
  double operand_one = 0;
  double operand_two = 0; 
  cin >> operation >> operand_one >> operand_two;

  if (operation == "+" || operation == "plus") {
    cout << "Sum: " << operand_one + operand_two << '\n'; 
  } else if (operation == "-" || operation == "minus") {
    cout << "Difference: " << operand_one - operand_two << '\n'; 
  } else if (operation == "*" || operation == "mul") {
    cout << "Product: " << operand_one * operand_two << '\n'; 
  } else if (operation == "/" || operation == "div") {
    cout << "Division: " << operand_one / operand_two << '\n'; 
  }
}*/
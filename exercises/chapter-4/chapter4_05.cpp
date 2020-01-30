#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/* Exercise 5: Simple Calculator

Description: 
Write a program that performs as a very simple calculator. Your calculator should be 
able to handle the four basic math operations - add, subtract, mutiply and divide -
on two input values. Your program should promot the user to enter three arguments:
two double values and a character to represent an operation.
*/

int add(int a, int b) 
{
  return a + b;
}

int subtract(int a, int b) 
{
  return a - b;
}

int divide(int a, int b) 
{
  return a / b;
}

int multiply(int a, int b)
{
  return a * b;
}

int main() 
{
  int number_one, number_two;
  int result;
  char operation;

  cout << "Please enter three arguments. The first two should be integer numbers. "
       << "The third argument should be your operator of choice (+|-|*|/).\n";
  cin >> number_one >> number_two >> operation;

  switch(operation) {
    case '+':
      result = add(number_one, number_two);
      cout << "The sum of " << number_one << " and " << number_two << " is: " 
           << result << endl;
      break;
    
    case '-':
      result = subtract(number_one, number_two);
      cout << "The difference of " << number_one << " and " << number_two << " is: " 
           << result << endl;
      break;

    case '*':
      result = multiply(number_one, number_two);
      cout << "The product of " << number_one << " and " << number_two << " is: " 
           << result << endl;
      break;
  
    case '/':
      if (number_two == 0) {
        cout << "ERROR: Can not divide by 0!\n";
        break;
      }
      
      result = divide(number_one, number_two);
      cout << "The division of " << number_one << " and " << number_two << " is: " 
           << result << endl;
      break;

    default:
      cout << "Please use only the four basic operators.\n";
      break;
  }
  return 0;
}
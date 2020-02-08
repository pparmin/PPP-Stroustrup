/* Quadratic Equation Solver 


Description:
Write a program to solve quadratic equations.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main()
{
  double a, b, c;
  double x, x1, x2;

  cout << "Please give values for a, b, c: \n";
  cin >> a >> b >> c;

  double delta = b*b - 4*a*c;

  if (delta < 0) {
    cout << "Sorry, can't solve that, number in sqr is negative. \n";
  } else if (delta == 0) {
    x = -b / (2*a);
    cout << "Since root equals zero, there's only one soltution: x = " << x << endl;
  } else {
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
    cout << "x1: " << x1 << " x2: " << x2 << endl; 
  }
}
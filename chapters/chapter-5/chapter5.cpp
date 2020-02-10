#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;


void error(string s1)
{
  throw runtime_error(s1);
}

int main()
{
  try
  {
    double d = 0;
    cin >> d;
    if (!cin) {
      error("No double was given as input!");
    }
  }
  catch(exception& e) {
    cerr << "Runtime Error: " << e.what() << endl;
    return 1; 
  }
  return 0;
}

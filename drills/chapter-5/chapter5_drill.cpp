/*
The drills for this chapter included 20+ error fixes, therefore this file looks rather 
empty. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
  try {
    string s = "Success\n";
    for (int i = 0; i < s.size(); ++i) {
      if (i % 2 == 0) {
        continue;
      } 
      cout << "letter: " << s[i] << endl;
    }
    return 0;
  }
  catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
  }
  catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
  }
}
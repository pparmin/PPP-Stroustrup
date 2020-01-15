#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

inline void keep_window_open() { char ch; cin>>ch; }

/* Multiple cout's 

int main() {
  cout << "Please enter a floating-point value: ";
  int n;
  cin >> n;
  cout << "n == " << n
       << "\nn+1 == " << n+1
       << "\n n divided by three == " << n/3
       << "\n modulo 5 == " << n % 5
       << "\nthree times n == " << 3*n
       << "\ntwice n == " << n+n
       << "\nn squared == " << n*n
       << "\nhalf of n == " << n/2
       << "\nsquare root of n == " << sqrt(n)
       << '\n';
}
*/ 

/*
int main() 
{
  cout << "Please enter your first and second names \n";
  string firstName;
  string secondName;
  cin >> firstName >> secondName;
  string fullName = firstName + ' ' + secondName;
  cout << "Hello, " << fullName << '\n';
} */

/* repeated words
*/

/* Counter
int main()
{
  string previous = " ";
  string current; 
  int counter = 0; 
  int number_of_words = 0;
  while (cin>>current) {
    number_of_words++;
    if (previous == current) {
      counter++;
      cout << "Current repetitions: " << counter << " at word number: "
      << number_of_words << "\n";
      //cout << "repeated word: " << current << "\n";
    }
    previous = current;
  }
}*/

/* Unsafe conversions */ 
int main() 
{
  double d = 0;
  while (cin >> d) {
    
    int i = d;          // try to get a double into an int
    char c = i;         // try to get an int into a char
    int i2 = c;         // get the integer value of the characters
    cout << "d==" << d  // cout original double
         << " i==" << i  // cout converted to int
         << " i2==" << i2 // cout int value of char
         << " char(" << c << ")\n"; // cout the char
  }
}
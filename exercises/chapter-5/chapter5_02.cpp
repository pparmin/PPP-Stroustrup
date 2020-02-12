/* Exercise 2 & 3 & 4 & 5 & 6: Temperature conversion

Description:
This little converter covers both directions, from Celsius to Kelvin and from Kelvin to Celsius. From the
book it covers multiple exercises at once. The program uses proper pre-condition tests to make sure you 
cant give an impossible value (like 0K or -273.15C).

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void error(string s1)
{
  throw runtime_error(s1);
}

/* ----------- Functions for the different conversions ----------- */

double ctof(double c)
{
  if (c < -273.15) {
    error("You can't give an impossible temperature.\n");
  }
  double f = (c * (9/5)) + 32;
  return f;
}

double ftoc(double f)
{
  if (f < -459.67) {
    error("You can't give an impossible temperature.\n");
  }
  double c = (f - 32) * (5/9);
  return c;
}


double ktoc(double k) 
{
  if (k < 0) {
    error("You can't give an impossible temperature.\n");
  }

  double c = k - 273.15;
  return c;
}

double ctok(double c)
{
  if (c < -273.15) {
    error("You can't give an impossible temperature.\n");
  }

  double k = c + 273.15;
  return k;
}

double ktof(double k) 
{
  if (k < 0) {
    error("You can't give an impossible temperature.\n");
  }
  double f = (k * 9/5) - 459.67;
  return f;
}

double ftok(double f)
{
  if (f < -459.67) {
    error("You can't give an impossible temperature.\n");
  }
  double k = (f + 459.67) + (5/9);
  return k;
}

/* ---------------------------------------------------- */

int main() 
{
  try {
  double celsius, kelvin, fheit;
  double result;
  char m, cm;

  // TODO: Add if-conditional for choosing type of conversion (either ctok or ktoc)
  cout << "Please insert the measure you want to convert from ('c' for Celsius, 'k' for Kelvin, 'f' for Fahrenheit): \n";
  cin >> m;
  // convert to lowercase so input can be either upper- or lowercase
  m = tolower(int(m));

  cout << "Please choose into which measure you want to convert? ('c', 'f' or 'k'): \n";
  cin >> cm;
  cm = tolower(int(cm));

    if (m == 'c') {
      cout << "Please insert an amount of Celcius: \n";
      cin >> celsius;
      switch(cm) {
        case 'f': 
          result = ctof(celsius);
          cout << "Converted value: " <<  result << " Fahrenheit" << endl;
          return 0;
      
        case 'k':
          result = ctok(celsius);
          cout << "Converted value: " <<  result << " Kelvin" << endl;
          return 0;  
      
        default: 
          error("It seems like you have not chosen a correct measure");
          return 1;
      }
    
    } else if (m == 'k') {
      cout << "Please insert an amount of Kelvin: \n";
      cin >> kelvin;
      switch(cm) {
        case 'f':
          result = ktof(kelvin);
          cout << "Converted value: " <<  result << " Fahrenheit" << endl;
          return 0;

        case 'c':
          result = ktoc(kelvin);
          cout << "Converted value: " <<  result << " Celcius" << endl;
          return 0;
        
        default: 
          error("It seems like you have not chosen a correct measure");
          return 1;
      }

    } else if (m == 'f') {
      cout << "Please insert an amount of Fahrenheit: \n";
      cin >> fheit;
      switch(cm) {
        case 'c':
          result = ftoc(fheit);
          cout << "Converted value: " <<  result << " Celsius" << endl;
          return 0;

        case 'k': 
          result = ftok(fheit);
          cout << "Converted value: " <<  result << " Kelvin" << endl;
          return 0;

        default: 
          error("It seems like you have not chosen a correct measure");
          return 1;
      }
    } else if (m != 'k' || m != 'c') {
      error("It seems like you have not chosen a correct measure");   
    }
  } 
  catch (exception& e) { 
    cerr << "Runtime Error: " << e.what() << endl;
    return 1;
  }
  catch (...) {
    cerr << "Oops. And unidentified Error has been encountered!\n";
    return 2;
  }
}
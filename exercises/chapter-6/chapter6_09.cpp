/* Exercise 9: Digit to Integer Converter

TODO: Get the full number (meaning '1''4''7' is 147 as integer)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void error(string s) 
{
  throw runtime_error(s);
}

class Number {
public:
  char digit;
  int number;
  Number(char digit)
    :digit(digit), number(0) { }
  Number(char digit, int number)
    :digit(digit), number(number) { }
  
  Number get();
  Number convertDigit(Number n);
  void output(vector<int> numbers);

private: 
  int size = 0;
};

Number get() 
{
  char d;
  cin >> d;
  return Number(d);
}

Number Number::convertDigit(Number n)
{

  switch(n.digit) {
    case '0':
      return Number('0', 0);
    case '1':
      return Number('1', 1);
    case '2':
      return Number('2', 2);
    case '3':
      return Number('3', 3);
    case '4':
      return Number('4', 4);
    case '5':
      return Number('5', 5);
    case '6':
      return Number('6', 6);
    case '7':
      return Number('7', 7);
    case '8':
      return Number('8', 8);
    case '9':
      return Number('9', 9);
    
    default:
      error("No digit between 0 - 9 was given.");
  }
}

void Number::output(vector<int> numbers) 
{
  int final_number;
  size = numbers.size();

  if (size == 1)
  {
    cout << numbers[0] << " is " << numbers[0] << " ones." << endl;
  }
  else if (size == 2)
  {
    final_number = numbers[0] * 10 + numbers[1];
    cout << final_number << " is " << numbers[0] << " tens and " << numbers[1] << " ones." << endl;
  }
  else if (size == 3)
  {
    final_number = numbers[0] * 100 + numbers[1] * 10 + numbers[2];
    cout << final_number << " is " << numbers[0] << " hundreds and " << numbers[1] << " tens and "
         << numbers[2] << " ones." << endl;
  }
  else if (size == 4)
  {
    final_number = numbers[0] * 1000 + numbers[1] * 100 + numbers[2] * 10 + numbers[3];
    cout << final_number << " is " << numbers[0] << " thousands and " << numbers[1] << " hundreds and "
         << numbers[2] << " tens and " << numbers[3] << " ones." << endl;
  }
  size = 0;
}

int main()
{
  try 
  {
    // Vectors for output
    vector<char> digits;
    vector<int> numbers;

    cout << "Please input a number for conversion. In order to indicate your final number"
         << " please end your input with a '=' character." << endl;
    while (cin) {
      Number n = get();

      if (n.digit == '=')         // handles end of number
      {
        n.output(numbers);        // create the output
        numbers = {};             // set 
        digits = {};
        continue;
      }

      n = n.convertDigit(n);
      //cout << "original digit: " << n.digit << endl;
      digits.push_back(n.digit);
      //cout << "integer digit: " << n.number << endl;
      numbers.push_back(n.number);  
      //cout << "numbers size pre-deletion: " << numbers.size() << endl;

      if (numbers.size() > 4) {
        error("Please only enter numbers that have a length between 1 and 4 digits.");
      }
    } 

    return 0;
  }
  catch(exception &e) 
  {
    cerr << "Runtime error: " << e.what() << endl;
    return -1;
  }
}
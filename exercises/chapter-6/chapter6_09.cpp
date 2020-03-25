/* Exercise 9: Digit to Integer Converter

Description: Write a program that reads digits nd composes them into integers. For example, 123 is read
as the characters 1, 2, and 3. The program should output 123 is 1 hundred and 2 tens and 3 ones. The number
should be output as an int value. Handle numbers with one, two, three, or four digits.
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
  // set size back to 0 for next result
  size = 0;
}

int main()
{
  try 
  {
    vector<int> numbers;

    cout << "Please input a number for conversion. In order to indicate your final number"
         << " please end your input with a '=' character." << endl;
    while (cin) {
      Number n = get();

      if (n.digit == '=')         // handles end of number
      {
        n.output(numbers);        // create the output
        numbers = {};             // delete all numbers from vector for next result
        continue;
      }

      if (n.digit == 'x') break;  // end program

      n = n.convertDigit(n);
      numbers.push_back(n.number);  

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
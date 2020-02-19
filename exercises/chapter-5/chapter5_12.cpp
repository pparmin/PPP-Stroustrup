/* Exercise 12 & 13: Bulls & Cows

Description: 
Implement a little guessing game called "Bulls and Cows". The program has a vector of four different integers
in the range 0 to 9 (e.g., 1234 but not 1122) and it's the user's task to discover those numbers by repeated
guesses. Say the number to be guessed is 1234 and the user guesses 1359; the response should be "1 bull and 1
cow" because the user got one digit right and in the right position and one digit right but in the wrong position.
The guessing continues until the user gets four bulls, that is, has the four digits correct and in the correct order.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void error(string s)
{
  throw runtime_error(s);
}

// splits the input string and adds them to a vector for later comparison
vector<int> splitIntoDigits(int number)
{
  if (number > 9999 || number < 100) {
    error("Erroneous input.");
  }

  vector<int> results(4);
  results[0] = number / 1000 % 10;
  results[1] = number / 100 % 10;
  results[2] = number / 10 % 10;
  results[3] = number % 10;

  return results;
}

void show(vector<int> numbers, vector<int> guesses)
{
  for (int number : numbers)
  {
    cout << "orig vec: " << number << endl;
  }

  for (int number : guesses)
  {
    cout << "guesses vec: " << number << endl;
  }
}

int main()
{
  try
  {
    vector<int> numbers = {1, 2, 3, 4};
    vector<int> guesses;
    int guess = 0;
    int bulls = 0;
    int cows = 0;
    int ng;
    int it = 0;
    cout << "Please enter your first guess: \n";
    //cin >> guess;

    while (cin >> guess)
    {
      if (guess > 9999)
        error("Guesses can only range from 0 - 9.");

      guesses = splitIntoDigits(guess);
      show(numbers, guesses);

      for (int i = 0; i < numbers.size(); i++)
      {
        for (int j = 0; j < guesses.size(); j++)
        {
          // checks for the same position within the array in order to check
          // whether an entry is a bull
          if (guesses[j] == numbers[i] && j == i)
          {
            bulls++;
            cout << "Found a bull!\n";
          }
          else if (guesses[j] == numbers[i] && j != i)
          {
            cows++;
            cout << "Found a cow!\n";
          }
        }
      }

      cout << bulls << " Bulls and " << cows << " cows.\n";

      if (bulls == 4) {
        cout << "You guessed all numbers correctly. Congratulations!\n";
        return 0;
      } else {
        bulls = 0;
        cows = 0;
        cout << "You haven't found all 4 bulls yet. Please try with a new guess. \n";
      }
    }
    return 0;
  }
  catch (exception &e)
  {
    cerr << "Runtime Error: " << e.what() << endl;
    return 1;
  }
}
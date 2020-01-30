#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/* Exercise 4 - Number guessing game

Description:
Write a program to play a numbers guessing game. The user thinks of a number between 1 
and 100 and your program asks questions to figure out what the number is. Your program
should be able to identify the number after asking no more than seven questions. 
 */

int counter = 0;
int lower = 1;
int upper = 100;

// calculates the median value of the range to be used as new guess
int calc_median(int lower, int upper) 
{
  int sum = 0;
  int range = upper + lower;
  int result;

  return range / 2;
}


// Recursively checks whether the guess and number equal each other. If not, 
// it will adjust the upper/lower range 
void is_number(int guess, int number) 
{
  int new_guess;

  cout << "Chosen number: " << number << endl;
  cout << "Is the number: " << guess << "?\n";

  if (guess == number) {
    cout << "Found the number! Number is: " << guess << endl;
    cout << "It took " << counter << " guesses.\n";

  } else if (guess < number) {
    lower = guess;
    new_guess = calc_median(lower, upper);
    counter++;
    cout << "Guess too small\n";
    cout << "new guess: " << new_guess << endl;

    if (counter == 7) {
      return;
    }
    return is_number(new_guess, number); 

  } else if (guess > number) {
    upper = guess;
    new_guess = calc_median(lower, upper);
    counter++;
    cout << "Guess too big\n";
    cout << "new guess: " << new_guess << endl;

    if (counter > 7) {
      cout << "It took too many guesses.\n";
      return;
    }
    return is_number(new_guess, number);
  } 
}

int main() 
{
  int number;
  int guess = 50;
  int median = 0;
  int sum = 0;


  int counter = 0;

  cout << "Please select a number between 1 - 100: " << endl;
  cin >> number;

  if (number > 100) {
    cout << "Please only select numbers between 1 - 100.\n";
    return 0;
  }

  is_number(guess, number);
  return 0;
}
/* Exercise 13 & 14: Sieve of Erastothenes

Description:
Create a program to find all the prime numbers between 1 and 100. There is a classic method for doing this, called the 
"Sieve of Erastothenes". If you don't know that method, get on the web and look it up. Write your program using this 
method. 

The "Sieve of Erastothenes" is an ancient method for finding prime numbers in a specific range. Basically, one makes
a list of all numbers within that range and then iteratively removes all multiples of each prime until there's no 
multiples left. For more information, see here: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes. I haven't yet 
figured out a recursive approach to this, which results in the current program being a bit less elegant, since I have
to manually make the calls. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

vector<int> removeNumber(vector<int> numbers, int number) 
{
/*if (numbers[0] > 7) {
    return numbers;
  } else if (numbers[0] >= 2 && numbers[0] < 7) {
    return removeNumber(numbers)
  }*/
  for (int i = 0; i < numbers.size(); i++) {
    if (numbers[i] % number == 0 && numbers[i] != number) {
      numbers.erase(numbers.begin() + i);
    }
  }
  return numbers;
}

int main()
{
  vector<int> numbers;
  int max {0};

  cout << "Please give a maximum number to calculate the end of the range of numbers: \n";
  cin >> max;
  
  // creates an array of numbers from 100 - max
  for (int i = 2; i <= max; i++) {
    numbers.push_back(i);
  }

  // removes the numbers step by step. So far this only works correctly from 2 - 100
  numbers = removeNumber(numbers, 2);
  numbers = removeNumber(numbers, 3);
  numbers = removeNumber(numbers, 5);
  numbers = removeNumber(numbers, 7);

  cout << "Primes: \n";
  for (int value : numbers) {
    cout << "val: " << value << endl;
  }
  return 0;

}
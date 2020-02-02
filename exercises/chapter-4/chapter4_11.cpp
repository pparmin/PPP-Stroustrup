/* Exercise 11 & 12: Find all prime numbers in a range

Description:
Create a program to find all the prime numbers between 1 and 100. One way to do this is to write
a function that will check if a number is prime using a vector of primes in order. Then write a 
loop that goes from 1 to 100, checks each number to see if it is a prime, and stores each prime
found in a vector. Write another loop that lists all the primes you found.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stdlib.h>
using namespace std;

int main()
{
  vector<int> primes;
  int max;

  cout << "Please give the maximum number until you want the prime numbers to be checked (from 2 - number): \n";
  cin >> max;

  cout << "End of range: " << max << endl;

  for (int i = 2; i <= max; i++) {
    int range {0};
    int non_divisible_numbers {0};
    //cout << "Number: " << i << endl;
    // second loop goes over the range - 1
    for (int j = 2; j < i; j++) {
      range++;
      if (i % j != 0) {
        non_divisible_numbers++;
        //cout << "p: " << j << endl;
      }
    }
    //cout << "Range: " << range << endl;
    //cout << "Non divisible numbers: " << non_divisible_numbers << endl;

    // If the range - 1 equals the amount of non divisible numbers it needs to be a prime number
    if (range == non_divisible_numbers) {
      primes.push_back(i);
      cout << "Prime: " << i << " added to vector.\n";
    }
  } 
  cout << "Primes: \n";
  for (int prime : primes) {
    cout << prime << endl;
  }
  /*cout << "Primes: \n";
  for (int i = 0; i < primes.size(); i++) {
    cout << primes[i] << endl;
  }*/
  return 0;
}
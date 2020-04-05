/* Exercise 10: Permutations and Combinations

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void error(string s) 
{
  throw runtime_error(s);
}

int factorial(int n)
{
    if (n == 0)
      return 1;

    int result = n;
    for (int i = n - 1; i > 0; i--) {
        result *= i;
    }
    return result;
}

int permutations(int a, int b)
{
  if (b > a) 
    error("There can not be more variations than total numbers in a permutation");
  
  int t = a - b;
  unsigned long long int result_one = factorial(a);
  unsigned long long int result_two = factorial(t);


  unsigned long long int result = (factorial(a)) / (factorial(t));
  cout << "result one: " << result_one << " result two: " << result_two << endl;
  cout << "result of permutations: " << result << endl;
}

int combinations(int a, int b)
{

  unsigned long long int result_one = permutations(a, b);
  unsigned long long int result_two = factorial(b);
  cout << "Result one in C: " << result_one << endl; 
  cout << "Result two in C: " << result_two << endl; 

  if (result_one < result_two) 
    error("The second number is larger than first (combinations)");
  unsigned long long int result = result_one / result_two;
  cout << "Result of combinations: " << result << endl;
}

int main()
{
  try
  {
    int a, b;
    char type;
    unsigned long long int result;
    cout << "Please enter two numbers and a character as indication whether you want to calculate "
         << "permutations or combinations ('c' or 'p'). Currently only values up to 10 are allowed: " << endl;

    while (cin >> a >> b >> type)
    {
      if (type == 'p') 
        permutations(a, b);
      else if (type == 'c')
        combinations(a, b);

      else 
        error("Please enter a proper type (c or p).");
    }
  }
  catch(exception &e) 
  {
    cerr << "Runtime error: " << e.what() << endl;
  }
}
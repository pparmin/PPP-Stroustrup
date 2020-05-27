/* Exercise 03 & 04 & 05 & 06: Fibonacci, print, reverse and swap, also for strings  */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void error(string s)
{
    throw runtime_error(s);
}

void swap(int& i1, int& i2) 
{
  int temp = i1;
  i1 = i2;
  i2 = temp;
}

void str_swap(string& s1, string& s2)
{
  string temp = s1;
  s1 = s2;
  s2 = temp;
}

vector<int> reverse(vector<int> v) 
{
  vector<int> reversed; 
  for (int i = v.size() - 1 ; i >= 0 ; i--) {
    reversed.push_back(v[i]);
  }
  return reversed;
}

void reverse_two(vector<int>& v) 
{
  for (int i = 0; i < v.size()/2; i++) {
    swap(v[i], v[v.size()-1-i]);
  }
}

vector<string> str_reverse(vector<string> str) 
{
  vector<string> reversed;
  for (int i = str.size()-1; i >= 0; i--) {
    reversed.push_back(str[i]);
  }
  return reversed;
}

void str_reverse_two(vector<string>& str)
{
  for (int i = 0; i < str.size()/2; i++) {
    str_swap(str[i], str[str.size()-1-i]);
  }
}

string print(const char* label, vector<int>& numbers) 
{
  string r;
  cout << label;
  for (int& n : numbers) {
    r += to_string(n) + " ";
  }
  return r;
}

string str_print(const char* label, vector<string>& words) 
{
  string r;
  cout << label;
  for (string& s : words) {
    r += s + " ";
  }
  return r;
}

vector<int> fibonacci(int x, int y, vector<int>& v, int n) 
{
  if (n > 45) {
    error("fibonacci(): number of iterations too large");
  } else if (n < 1) {
    error("fibonacci(): there must be at least one number in the series");
  }
  v.push_back(x);
  v.push_back(y);
  int new_number;
  for (int i = 2; i < n; i++) {
    new_number = v[i - 1] + v[i - 2];
    v.push_back(new_number);
  }
  return v;
}

int main()
{
  try {
    vector<int> empty_v;
    vector<int> empty_v_two;
    vector<string> words = { "one", "two", "three", "four", "five" };
    vector<int> numbers = fibonacci(1, 1, empty_v, 8);
    vector<int> reversed = reverse(numbers);
    cout << "NUMBERS" << endl;
    cout << print("Fibonacci numbers: ", numbers) << endl;
    cout << print("Reversed numbers: ", reversed) << endl;

    vector<int> numbers_two = fibonacci(1, 1, empty_v_two, 9);
    cout << print("Numbers two: ", numbers_two) << endl;
    reverse_two(numbers_two);
    cout << print("Reversed two: ", numbers_two) << endl;
    
    cout << "STRINGS" << endl;
    cout << str_print("Original word vector: ", words) << endl;
    vector<string> r_words = str_reverse(words);
    cout << str_print("New word vector reversed: ", r_words) << endl;
    str_reverse_two(words);
    cout << str_print("Swapped vector: ", words) << endl;

    return 0;
  } 
  catch(exception & e) {
    cerr << "error: " << e.what() << endl;
    return 1;
  }
}
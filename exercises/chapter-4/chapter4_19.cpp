/* Name-value pairs

Description:
Write a program where you first enter a set of name-and-value pairs, such as "Joe 17". For each pair, add the name to a vector called
names and the number to a vector called scores. Terminate input with "NoName 0"
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main()
{
  vector<string> names;
  vector<int> scores; 
  string name;
  int score;

  cout << "Please enter a name and a score: (terminate with \"NoName 0\" \n";

  while(cin >> name >> score) {
    // check whether name already exists in the loop
    for (int i = 0; i < names.size(); i++) {
      if (name == names[i]) {
        cout << "ERROR: Name already exists!\n";
        return 0;
      }
    }

    if (name == "NoName" && score == 0) {
      break;
    }
    
    names.push_back(name);
    scores.push_back(score);

  }
  for (int i = 0; i < names.size(); i++) {
    cout << "Name: " << names[i] << " Score: " << scores[i] << endl;
  }

  return 0;
}
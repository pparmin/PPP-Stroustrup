/* Exercise 08: Bulls and Cows Remake

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void error(string s) 
{
  throw runtime_error(s);
}

vector<string> splitIntoChars(string word) 
{
  vector<string> letters(4); 
  for (int i = 0; i < letters.size(); i++) {
    letters[i] = word[i];
  }
  // letters[0] = word[0];
  // letters[1] = word[1];
  // letters[2] = word[2];
  // letters[3] = word[3];

  return letters;
}

void show(vector<string> letters, vector<string> guesses)
{
  for (string letter : letters)
  {
    cout << "orig vec: " << letter << endl;
  }

  for (string letter : guesses)
  {
    cout << "guesses vec: " << letter << endl;
  }
}

int main() 
{
  try 
  {
    vector<string> letters = { "a", "b", "c", "d" };
    vector<string> guesses;
    string word;
    int bulls = 0;
    int cows = 0;

    while(cin >> word) {
      if (word.size() > 4) error("Maximum of 4 letters allowed.");

      guesses = splitIntoChars(word);
      show(letters, guesses);

      for (int i = 0; i < guesses.size(); i++) {
        for (int j = 0; j < letters.size(); j++) {
          if (letters[j] == guesses[i] && j == i) 
          {
            bulls++;
            cout << "Found a bull!\n";
          }
        
          else if (letters[j] == guesses[i] && j != i) {
            cows++;
            cout << "Found a cow!" << endl;
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
    cerr << "Runtime error: " << e.what() << endl;
    return -1;
  }
 
}
/* Exercise 10: Rock Paper Scissors 

Description:
Write a program that plays the game "Rock, Paper, Scissors".
Use a switch-statement to solve this exercise. Also, the machine 
should give random answers. Real randomness is too hard to provide
just now, so just build a vector with a sequence of values to be 
used as the next value. 

FOR README: 
Definitely one of my favourite exercises in this chapter was the
Rock, Paper, Scissors game. That is mostly due to the fact that I
already made a browser based version of this simple game. It was 
interesting to compare both approaches (Javascript & C++). 
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stdlib.h>
using namespace std;

// This function takes care of the nitty gritty. It compares both selections
// and creates the wished-for output 
void playRound(string userSelection, string computerSelection) 
{
  if (userSelection == "rock") {
    if (computerSelection == "paper") {
      cout << "The computer chose paper. Paper beats rock. You lost!\n";

    } else if (computerSelection == "scissors") {
      cout << "The computer chose scissors. Rock beats scissors. You won!\n";

    } else if (computerSelection == userSelection) {
      cout << "You both chose " << userSelection << ". It's a draw!\n";
    } 

  } else if (userSelection == "paper") {
    if (computerSelection == "scissors") {
      cout << "The computer chose scissors. Scissors beat paper. You lost!\n";

    } else if (computerSelection == "rock") {
      cout << "The computer chose rock. Paper beats rock. You won!\n";

    } else if (computerSelection == userSelection) {
      cout << "You both chose " << userSelection << ". It's a draw!\n";
    } 

  } else if (userSelection == "scissors") {
    if (computerSelection == "rock") {
      cout << "The computer chose rock. Rock beats scissors. You lost!\n";

    } else if (computerSelection == "paper") {
      cout << "The computer chose paper. Scissors beat paper. You won!\n";

    } else if (computerSelection == userSelection) {
      cout << "You both chose " << userSelection << ". It's a draw!\n";
    }

  } else {
    cout << "It seems like you have made an incorrect entry.\n";
  }
}
// Based on the user input find the computer's choice
string computerPlay(vector<string>options) 
{
  int number;

  cout << "Please choose a number between 1 - 3" 
       << " to determine the computer's weapon:\n";
  cin >> number;
  switch(number) {
    case 1: 
      return options[0];

    case 2: 
      return options[1];

    case 3: 
      return options[2];
    
    default:
      cout << "Please select a number in range.\n";
      return computerPlay(options);
  }
}

int main()
{
  vector<string>options {"rock", "paper", "scissors"};
  string userSelection; 
  string userSelection_lc = "";

  cout << "Welcome to Rock, Paper, Scissors. In order to play" 
       << " against the computer please pick your weapon of choice: \n";
  while (cin >> userSelection) {
    string computerSelection;
    for (char letter : userSelection) {

      // converts input into lowercase for each letter if letter
      // is Uppercase. (This approach both shows how to do this
      // with the STL and by directly changing the ASCII value)
      if (isupper(int(letter))) {
        //letter = int(letter) + 32;
        letter = tolower(letter);
        userSelection_lc += letter;
      } else {
      userSelection_lc += letter;
      }
    }
    computerSelection = computerPlay(options);
    playRound(userSelection_lc, computerSelection);

    // reset lower case version of userSelection to be used again
    userSelection_lc = "";
  }

  return 0;
}
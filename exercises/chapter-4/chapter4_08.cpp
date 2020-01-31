/* Exercise 8: Grains of Rice

Description: 
There is an old story that the emperor wanted to thank the inventor of the game of
 chess and asked the inventor to name his reward. The inventor asked for one grain
of rice for the first square, 2 for the second, 4 for the third, and so on. Write a
program to calculate how many squares are required to give the inventor at least 1000
grains of rice, at least 1.000.000 grains, etc. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() 
{
  int currentSquare = 0;
  int currentGrains = 0;
  int totalGrains = 0;

  int sqForThousand = 0;
  int sqForMillion = 0;
  int sqForBillion = 0;

  for (int square = 1; square <= 31; ++square) {
    if (square == 1) {
      currentGrains = 1;
      totalGrains += currentGrains;
    } else {
      currentGrains *= 2;
      totalGrains += currentGrains;
    }
    
    cout << "grains: " << currentGrains << " at square: " << square << endl;
    cout << "total grains: " << totalGrains << endl;

    if (totalGrains >= 1000 && totalGrains <= 2000) {
      sqForThousand = square;
      cout << "You just reached 1000 grains after " << square << " squares\n";
    } else if (totalGrains >= 1000000 && totalGrains <= 2000000) {
      sqForMillion = square;
      cout << "You just reached 1.000.000 grains after " << square << " squares\n";
    } else if (totalGrains >= 1000000000 && totalGrains <= 2000000000) {
      sqForBillion = square;
      cout << "You just reached 1.000.000.000 grains after " << square << " squares\n";
    }
  }
}
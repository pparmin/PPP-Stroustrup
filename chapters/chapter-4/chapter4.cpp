#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

inline void keep_window_open() { char ch; cin>>ch; }

/*Convertor - with If conditional 

int main() 
{
  constexpr double yen_per_dollar = 110.13;
  constexpr double krone_per_dollar = 8.91;
  constexpr double pound_per_dollar = 0.77;

  char currency = ' ';
  double amount = 0;

  cout << "Please enter an amount and a currency for conversion: \n";
  cin >> amount >> currency;

  if (currency == 'y') {
    cout << "Original amount in Yen: " << amount << " Conversion to Dollar: " 
         << amount / yen_per_dollar << endl;
  } else if (currency == 'k') {
    cout << "Original amount in Kronen: " << amount << " Conversion to Dollar: " 
         << amount / krone_per_dollar << endl;   
  } else if (currency == 'p') {
    cout << "Original amount in Pounds: " << amount << " Conversion to Dollar: " 
         << amount / pound_per_dollar << endl;
  } else {
    cout << "Sorry. Currency not found!\n";
  }
}*/


/*Convertor - with switch conditional  
int main() 
{
  constexpr double yen_per_dollar = 110.13;
  constexpr double krone_per_dollar = 8.91;
  constexpr double pound_per_dollar = 0.77;

  char currency = ' ';
  double amount = 0;

  cout << "Please enter an amount and a currency for conversion: \n";
  cin >> amount >> currency;

  switch (currency) {
    case 'y':
      cout << "Original amount in Yen: " << amount << " Conversion to Dollar: " 
           << amount / yen_per_dollar << endl;
      break;
    
    case 'k': 
      cout << "Original amount in Kronen: " << amount << " Conversion to Dollar: " 
           << amount / yen_per_dollar << endl;
      break;

    case 'p':
      cout << "Original amount in Pounds: " << amount << " Conversion to Dollar: " 
           << amount / yen_per_dollar << endl;
      break;

    default:
      cout << "Sorry. Currency not found!\n";
      break;
  }  
}*/

/* while loop 

int main() 
{
  int i = 97;
  while (i <= 122) {
    cout << char(i) << '\t' << i << endl;
    ++i;
  }
}*/

/* for loop 

int square(int number) 
{
  int result = 0;
  for (int i = 0; i < number; i++) {
    result += number;
  }

  return result;
}

int main() 
{
  cout << square(5) << endl;
    for (int i = 97; i <= 122; i++) {
    cout << char(i) << '\t' << i << endl;
  }
}*/

/* --- VECTORS --- */

int main()
{
  vector<string> disliked = {"Broccoli", "Carrot", "Apple", "Mango"};
  vector<string> words;

  for (string word; cin >> word; ) {
    words.push_back(word);
  }

  // check whether input appears in disliked and censor it if true
  for (string word : words) {
    if (std::find(disliked.begin(), disliked.end(), word) != disliked.end()) {
      cout << "BLEEP" << endl;
    } else {
      cout << word << endl;
    }
  }
}


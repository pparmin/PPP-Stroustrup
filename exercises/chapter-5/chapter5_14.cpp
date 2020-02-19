/* Exercise 14: Day-value pairs

Description: 
Read (day-of-the-week, value) pairs from standard input. Collect all the values for each day of the week in a vector<int>. Write out the values
of the seven day-of-the-week vectors. Print out the sum of the values in each vector. Ignore illegal days of the week, such as "Funday", but 
accept common synonym such as "Mon" and "monday". Write out the number of rejected values.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void error(string s) {
    throw runtime_error(s);
}

// function to convert the initial string to lowercase 
string convertToLower (string s) 
{
  string sToLower;
  for(int i = 0; i < s.size(); ++i) {
    //cout << "char: " << tolower(int(s[i])) << endl;
    sToLower += tolower(int(s[i]));
  }

  return sToLower;
}

// check whether weekday exists within vector
bool nameInVector(vector<string> names, string weekday) 
{
  for (string entry : names) {
    if (entry == weekday) {
      return true;
    }
  }
  return false;
}

// Makes a sum of all values within a target vector
int sumValues(vector<int> values) {
    int sum = 0;
    for (int i = 0; i < values.size(); i++) {
        sum += values[i];
    }
    return sum;
}

int main()
{
    try {
        vector<int> monday, tuesday, wednesday, thursday, friday, saturday, sunday;
        vector<int> rejectedValues;
        vector<string> acceptedNames = { "monday", "tuesday", "wednesday", "thursday", "friday",
        "saturday", "sunday", "mon", "tue", "wed", "thu", "fri", "sat", "sun" };
        string weekday;
        int sMon = 0;
        int sTue = 0;
        int sWed = 0;
        int sThu = 0;
        int sFri = 0;
        int sSat = 0;
        int sSun = 0;
        int value;
        int sum = 0;

        cout << "Please input a day of the week and a corresponding value: \n";

        while (cin >> weekday >> value) {
            weekday = convertToLower(weekday);
            if (nameInVector(acceptedNames, weekday)) {
                if (weekday == "monday" || weekday == "mon") {
                    monday.push_back(value);
                    sMon = sumValues(monday);
                }
                else if (weekday == "tuesday" || weekday == "tue") {
                    tuesday.push_back(value);
                    sTue = sumValues(tuesday);
                }
                else if (weekday == "wednesday" || weekday == "wed") {
                    wednesday.push_back(value);
                    sWed = sumValues(wednesday);
                }
                else if (weekday == "thursday" || weekday == "thu") {
                    thursday.push_back(value);
                    sThu = sumValues(thursday);
                }
                else if (weekday == "friday" || weekday == "fri") {
                    friday.push_back(value);
                    sFri = sumValues(friday);
                }
                else if (weekday == "saturday" || weekday == "sat") {
                    saturday.push_back(value);
                    sSat = sumValues(saturday);
                }
                else if (weekday == "sunday" || weekday == "sun") {
                    sunday.push_back(value);
                    sSun = sumValues(sunday);
                }
            }
            else if (!nameInVector(acceptedNames, weekday)) {
                rejectedValues.push_back(value);
                cout << "Day doesn't exist." << endl;
            }
        }
        cout << "Rejected Values: ";
        for (int value : rejectedValues) {
            cout << value << " ";
        }
        cout << endl;
        cout << "Number of rejected values: " << rejectedValues.size() << endl;
        cout << "Sum for Monday: " << sMon << endl;
        cout << "Sum for Tuesday: " << sTue << endl;
        cout << "Sum for Wednesday: " << sWed << endl;
        cout << "Sum for Thursday: " << sThu << endl;
        cout << "Sum for Friday: " << sFri << endl;
        cout << "Sum for Saturday: " << sSat << endl;
        cout << "Sum for Sunday: " << sSun << endl;
        return 0;
    }
    catch (exception & e) {
        cerr << "Runtime Error: " << e.what() << endl;
        return 1;
    }
}
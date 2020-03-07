/* Exercise 04: Reworked Name-value pairs

Description: Define a class Name_value that holds a string and a value. Rework exercise 19 in Chapter 4 
to use a vector<Name_value> instead of two vectors.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void error(string s)
{
    throw runtime_error(s);
}

class Name_value {
public: 
    string name;
    int value;
    Name_value(string name, int val)
        :name(name), value(val) { }

};

class Nv_stream {
public:
    Name_value get();                       // read a name and a value from cin
    void print(vector<Name_value> nvs);     // print out entries within the vector
    bool exists(vector<Name_value> names, string name);
    int make_sum(vector<Name_value> names);

/*private:
    bool exists = false;
    vector<string> names;*/
};

Nv_stream nvStream;                 //  initiate to provide properties name and value


// --------------------------------------------------------------------------------------------

Name_value Nv_stream::get()
{
    cout << "Please enter a name and a score: (terminate with \"NoName 0\")" << endl;
    string n;
    int v;
    cin >> n >> v;                  // read a string and an int from input
    return Name_value(n, v);
}

void Nv_stream::print(vector<Name_value> nvs)
{
    cout << "Name-value pairs: " << endl;
    for (Name_value entry : nvs) {
        cout << entry.name << ": " << entry.value << endl;
    }
}

bool Nv_stream::exists(vector<Name_value> names, string name)
{
    for (Name_value entry : names) {
        if (entry.name == name)
            return true;
    }
    return false;
}

int Nv_stream::make_sum(vector<Name_value> names)
{
    int sum = 0;
    for (Name_value entry : names) {
        sum += entry.value;
    }
    return sum;
}

// --------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------

int main()
{
    try {
        vector<Name_value> names_values;
        string name;
        int sum;
        bool exists = false;

        while (cin) {
            Name_value nv = nvStream.get();
            if (nv.name == "NoName" && nv.value == 0) break;    // break when exit condition is encountered
            cout << "name: " << nv.name << " value: " << nv.value << endl;

            exists = nvStream.exists(names_values, nv.name);
            if (!exists)
                names_values.push_back(nv);
            else
                error("Name already exists.");
        }
        nvStream.print(names_values);
        sum = nvStream.make_sum(names_values);
        cout << "Sum of all values: " << sum << endl;
        return 0;
    }
    catch (exception & e)
    {
        cerr << "error: " << e.what() << '\n';
        return 1;
    }
}
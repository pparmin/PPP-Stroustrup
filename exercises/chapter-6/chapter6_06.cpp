/* Exercise 04: English Grammar

Sentence
	Article Noun Verb
	Noun Verb
	Sentence Conjunction Sentence
Conjunction
	"and"
	"or"
	"but"
Article
	"the"
Noun
	"birds"
	"fish"
	"C++"
Verb
	"rules"
	"fly"
	"swim"

Description: Write a program that checks if a sentence is correct according to the "English" grammar in �6.4.1. Assume that every sentence
is terminated by a full stop (.) surrounded by whitespace.


TODO: Fix the checkOrder() function

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void error(string s)
{
	throw runtime_error(s);
}

class Word {
public: 
	char type;
	string meaning;
	Word(char type)
		:type(type), meaning("") { }
	Word(char type, string meaning)
		:type(type), meaning(meaning) { }
};

class Word_stream {
public: 
	Word get();
	Word checkType(string word);
	bool checkOrder(vector<char> types);

private:
	bool withArticle = false;
	// bool isArticle = false;
	// bool isNoun = false;
	// bool isVerb = false;
	// bool isConj = false;
};

Word_stream WS;

// checks existence of word in list and returns type of string
Word Word_stream::checkType(string word)
{
	vector<string> nouns = { "birds", "fish", "C++" };
	vector<string> verbs = { "rules", "fly", "swim" };
	vector<string> conj = { "and", "or", "but" };
	string article = "the";

	if (word == article) {
		return Word('a');
	}

	for (string entry : nouns) {
		if (entry == word) {
			return Word('n');
		}
	}

	for (string entry : verbs) {
		if (entry == word) {
			return Word('v');
		}
	}

	for (string entry : conj) {
		if (entry == word) {
			return Word('c');
		}
	}

	if (word == ".") 
	{
		return Word('.');
	}

	cout << "The word you chose could not be found within the list." << endl;
	return Word('f');
}


// checks the correct order within each sentence. In order to do so, it compares entries within a 
// vector that holds the order of the input and a vector that holds the correct order. 
bool Word_stream::checkOrder(vector<char> types)
{
	// compares order for both "Article Noun Verb" and "Noun Verb"
	vector<char> order = { 'n', 'v' };
	vector<char> order_a = { 'a', 'n', 'v' };

	int order_size = order.size();
	int order_a_size = order_a.size();
	int count = 0;

	// Is there an article in the sentence?
	for (char entry : types) {
		if (entry == 'a') 
		{
			withArticle = true;
		}
	}

	// comparison for sentences with article
	if (withArticle) 
	{
		for (char entry : types) {

			// if conjunction encountered set variables to initial values and increase counter
			if (entry == 'c') {
			count++;
			withArticle = false;
			order = { 'n', 'v' };
			order_a = { 'a', 'n', 'v' };
			}
			for (char item : order_a) {
				if (entry == item)
				{
					count++;
					order_a.erase(order_a.begin());
				}
			}
		}
	} 

	// comparison for sentences without article
	else {
		for (char entry : types) {
			// if conjunction encountered set variables to initial values and increase counter
			if (entry == 'c')
			{
				count++;
				withArticle = false;
				order = {'n', 'v'};
				order_a = {'a', 'n', 'v'};
			}
			for (char item : order) {
				if (entry == item)
				{
					count++;
					order.erase(order.begin());
				}
			}
		}
	}
	if (count == types.size()) return true;

	return false;
}

Word Word_stream::get()
{
	string word;
	cin >> word;

	if (word == ".") {
		return Word('.', word);
	}

	Word w = WS.checkType(word);
	switch (w.type) {
	case 'a': case 'n': case 'v': case 'f': case 'c':
		return Word(w.type, word);

	default:
		error("You didn't select a proper type.");

	}
}

// -------------------------------------------------------------------------------------------- // 


// -------------------------------------------------------------------------------------------- //

Word sentence() 
{
	Word w = WS.get();
	if (w.type == '.') 
	{
		return Word('.');
	} 
	return w;
}

int main()
{
	try {
		vector<char> types;
		bool correctOrder = false;
		cout << "Welcome! Please form a proper sentence out of the following words. Choose one each type:" << '\n'
			<< "Article: 'the'; Noun: 'birds, fish, C++'; Verb: 'rules, fly, swim'; Conjunction: 'and, or, but':" << '\n'
			<< "Remember: A sentence consists of either Article Noun Verb or Noun Verb or Sentence Conjunction Sentence. " << '\n' 
			<< "the program will then tell you if your sentence is OK or Not OK." << endl;
		while (cin) {
			Word w = sentence();

			// discover end of sentence
			if (w.type == '.')
				break;


			types.push_back(w.type);
		}

			correctOrder = WS.checkOrder(types);
			if (correctOrder) {
				cout << "OK" << endl;
			}
			else if (!correctOrder) {
				cout << "Not OK" << endl;
			}
		return 0;
	}
	catch (exception & e) {
		cerr << "error: " << e.what() << '\n';
		return -1;
	}
}
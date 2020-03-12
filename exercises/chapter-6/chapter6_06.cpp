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

Description: Write a program that checks if a sentence is correct according to the "English" grammar in §6.4.1. Assume that every sentence
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
	bool isArticle = false;
	bool isNoun = false;
	bool isVerb = false;
	bool isConj = false;
	/*string get();
	bool sentence(string word);
	bool compare(string word);
	//bool article(string word);
	bool noun(string word);
	bool verb(string word);
	bool conjunction(string word);
	bool existsIn(vector<string> target, string word);
private:
	bool isArticle = false;
	bool isNoun = false;
	bool isVerb = false;
	bool isConjunction = false;
	vector<string> nouns = { "birds", "fish", "c++" };
	vector<string> verbs = { "rules", "fly", "swim" };
	vector<string> conj = { "and", "or", "but" };
	string article = "the";*/
};

Word_stream WS;

// checks existence of word in list and returns type of string
Word Word_stream::checkType(string word)
{
	vector<string> nouns = { "birds", "fish", "c++" };
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

	cout << "The word you chose could not be found within the list." << endl;
	return Word('f');
}

bool Word_stream::checkOrder(vector<char> types)
{
	// compares order for both "Article Noun Verb" and "Noun Verb"
	vector<char> order = { 'a', 'n', 'v' };
	int count = 0;

	for (char entry : types) {
		for (char item : order) {
			if (entry == item) {
				count++;
				cout << "count increased " << endl;
			}
		}
	}
	cout << "count: " << count << endl;
	if (count == order.size() || count == order.size() - 1)
		return true;

	/*for (char entry : types) {
		for (char item : order_two) {
			if (entry == item)
				return true;
		}
	}*/

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
	case 'a': case 'n': case 'v': case 'c': case 'f':
		return Word(w.type, word);

	default:
		error("You didn't select a proper type.");

	}
}

// -------------------------------------------------------------------------------------------- // 


// -------------------------------------------------------------------------------------------- //

int main()
{
	try {
		vector<char> types;
		bool correctOrder = false;
		cout << "Welcome! Please form a proper sentence out of the following words. Choose one each type:" << '\n'
			<< "Article: 'the'; Noun: 'birds, fish, C++'; Verb: 'rules, fly, swim'; Conjunction: 'and, or, but':" << '\n'
			<< "Remember: A sentence consists of either Article Noun Verb or Noun Verb or Sentence Conjunction Sentence. " << endl;
		while (cin) {
			Word w = WS.get();
			cout << "w.type: " << w.type << " w.meaning: " << w.meaning << endl;

			// discover end of sentence
			if (w.type == '.')
				break;

			if (w.type == 'f') {
				cout << "Please use one of the words within the list." << endl;
			}

			types.push_back(w.type);
			/*string word = w_s.get();
			cout << "word: " << word << endl;
			if (word == ".")
				break;

			bool wordDoesExist = w_s.sentence(word);

			if (wordDoesExist) {
				cout << "OK" << endl;
			}
			else if (!wordDoesExist) {
				cout << "Not OK" << endl;
			}*/

			for (char entry : types) {
				cout << "type: " << entry << endl;
			}
			correctOrder = WS.checkOrder(types);
			if (correctOrder) {
				cout << "OK" << endl;
			}
			else if (!correctOrder) {
				cout << "Not OK" << endl;
			}
		}
			//bool isSentence = sentence();
		return 0;
	}
	catch (exception & e) {
		cerr << "error: " << e.what() << '\n';
		return -1;
	}
}
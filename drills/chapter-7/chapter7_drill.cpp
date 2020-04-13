
/*
Updated Grammar:

Expression:
	Term
	Expression "+" Term
	Expression "-" Term

Term:
	Primary
	Term "*" Primary
	Term "/" Primary
	Term "%" Primary

Primary:
	Number
	"(" Expression ")"
	"sqrt" "(" Expression ")
	"pow" "(" Expression "," Expression ")"
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

// run-time checked narrowing cast (type conversion). See ???.
template<class R, class A> R narrow_cast(const A& a)
{
	R r = R(a);
	if (A(r) != a) error(string("info loss"));
	return r;
}


inline void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

inline void keep_window_open(string s)
{
	if (s == "") return;
	cin.clear();
	cin.ignore(120, '\n');
	for (;;) {
		cout << "Please enter " << s << " to exit\n";
		string ss;
		while (cin >> ss && ss != s)
			cout << "Please enter " << s << " to exit\n";
		return;
	}
}

/*class Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n) :kind(ch), name(n) { }
};*/

class Token {
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	string name;
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
	Token(char ch, string n) :kind{ ch }, name{ n } { }
	Token(char ch, string n, double val) : kind { ch }, name { n }, value { val } { }
};

class Token_stream {
public:
	Token_stream();
	Token get();
	void unget(Token t);
	void ignore(char);
private:
	bool full;
	Token buffer;

};

Token_stream::Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}

const char let = 'L';
const char quit = 'q';
const char print = '=';
const char number = '8';
const char name = 'a';
const char square_rt = 'S';
const char _pow = 'P';
const string varKey = "let"; // declaration keyword
const string sqrtKey = "sqrt"; // sqrt keyword
const string powKey = "pow";   // pow keyword
const string quitKey = "exit"; // quit keyword



Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case print:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case ',':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	
	cin.putback(ch);
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.putback(ch);
			if (s == varKey) return Token{ let };
			if (s == sqrtKey) return Token{ square_rt };
			if (s == powKey) return Token{ _pow };
			if (s == quitKey) return Token{ quit };
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

void Token_stream::unget(Token t)
{
	if (full) error("unget() into full buffer");
	buffer = t; 
	full = true;
}

Token_stream ts;

class Variable {
public:
	string name;
	double value;
	Variable(string n, double v) :name{ n }, value{ v } { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ");
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ");
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

// add {var, val} to var_table
double define_name(string var, double val)
{
	if (is_declared(var)) error("variable declared twice");
	names.push_back(Variable{ var, val });
	return val;
}


double expression();

// deal with numbers, parentheses, names, sqrt, pow
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("'(' expected");
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case square_rt:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected: Please insert an expression to sqrt()");
		double expr = expression();
		if (expr < 0) error("Number under root can not be less than 0");
		double d = sqrt(expr);
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case _pow:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected: Please insert an expression to sqrt()");
		double d = expression();
		t = ts.get();
		if (t.kind != ',') error("',' expected: Please insert a number indicating the times of multiplication");
		double d2 = narrow_cast<int>(expression());
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return pow(d, d2);
	}
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0) error("%: divide by zero");
			left = fmod(left, d);
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
// assume we have seen "let"
// handle: name = expression
// declare a variable called "name" with the initial value "expression"
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error("name declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ");
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (cin) 
		try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (exception & e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
try {
	define_name("k", 1000);
	calculate();
	return 0;
}
catch (exception & e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}

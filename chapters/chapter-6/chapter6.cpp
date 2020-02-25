#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void error(string s)
{
	throw(runtime_error(s));
}

class Token {
	public:
		char kind;
		double value;
};
Token t; 

Token get_token()
{
}

double expression()
{
	double left = term();
	Token t = get_token();
	while (true) {
		switch (t.kind) {
		case'+':
			left += term();
			t = get_token();
			break;

		case'-':
			double d = term();
			left -= d;
			t = get_token();
			break;

		default:
			return left;
		}
	}
}

double term()
{
	double left = primary();
	Token t = get_token();
	while (true) {
		switch (t.kind) {
		case'*':
			left *= primary();
			t = get_token();
			break;

		case'/': 
		{
			double d = primary();
			if (d == 0) error("Divide by zero");
			left /= d;
			t = get_token();
			break;
		}
		default:
			return left;
		}
	}
}

double primary()
{

}

int main()
{
	cout << "Please enter expression (we can handle + and -): ";
	int lval = 0;
	int rval;
	char op;
	int res;
	cin >> lval >> op >> rval;			// read somethig like 1 + 3

	if (op == '+')
		res = lval + rval;
	else if (op == '-')
		res = lval - rval;

	cout << "Result: " << res << endl;
	return 0;
}
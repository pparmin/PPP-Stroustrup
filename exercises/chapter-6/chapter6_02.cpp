/* Exercises 2 & 3: Improved calculator (with factorial)

Updated Expression Grammar: 
    Expression
        Term
        Expression "+" Term
        Expression "-" Term
    Term
        Factorial
        Term "*" Factorial
        Term "/" Factorial
    Factorial
        Primary
        Factorial"!"
    Primary
        Number
        "(" Expression ")"
    Number
        Floating-point literal value


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

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        full = false; // remove token from buffer
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '{': case '}': case '(': case ')': case '+': case '-': case '*': case '/': case '!':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('8', val);   // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()
double primary();       // declaration so factorial can call primary();

//------------------------------------------------------------------------------

// calculate factorial
int calc_factorial(int n)
{
    if (n == 0)
        return 1;

    //double left = primary();
    //Token t = ts.get();

    int result = n;
    for (int i = n - 1; i > 0; i--) {
        result *= i;
    }
    return result;
}

// deal with factorial or else make a primary
double factorial()
{
    double left = primary();
    Token t = ts.get();
    while (true)
    {
        if (t.kind == '!')
        {
            double result = 0;
            cout << "Value: " << int(round(left)) << endl;
            result = calc_factorial(int(round(left)));
            return result;
        }
        else
        {
            ts.putback(t);
            return left;
        }
    }
}

// deal with numbers and parentheses and factorial
double primary()
{
    Token t = ts.get();
    cout << "t.kind: " << t.kind << endl;
    switch (t.kind) {
    case '(':               // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '{':              // handle '{' expression '}'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
        return d;
    }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = factorial();   // read and evaluate a factorial or primary
    Token t = ts.get();        // & check whether it is followed by +/- 

    while (true) {
        switch (t.kind) {
        case '*':
            left *= factorial();
            t = ts.get();
            break;
        case '/':
        {
            double d = factorial();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // & check whether it is followed by +/- (get the next token from token stream)

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
{
    try
    {
        cout << "Welcome to our simple calculator. Please enter expressions "
            << "using floating-point numbers. The following operators are "
            << '\n' << "available: + - / *. To print the result add a '=' after your "
            << "calculation." << '\n' << "To exit the program type 'x'. Have fun calculating!"
            << endl;

        while (cin) {
            double val = expression();
            Token t = ts.get();

            if (t.kind == 'x') 
                break;                // 'x' for quit
            if (t.kind == '=')        // '=' for "print now"
            {
                cout << "=" << val << '\n';
            }
            else
                ts.putback(t);

            //cout << "Val at the end of each iteration: " << val << endl;
        }
        //keep_window_open();
        return 1;
    }
    catch (exception & e) {
        cerr << "error: " << e.what() << '\n';
        //keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        //keep_window_open();
        return 2;
    }
}

//------------------------------------------------------------------------------
/* 
CODE FOR CHAPTER 07: Improved version of the calculator

Updated Grammar:

Calculation: 
    Statement
    Print
    Quit
    Calculation Statement

Statement:
    Declaration
    Expression

Declaration:
    "let" Name "=" Expression      

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

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;
    Token() : kind{ 0 } { }   // make a Token from a char
    Token(char ch) : kind{ ch } { }    // make a Token from a char and a double
    Token(char ch, double val) : kind{ ch }, value{ val } { }
    Token(char ch, string n) :kind{ch}, name{n} { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);
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

void Token_stream::ignore(char c)
{
    // first check buffer
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;
    
    // now search input:
    char ch = 0;
    while (cin >> ch)
        if (ch == c) return;
}


//------------------------------------------------------------------------------

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

bool isunderscore(char c)
{
    if (c == '_') return true;
    return false;
}

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        full = false; // remove token from buffer
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case print:   
    case '{': 
    case '}': 
    case '(': 
    case ')': 
    case '+': 
    case '-': 
    case '*': 
    case '/': 
    case '!': 
    case '%':
    case ',':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);             // put digit back into the input stream
        double val;
        cin >> val;                  // read a floating-point number
        return Token(number, val);   // let '8' represent "a number"
    }
    default:
        if (isalpha(ch) || isunderscore(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
            cin.putback(ch);
            if (s == varKey) return Token{ let }; // declaration keyword
            if (s == sqrtKey) return Token{ square_rt };
            if (s == powKey) return Token{ _pow };
            if (s == quitKey) return Token{ quit };
            return Token{ name, s };
        }
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;         // provides get() and putback() 

//------------------------------------------------------------------------------

class Variable {
public:
    string name;
    double value;
};

vector<Variable> var_table;

// is var already in var_table?
bool is_declared(string var)
{
    for (const Variable& v : var_table) {
        if (v.name == var) return true;
    }
    return false;
}

// add {var, val} to var_table
double define_name(string var, double val)
{
    if (is_declared(var)) error("variable declared twice");
    var_table.push_back(Variable{ var, val });
    return val;
}

//------------------------------------------------------------------------------


double expression();    // declaration so that primary() can call expression()
double primary();       // declaration so factorial can call primary();

//------------------------------------------------------------------------------

// return the value of the Variable named s
double get_value(string s)
{
    for (const Variable& v : var_table) {
        if (v.name == s) return v.value;
    }
    error("get: undefined variable");
}

// set the value of variable named s to d
void set_value(string s, double d)
{
    for (Variable& v : var_table) {
        if (v.name == s)
        {
            v.value = d;
            return;
        }
    }
    error("set: undefined variable");
}

void clean_up_mess()
{
    ts.ignore(print);
}

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

double declaration()
// assume we have seen "let"
// handle: name = expression
// declare a variable called "name" with the initial value "expression"
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of var_name");

    double d = expression();
    define_name(var_name, d);
    return d;
}

// deal with numbers, names, parentheses, factorial, pow, sqrt
double primary()
{
    Token t = ts.get();
    //cout << "t.kind: " << t.kind << endl;
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

    case '-':
        return - primary();

    case '+':
        return primary();

    case name:
        return get_value(t.name);

    case number:         
        return t.value;  

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
        case '%':
        {
            double d = primary();
            if (d == 0) error("%: divide by zero");
            left = fmod(left, d);
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

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------

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
        ts.putback(t);
        cout << result << statement() << '\n';
    }
    catch (exception & e) {
        cerr << e.what() << '\n';
        clean_up_mess();
    }
}

int main()
{
    try
    {
        cout << "Welcome to our simple calculator. Please enter expressions "
            << "using floating-point numbers. The following operators are "
            << '\n' << "available: + - / *. To print the result add a '=' after your "
            << "calculation." << '\n' << "To exit the program type 'x'. Have fun calculating!"
            << endl;
        
        define_name("pi", 3.1415926535);
        define_name("e", 2.7182818284);

        calculate();
        keep_window_open();
        return 0;
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
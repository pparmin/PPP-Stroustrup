/* Exercises 01: Improved calculator

**Updated Grammar:**

Calculation:
    Statement
    Print
    Assignment
    Quit
    Calculation Statement

Statement:
    Declaration
    Constant Declaration
    Squareroot
    Power
    Logarithm
    Assignment
    Expression

Declaration:
    "let" Name "=" Expression

Constant Declaration:
    "const" Name "=" Expression

Squareroot:
    sqrt "(" "Expression ")"

Power:
    pow "(" "Expression" "," "Expression" ")"

Logarithm:
    log "(" Expression ")"

Assignment: 
    "="Name "=" Expression

Expression:
    Term
    Expression "+" Term
    Expression "-" Term

Term:
    Factorial
    Term "*" Factorial
    Term "/" Factorial

Factorial:
    Primary
    Factorial"!"

Primary:
    Number
    "(" Expression ")"

Number:
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

// run-time checked narrowing cast (type conversion)
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
    Token(char ch, string n) :kind{ ch }, name{ n } { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token_stream(istream&);
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
const char constant = 'C';
const char quit = 'q';
const char print = ';';
const char assign = '=';
const char help = 'H';
const char number = '8';
const char name = 'a';
const char square_rt = 'S';
const char _pow = 'P';
const char _log = 'G';
const string varKey = "let"; // declaration keyword
const string constKey = "const";
const string sqrtKey = "sqrt"; // sqrt keyword
const string powKey = "pow";   // pow keyword
const string logKey = "log";
const string quitKey = "exit"; // quit keyword
const string helpKey = "help";


//------------------------------------------------------------------------------

// handles names starting with underscore
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
    //cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)
    cin.get(ch);    // cin.get() does not skip whitespace
    while (isspace(ch)) {
        if (ch == '\n') return Token(print);
        cin.get(ch);
    }

    switch (ch) {
    case print:
    case assign:
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
            if (s == varKey) return Token{ let };
            if (s == constKey) return Token{ constant };
            if (s == sqrtKey) return Token{ square_rt };
            if (s == powKey) return Token{ _pow };
            if (s == logKey) return Token{ _log };
            if (s == quitKey) return Token{ quit };
            if (s == helpKey) return Token{ help }; 
            return Token{ name, s };
        }
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

//Token_stream ts;         // provides get() and putback() 

//------------------------------------------------------------------------------


class Variable {
public:
    string name;
    char type;
    double value;
};

//------------------------------------------------------------------------------

class Symbol_table {
public:
    vector<Variable> var_table;
    bool is_declared(string var);
    double declare(string var, char type, double val);
    double get_value(string s);
    void set_value(string s, double d);
};

//------------------------------------------------------------------------------

Symbol_table st;        // provides names table & member functions

//------------------------------------------------------------------------------

// is var already in var_table?
bool Symbol_table::is_declared(string var)
{
    for (const Variable& v : var_table) {
        if (v.name == var) return true;
    }
    return false;
}

// add {var, type, val} to var_table
double Symbol_table::declare(string var, char type, double val)
{
    if (is_declared(var)) error("variable declared twice");
    var_table.push_back(Variable{ var, type, val });
    return val;
}

//------------------------------------------------------------------------------


double expression(Token_stream& ts);    // declaration so that primary() can call expression()
double primary(Token_stream& ts);       // declaration so factorial can call primary();

//------------------------------------------------------------------------------

// return the value of the Variable named s
double Symbol_table::get_value(string s)
{
    for (const Variable& v : var_table) {
        if (v.name == s) return v.value;
    }
    error("get: undefined variable");
}

// set the value of variable named s to d
void Symbol_table::set_value(string s, double d)
{
    for (Variable& v : var_table) {
        if (v.name == s)
        {
            if (v.type == 'v')
            {
                v.value = d;
                return;
            }
            else
                error("set: can not change value of constant type");
        }
    }
    error("set: undefined variable");
}

void clean_up_mess(Token_stream& ts)
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
double factorial(Token_stream& ts)
{
    double left = primary(ts);
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

//------------------------------------------------------------------------------

double declaration(Token_stream& ts)
// assume we have seen "let"
// handle: name = expression
// declare a variable called "name" of the type 'variable' with the initial value "expression"
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of var_name");

    double d = expression(ts);
    st.declare(var_name, 'v', d);          // v for variable type
    return d;
}

double constDeclaration(Token_stream& ts)
// assume we have seen "const"
// handle: name = expression
// declares a variable called "name" of the type "const" with the constant value "expression"
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of var_name");

    double d = expression(ts);
    st.declare(var_name, 'c', d);
    return d;
}

double assignment(Token_stream& ts)
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in assignment");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of var_name");

    double d = expression(ts);
    st.set_value(var_name, d);
    return d;
}

double squarert(Token_stream& ts)
{
    Token t = ts.get();
    if (t.kind != '(') error("'(' expected: Please insert an expression to sqrt()");
    double expr = expression(ts);
    if (expr < 0) error("Number under root can not be less than 0");
    double d = sqrt(expr);
    t = ts.get();
    if (t.kind != ')') error("')' expected");
    return d;
}

double power(Token_stream& ts)
{
    Token t = ts.get();
    if (t.kind != '(') error("'(' expected: Please insert an expression to sqrt()");
    double d = expression(ts);
    t = ts.get();
    if (t.kind != ',') error("',' expected: Please insert a number indicating the times of multiplication");
    double d2 = narrow_cast<int>(expression(ts));
    t = ts.get();
    if (t.kind != ')') error("')' expected");
    return pow(d, d2);
}

double logarithm(Token_stream& ts)
{
    Token t = ts.get();
    if (t.kind != '(') error("'(' expected: Please insert an expression to sqrt()");
    double d = expression(ts);
    if (d < 0) error("ERROR log: number smaller than 0");
    t = ts.get();
    if (t.kind != ')') error("')' expected");
    return log(d);
}

void print_help()
{
    cout << "This calculator comes with the basic arithmetic functionality. Additionally, there are " << '\n'
        << "some extra calculations it can perform." << '\n'
        << '\n'
        << "Special Commands: " << '\n'
        << "sqrt(expression): " << "Calculate squareroot of a number." << '\n'
        << "pow(expression, n): " << "Calculate the nth-power of a number." << '\n'
        << "log(expression): " << "Calculate the natural logarithm of a number." << '\n'
        << "expression ! : " << "Calculate the factorial of a number." << '\n'
        << "help: " << "show this help message." << '\n'
        << "exit: " << "exit the program." << '\n';
}

//------------------------------------------------------------------------------

// deal with numbers and names
double primary(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':               // handle '(' expression ')'
    {
        double d = expression(ts);
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '{':              // handle '{' expression '}'
    {
        double d = expression(ts);
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
        return d;
    }

    case '-':
        return -primary(ts);

    case '+':
        return primary(ts);

    case name:
        return st.get_value(t.name);

    case number:
        return t.value;

    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term(Token_stream& ts)
{
    double left = factorial(ts);   // read and evaluate a factorial or primary
    Token t = ts.get();        // & check whether it is followed by +/- 

    while (true) {
        switch (t.kind) {
        case '*':
            left *= factorial(ts);
            t = ts.get();
            break;
        case '/':
        {
            double d = factorial(ts);
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary(ts);
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
double expression(Token_stream& ts)
{
    double left = term(ts);      // read and evaluate a Term
    Token t = ts.get();        // & check whether it is followed by +/- (get the next token from token stream)

    while (true) {
        switch (t.kind) {
        case '+':
            left += term(ts);    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term(ts);    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

// handles let, const, sqrt, pow and re-assignment
double statement(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration(ts);
    case constant:
        return constDeclaration(ts);
    case square_rt:
        return squarert(ts);
    case _pow:
        return power(ts);
    case _log:
        return logarithm(ts);
    case assign:
        return assignment(ts);
    default:
        ts.putback(t);
        return expression(ts);
    }
}

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------

const string prompt = "> ";
const string result = "= ";

void calculate()
{
    Token_stream ts;
    while (cin)
        try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t = ts.get();
        if (t.kind == help)
            print_help();
        else {
            if (t.kind == quit) return;
            ts.putback(t);
            cout << result << statement(ts) << '\n';
        }
    }
    catch (exception & e) {
        cerr << e.what() << '\n';
        clean_up_mess(ts);
    }
}

int main()
{
    try
    {
        cout << "Welcome to my calculator. Please enter expressions "
            << "using floating-point numbers. " << '\n' 
            << "To finish a statement add a ';' after your input." << '\n'
            << "To exit the program type 'exit'. Have fun calculating!"
            << endl;

        st.declare("pi", 'c', 3.1415926535);   // 'c' for constant type
        st.declare("e", 'c', 2.7182818284);

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
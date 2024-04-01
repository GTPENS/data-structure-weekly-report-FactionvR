/*
                        ALGORITMA DAN STRUKTUR DATA

NAMA : RANGGA RAISHA SYAPUTRA
NRP  : 5223600007

                        MENGONVERSIKAN INFIX KE POSTFIX
*/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

//Memeriksa apakah suatu karakter adalah operator matematika atau bukan//
bool apaOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

//Menerima sebuah string infix yang merupakan ekspresi matematika dalam bentuk infix, dan mengembalikan ekspresi tersebut dalam bentuk postfix.//
string infixkePostfix(const string& infix) {
    stack<char> stack;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            stack.push(ch);
        }
        else if (ch == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            }
        }
        else {
            while (!stack.empty() && precedence(ch) <= precedence(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixkePostfix(infix);

    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
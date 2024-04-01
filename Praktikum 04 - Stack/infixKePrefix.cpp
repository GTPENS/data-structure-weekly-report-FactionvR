/*
                        ALGORITMA DAN STRUKTUR DATA

NAMA : RANGGA RAISHA SYAPUTRA
NRP  : 5223600007

                        MENGONVERSIKAN INFIX KE PREFIX
*/

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

//Mengembalikan tingkat prioritas (presendensi) dari operator matematika. Operator + dan - memiliki prioritas 1, operator * dan / memiliki prioritas 2, operator ^ (pangkat) memiliki prioritas 3, dan operator lainnya memiliki prioritas 0.//
int presendensi(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '^') {
        return 3;
    }
    return 0;
}

string infixKePrefix(const string& infix) {
    string reversInfix = infix;
    reverse(reversInfix.begin(), reversInfix.end());

    for (int i = 0; i < reversInfix.length(); i++) {
        if (reversInfix[i] == '(') {
            reversInfix[i] = ')';
        }
        else if (reversInfix[i] == ')') {
            reversInfix[i] = '(';
        }
    }

    stack<char> stack;
    string prefix;

    for (char ch : reversInfix) {
        if (isalnum(ch)) {
            prefix += ch;
        }
        else if (ch == ')') {
            stack.push(ch);
        }
        //Jika karakter adalah kurung tutup ), karakter tersebut dimasukkan ke dalam stack.//
        else if (ch == '(') {
            while (!stack.empty() && stack.top() != ')') {
                prefix += stack.top();
                stack.pop();
            }
        //Jika karakter adalah kurung buka (, dilakukan operasi pop dari stack dan dimasukkan ke dalam prefix sampai ditemukan kurung tutup yang sesuai.//
            if (!stack.empty() && stack.top() == ')') {
                stack.pop();
            }
        }
        else {
            while (!stack.empty() && stack.top() != ')' &&
                ((ch != '^' && presendensi(ch) <= presendensi(stack.top())) ||
                    (ch == '^' && presendensi(ch) < presendensi(stack.top())))) {
                prefix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.empty()) {
        prefix += stack.top();
        stack.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string prefix = infixKePrefix(infix); //Fungsi infixKePrefix dipanggil untuk mengonversi ekspresi tersebut ke dalam bentuk prefix.//

    cout << "Infix expression: " << infix << endl;
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
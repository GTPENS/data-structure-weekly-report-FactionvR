/*
                        ALGORITMA DAN STRUKTUR DATA

NAMA : RANGGA RAISHA SYAPUTRA
NRP  : 5223600007

                        KESEIMBANGAN TANDA KURUNG
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool apaKurungImbang(const string& eks) {
    stack<char> stack;

    for (char ch : eks) {
        switch (ch) {
        case '(':
        case '[':
        case '{':
            stack.push(ch);
            break;
        case ')':
            if (stack.empty() || stack.top() != '(') {
                return false;
            }
            stack.pop();
            break;
        case ']':
            if (stack.empty() || stack.top() != '[') {
                return false;
            }
            stack.pop();
            break;
        case '}':
            if (stack.empty() || stack.top() != '{') {
                return false;
            }
            stack.pop();
            break;
        default:
            break;
        }
    }

    return stack.empty();
}

int main() {
    string eks1 = "({})";
    string eks2 = "{{}][";

    cout << "Ekspresi: " << eks1 << " adalah "
        << (apaKurungImbang(eks1) ? "seimbang" : "tidak seimbang") << endl;
    cout << "Ekspresi: " << eks2 << " adalah "
        << (apaKurungImbang(eks2) ? "seimbang" : "tidak seimbang") << endl;

    return 0;
}
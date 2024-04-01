/*
                        ALGORITMA DAN STRUKTUR DATA

NAMA : RANGGA RAISHA SYAPUTRA
NRP  : 5223600007

                        MENGEVALUASI EKSPRESI STACK
*/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evalPostfix(const string& postfix) {
    stack<int> stack;

    for (char ch : postfix) {
        //Jika karakter adalah digit (angka), maka nilai numerik dari karakter tersebut dikonversi ke dalam bentuk integer dan dimasukkan ke dalam stack.//
        if (isdigit(ch)) {
            stack.push(ch - '0');
        }
        //Jika karakter adalah operator dibawah ini, maka dua nilai teratas dari stack diambil sebagai operand dan dioperasikan sesuai dengan operator yang bersangkutan. Hasil operasi kemudian dimasukkan kembali ke dalam stack.//
        else {
            int operasi2 = stack.top();
            stack.pop();
            int operasi1 = stack.top();
            stack.pop();

            switch (ch) {
            case '+':
                stack.push(operasi1 + operasi2);
                break;
            case '-':
                stack.push(operasi1 - operasi2);
                break;
            case '*':
                stack.push(operasi1 * operasi2);
                break;
            case '/':
                stack.push(operasi1 / operasi2);
                break;
            }
        }
    }

    return stack.top();
}

int main() {
    string postfix = "83*72-";
    int result = evalPostfix(postfix);

    cout << "Ekspresi Postfix: " << postfix << endl;
    cout << "Hasil: " << result << endl;

    return 0;
}
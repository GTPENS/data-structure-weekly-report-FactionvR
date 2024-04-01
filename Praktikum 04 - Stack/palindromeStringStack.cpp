/*
                        ALGORITMA DAN STRUKTUR DATA

NAMA : RANGGA RAISHA SYAPUTRA
NRP  : 5223600007

                        PALINDROME STRING DENGAN STACK
*/

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool apaPalindrome(const string& str) {
    stack<char> stack;
    string temp = str;

    // Menghapus spasi lalu mengubah string yang dimasukkan ke huruf kecil
    temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

    // Mendorong setengah dari karakter yang diinputkan ke dalam stack
    for (int i = 0; i < temp.length() / 2; i++) {
        stack.push(temp[i]);
    }

    int start = temp.length() % 2 == 0 ? temp.length() / 2 : (temp.length() / 2) + 1;

    // Memeriksa apakah karakter yang sesuai dengan stack
    for (int i = start; i < temp.length(); i++) {
        if (temp[i] != stack.top()) {
            return false;
        }
        stack.pop();
    }

    return true;
}

int main() {
    string a;
    cout << "Masukkan sebuah string: ";
    getline(cin, a);

    cout << "Kata " << "\""<< a << "\" adalah " << (apaPalindrome(a) ? "sebuah palindrome" : "bukan sebuah palindrome") << endl;

    return 0;
}
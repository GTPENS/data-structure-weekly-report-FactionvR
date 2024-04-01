/*
                        ALGORITMA DAN STRUKTUR DATA

NAMA : RANGGA RAISHA SYAPUTRA
NRP  : 5223600007

                        JOSEPHUS PROBLEM

Josephus Problem adalah sebuah permainan atau teka-teki matematika yang melibatkan sejumlah orang yang membentuk lingkaran. Setiap orang memiliki nomor identitas unik, dan permainan tersebut dimulai dengan menghitung dari salah satu orang dan melakukan penghapusan setiap ke-k orang (biasanya disebut dengan langkah k) sampai hanya satu orang yang tersisa. Orang yang tersisa tersebut adalah orang yang "selamat".

*/

#include <iostream>
#include <list>
using namespace std;

int josep(int n, int k) {
    list<int> orang;

    // Membuat daftar orang dari 1 hingga n
    for (int i = 1; i <= n; i++) {
        orang.push_back(i);
    }

    auto it = orang.begin();
    while (orang.size() > 1) {
        // Memindahkan iterator k-1 langkah
        for (int i = 0; i < k - 1; i++) {
            it++;
            if (it == orang.end()) {
                it = orang.begin();
            }
        }

        // Menghapus orang saat ini
        auto next = it;
        next++;
        if (next == orang.end()) {
            next = orang.begin();
        }
        it = orang.erase(it);
        it = next;
    }

    return orang.front();
}

int main() {
    int n, k;
    cout << "Berapa jumlah orang: ";
    cin >> n;
    cout << "Berapa nilai k: ";
    cin >> k;

    int selamat = josep(n, k);
    cout << "Dan akhirnya orang yang selamat adalah: " << selamat << endl;

    return 0;
}
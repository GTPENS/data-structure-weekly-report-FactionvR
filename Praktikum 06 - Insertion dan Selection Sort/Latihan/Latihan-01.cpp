#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menampilkan koleksi
void tampilkanKoleksi(vector<int>& koleksi) {
    for (int elemen : koleksi) {
        cout << elemen << " ";
    }
    cout << endl;
}

// Algoritma pengurutan penyisipan
void algoritmaPenyisipan(vector<int>& koleksi) {
    int panjang = koleksi.size();
    for (int i = 1; i < panjang; i++) {
        int kunci = koleksi[i];
        int j = i - 1;
        while (j >= 0 && koleksi[j] > kunci) {
            koleksi[j + 1] = koleksi[j];
            j--;
        }
        koleksi[j + 1] = kunci;
        cout << "Iterasi ke-" << i << ": ";
        tampilkanKoleksi(koleksi);
    }
}

// Algoritma pengurutan penyisipan biner
void algoritmaPenyisipanBiner(vector<int>& koleksi) {
    int panjang = koleksi.size();
    for (int i = 1; i < panjang; i++) {
        int kunci = koleksi[i];
        int kiri = 0, kanan = i;
        while (kiri < kanan) {
            int tengah = kiri + (kanan - kiri) / 2;
            if (kunci < koleksi[tengah])
                kanan = tengah;
            else
                kiri = tengah + 1;
        }
        for (int j = i; j > kiri; j--) {
            koleksi[j] = koleksi[j - 1];
        }
        koleksi[kiri] = kunci;
        cout << "Iterasi ke-" << i << ": ";
        tampilkanKoleksi(koleksi);
    }
}

// Algoritma pengurutan pilihan
void algoritmaPilihan(vector<int>& koleksi) {
    int panjang = koleksi.size();
    for (int i = 0; i < panjang - 1; i++) {
        int indeksMinimum = i;
        for (int j = i + 1; j < panjang; j++) {
            if (koleksi[j] < koleksi[indeksMinimum])
                indeksMinimum = j;
        }
        swap(koleksi[i], koleksi[indeksMinimum]);
        cout << "Iterasi ke-" << i + 1 << ": ";
        tampilkanKoleksi(koleksi);
    }
}

int main() {
    vector<int> koleksi = {64, 25, 12, 22, 11};

    cout << "Pengurutan Penyisipan:" << endl;
    algoritmaPenyisipan(koleksi);
    cout << endl;

    koleksi = {64, 25, 12, 22, 11};
    cout << "Pengurutan Penyisipan Biner:" << endl;
    algoritmaPenyisipanBiner(koleksi);
    cout << endl;

    koleksi = {64, 25, 12, 22, 11};
    cout << "Pengurutan Pilihan:" << endl;
    algoritmaPilihan(koleksi);

    return 0;
}

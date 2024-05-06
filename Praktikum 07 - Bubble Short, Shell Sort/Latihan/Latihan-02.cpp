#include <iostream>
#include <cstdlib>
using namespace std;

const int MAKS = 10;
int Data[MAKS];

// Prosedur untuk menukar data
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur pengurutan metode gelembung
void PengurutanGelembung(int& perbandingan, int& pertukaran) {
    int i, j;
    perbandingan = 0;
    pertukaran = 0;

    for (i = 0; i < MAKS - 1; i++) {
        for (j = MAKS - 1; j >= i + 1; j--) {
            perbandingan++;
            if (Data[j - 1] > Data[j]) {
                Tukar(&Data[j - 1], &Data[j]);
                pertukaran++;
            }
        }
    }
}

// Prosedur pengurutan metode Shell
void PengurutanShell(int& perbandingan, int& pertukaran) {
    int Jarak, i, j;
    bool Sudah;
    Jarak = MAKS;
    perbandingan = 0;
    pertukaran = 0;

    while (Jarak > 1) {
        Jarak = Jarak / 2;
        Sudah = false;

        while (!Sudah) {
            Sudah = true;
            for (j = 0; j < MAKS - Jarak; j++) {
                i = j + Jarak;
                perbandingan++;
                if (Data[j] > Data[i]) {
                    Tukar(&Data[j], &Data[i]);
                    Sudah = false;
                    pertukaran++;
                }
            }
        }
    }
}

int main() {
    int i, pilihan, perbandingan, pertukaran;
    srand(0);

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAKS; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    // Menu pilihan metode pengurutan
    cout << "\nPilih metode pengurutan:" << endl;
    cout << "1. Pengurutan Gelembung" << endl;
    cout << "2. Pengurutan Shell" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "\nProses Pengurutan Gelembung:" << endl;
            PengurutanGelembung(perbandingan, pertukaran);
            cout << "\nData setelah diurutkan dengan Pengurutan Gelembung:" << endl;
            cout << "Jumlah Perbandingan: " << perbandingan << endl;
            cout << "Jumlah Pertukaran: " << pertukaran << endl;
            break;
        case 2:
            cout << "\nProses Pengurutan Shell:" << endl;
            PengurutanShell(perbandingan, pertukaran);
            cout << "\nData setelah diurutkan dengan Pengurutan Shell:" << endl;
            cout << "Jumlah Perbandingan: " << perbandingan << endl;
            cout << "Jumlah Pertukaran: " << pertukaran << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    // Menampilkan data setelah diurutkan
    for (i = 0; i < MAKS; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
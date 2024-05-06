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

// Prosedur untuk pengurutan dengan metode gelembung
void PengurutanGelembung() {
    int i, j;
    for (i = 0; i < MAKS - 1; i++) {
        for (j = MAKS - 1; j >= i + 1; j--) {
            if (Data[j - 1] > Data[j]) {
                Tukar(&Data[j - 1], &Data[j]);
                cout << "Iterasi " << i + 1 << ", Tukar Data[" << j - 1 << "] = " << Data[j - 1] << " dengan Data[" << j << "] = " << Data[j] << endl;
            }
        }
    }
}

// Prosedur untuk pengurutan dengan metode Shell
void PengurutanShell() {
    int Jarak, i, j;
    for (Jarak = MAKS / 2; Jarak > 0; Jarak /= 2) {
        for (i = Jarak; i < MAKS; i++) {
            for (j = i - Jarak; j >= 0; j -= Jarak) {
                if (Data[j] > Data[j + Jarak]) {
                    Tukar(&Data[j], &Data[j + Jarak]);
                    cout << "Jarak = " << Jarak << ", Tukar Data[" << j << "] = " << Data[j] << " dengan Data[" << j + Jarak << "] = " << Data[j + Jarak] << endl;
                }
            }
        }
    }
}

int main() {
    int i, pilihan;
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
            PengurutanGelembung();
            cout << "\nData setelah diurutkan dengan Pengurutan Gelembung:" << endl;
            break;
        case 2:
            cout << "\nProses Pengurutan Shell:" << endl;
            PengurutanShell();
            cout << "\nData setelah diurutkan dengan Pengurutan Shell:" << endl;
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

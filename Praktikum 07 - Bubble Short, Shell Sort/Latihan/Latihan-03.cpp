#include <iostream>
#include <cstring>
using namespace std;

struct Pegawai {
    string NIP;
    string Nama;
    string Alamat;
    char Golongan;
};

const int MAKS_PEGAWAI = 5;
Pegawai dataPegawai[MAKS_PEGAWAI] = {
    {"P001", "Sulistyo", "Pemalang", 'A'},
    {"P002", "Fulan", "Surabaya", 'A'},
    {"P003", "Hamdan", "Surabaya", 'A'},
    {"P004", "Muhajir", "Pamekasan", 'A'},
    {"P005", "Zahra", "Malang", 'A'}
};

void TukarPegawai(Pegawai& a, Pegawai& b) {
    Pegawai temp = a;
    a = b;
    b = temp;
}

void BubbleSortPegawai(bool isAscending, bool urutBerdasarkanNIP) {
    int perbandingan = 0, pertukaran = 0;
    for (int i = 0; i < MAKS_PEGAWAI - 1; i++) {
        for (int j = MAKS_PEGAWAI - 1; j >= i + 1; j--) {
            perbandingan++;
            bool harusDitukar = false;
            if (urutBerdasarkanNIP) {
                harusDitukar = isAscending ? dataPegawai[j - 1].NIP > dataPegawai[j].NIP
                                            : dataPegawai[j - 1].NIP < dataPegawai[j].NIP;
            } else {
                harusDitukar = isAscending ? dataPegawai[j - 1].Nama > dataPegawai[j].Nama
                                            : dataPegawai[j - 1].Nama < dataPegawai[j].Nama;
            }

            if (harusDitukar) {
                TukarPegawai(dataPegawai[j - 1], dataPegawai[j]);
                pertukaran++;
            }
        }
    }
    cout << "Jumlah Perbandingan: " << perbandingan << endl;
    cout << "Jumlah Pertukaran: " << pertukaran << endl;
}

void ShellSortPegawai(bool isAscending, bool urutBerdasarkanNIP) {
    int perbandingan = 0, pertukaran = 0;
    int jarak, i, j;
    bool sudah;
    jarak = MAKS_PEGAWAI;

    while (jarak > 1) {
        jarak = jarak / 2;
        sudah = false;

        while (!sudah) {
            sudah = true;
            for (j = 0; j < MAKS_PEGAWAI - jarak; j++) {
                i = j + jarak;
                perbandingan++;
                bool harusDitukar = false;
                if (urutBerdasarkanNIP) {
                    harusDitukar = isAscending ? dataPegawai[j].NIP > dataPegawai[i].NIP
                                                : dataPegawai[j].NIP < dataPegawai[i].NIP;
                } else {
                    harusDitukar = isAscending ? dataPegawai[j].Nama > dataPegawai[i].Nama
                                                : dataPegawai[j].Nama < dataPegawai[i].Nama;
                }

                if (harusDitukar) {
                    TukarPegawai(dataPegawai[j], dataPegawai[i]);
                    sudah = false;
                    pertukaran++;
                }
            }
        }
    }
    cout << "Jumlah Perbandingan: " << perbandingan << endl;
    cout << "Jumlah Pertukaran: " << pertukaran << endl;
}

int main() {
    int pilihan, urutanPilihan, kriteriaPilihan;

    cout << "Data Pegawai Awal:" << endl;
    for (int i = 0; i < MAKS_PEGAWAI; i++) {
        cout << "NIP: " << dataPegawai[i].NIP << ", Nama: " << dataPegawai[i].Nama
             << ", Alamat: " << dataPegawai[i].Alamat << ", Golongan: " << dataPegawai[i].Golongan << endl;
    }

    cout << "\nPilih metode pengurutan:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Shell Sort" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    cout << "\nPilih urutan pengurutan:" << endl;
    cout << "1. Urut Naik" << endl;
    cout << "2. Urut Turun" << endl;
    cout << "Pilihan Anda: ";
    cin >> urutanPilihan;

    cout << "\nPilih kriteria pengurutan:" << endl;
    cout << "1. Berdasarkan NIP" << endl;
    cout << "2. Berdasarkan Nama" << endl;
    cout << "Pilihan Anda: ";
    cin >> kriteriaPilihan;

    bool urutNaik = urutanPilihan == 1;
    bool urutBerdasarkanNIP = kriteriaPilihan == 1;

    if (pilihan == 1) {
        BubbleSortPegawai(urutNaik, urutBerdasarkanNIP);
        cout << "\nData Pegawai Setelah Diurutkan dengan Bubble Sort:" << endl;
    } else if (pilihan == 2) {
        ShellSortPegawai(urutNaik, urutBerdasarkanNIP);
        cout << "\nData Pegawai Setelah Diurutkan dengan Shell Sort:" << endl;
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return 0;
    }

    for (int i = 0; i < MAKS_PEGAWAI; i++) {
        cout << "NIP: " << dataPegawai[i].NIP << ", Nama: " << dataPegawai[i].Nama
             << ", Alamat: " << dataPegawai[i].Alamat << ", Golongan: " << dataPegawai[i].Golongan << endl;
    }

    return 0;
}
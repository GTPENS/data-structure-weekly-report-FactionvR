### Nama : Rangga Raisha Syaputra
### NRP : 5223600007
### Kelas : 11 GT-A
# Praktikum 07 : Bubble Sort, Shell Sort

## Percobaan

Percobaan - 01

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

using namespace std;

int Data[MAX];

void Tukar(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort() {
    int i, j;
    for (i = 0; i < MAX - 1; i++)
        for (j = MAX - 1; j >= i; j--)
            if (Data[j - 1] > Data[j])
                Tukar(&Data[j - 1], &Data[j]);
}

int main() {
    int i;
    srand(0);
    cout << "DATA SEBELUM TERURUT" << endl;
    
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    BubbleSort();
    
    cout << "DATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    return 0;
}
```

Percobaan - 02

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

using namespace std;

int Data[MAX];

void Tukar(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void ShellSort() {
    int Jarak, i, j;
    bool Sudah;
    Jarak = MAX;
    while (Jarak > 1) {
        Jarak = Jarak / 2;
        Sudah = false;
        while (!Sudah) {
            Sudah = true;
            for (j = 0; j < MAX - Jarak; j++) {
                i = j + Jarak;
                if (Data[j] > Data[i]) {
                    Tukar(&Data[j], &Data[i]);
                    Sudah = false;
                }
            }
        }
    }
}

int main() {
    int i;
    srand(0);
    cout << "DATA SEBELUM TERURUT" << endl;

    for (i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    ShellSort();
    cout << "DATA SETELAH TERURUT" << endl;

    for (i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    return 0;
}
```

## Latihan

Latihan - 01

```cpp
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
```

Latihan - 02

```cpp
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
```

Latihan - 03

```cpp
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
```












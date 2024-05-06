### Nama : Rangga Raisha Syaputra
### NRP : 5223600007
### Kelas : 11 GT-A
# Praktikum 06 : Insertion dan Selection Sort

## Percobaan

Percobaan - 01

```sh
#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

using namespace std;

int Data[MAX];

void StraightInsertSort() {
    int i, j, x;
    for(i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (j >= 0 && x < Data[j]) {
            Data[j + 1] = Data[j];
            j--;
        }
        Data[j + 1] = x;
    }
}

int main() {
    int i;
    srand(0);
    cout << "DATA SEBELUM TERURUT" << endl;
    for(i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    
    StraightInsertSort();
    cout << "DATA SETELAH TERURUT" << endl;
    for(i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    return 0;
}
```

Percobaan - 02

```sh
#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

using namespace std;

int Data[MAX];

void BinaryInsertSort() {
    int i, j, l, r, m, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        l = 0;
        r = i - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (x < Data[m])
                r = m - 1;
            else
                l = m + 1;
        }
        for (j = i - 1; j >= l; j--)
            Data[j + 1] = Data[j];
        Data[l] = x;
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
    
    BinaryInsertSort();
    cout << "DATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    return 0;
}
```

Percobaan - 03

```sh
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

void SelectionSort() {
    int i, j, k;
    for (i = 0; i < MAX - 1; i++) {
        k = i;
        for (j = i + 1; j < MAX; j++)
            if (Data[k] > Data[j])
                k = j;
        Tukar(&Data[i], &Data[k]);
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
    SelectionSort();
    cout << "DATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    return 0;
}
```

## Latihan

Latihan - 01

```sh
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
```

Latihan - 02

```sh
#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menampilkan array
void tampilkanArray(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Algoritma pengurutan penyisipan
void pengurutanPenyisipan(vector<int>& arr, int& perbandingan, int& pergeseran) {
    int n = arr.size();
    perbandingan = 0;
    pergeseran = 0;
    for (int i = 1; i < n; i++) {
        int kunci = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > kunci) {
            arr[j + 1] = arr[j];
            j--;
            pergeseran++;
            perbandingan++;
        }
        arr[j + 1] = kunci;
        pergeseran++;
    }
}

// Algoritma pengurutan penyisipan biner
void pengurutanPenyisipanBiner(vector<int>& arr, int& perbandingan, int& pergeseran) {
    int n = arr.size();
    perbandingan = 0;
    pergeseran = 0;
    for (int i = 1; i < n; i++) {
        int kunci = arr[i];
        int kiri = 0, kanan = i;
        while (kiri < kanan) {
            int tengah = kiri + (kanan - kiri) / 2;
            if (kunci < arr[tengah]) {
                kanan = tengah;
            } else {
                kiri = tengah + 1;
            }
            perbandingan++;
        }
        for (int j = i; j > kiri; j--) {
            arr[j] = arr[j - 1];
            pergeseran++;
        }
        arr[kiri] = kunci;
        pergeseran++;
    }
}

// Algoritma pengurutan pilihan
void pengurutanPilihan(vector<int>& arr, int& perbandingan, int& pergeseran) {
    int n = arr.size();
    perbandingan = 0;
    pergeseran = 0;
    for (int i = 0; i < n - 1; i++) {
        int indeksMinimum = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[indeksMinimum]) {
                indeksMinimum = j;
            }
            perbandingan++;
        }
        swap(arr[i], arr[indeksMinimum]);
        pergeseran += 3;  // Setiap swap memerlukan 3 pergeseran
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    int perbandingan, pergeseran;

    cout << "Pengurutan Penyisipan:" << endl;
    pengurutanPenyisipan(arr, perbandingan, pergeseran);
    tampilkanArray(arr);
    cout << "Perbandingan: " << perbandingan << ", Pergeseran: " << pergeseran << endl;
    cout << endl;

    arr = {64, 25, 12, 22, 11};
    cout << "Pengurutan Penyisipan Biner:" << endl;
    pengurutanPenyisipanBiner(arr, perbandingan, pergeseran);
    tampilkanArray(arr);
    cout << "Perbandingan: " << perbandingan << ", Pergeseran: " << pergeseran << endl;
    cout << endl;

    arr = {64, 25, 12, 22, 11};
    cout << "Pengurutan Pilihan:" << endl;
    pengurutanPilihan(arr, perbandingan, pergeseran);
    tampilkanArray(arr);
    cout << "Perbandingan: " << perbandingan << ", Pergeseran: " << pergeseran << endl;

    return 0;
}
```

Latihan - 03

```sh
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Struct untuk menyimpan data Pegawai
struct Pegawai {
    string nip;
    string nama;
};

// Fungsi untuk melakukan pengurutan berdasarkan NIP
bool sortByNIP(const Pegawai& p1, const Pegawai& p2) {
    return p1.nip < p2.nip;
}

// Fungsi untuk melakukan pengurutan berdasarkan Nama
bool sortByNama(const Pegawai& p1, const Pegawai& p2) {
    return p1.nama < p2.nama;
}

// Fungsi untuk menampilkan data Pegawai
void printPegawai(vector<Pegawai>& pegawai) {
    cout << "Data Pegawai:" << endl;
    for (const auto& p : pegawai) {
        cout << "NIP: " << p.nip << ", Nama: " << p.nama << endl;
    }
}

int main() {
    vector<Pegawai> pegawai = {
       {"P001", "Indra"},
       {"P002", "Sulistyo"},
       {"P003", "Parman"},
       {"P004", "Setya"},
       {"P005", "Rahayu"}
    };

    int choice;
    bool ascending;
    char sortBy;

    do {
        cout << "Pilih metode pengurutan:" << endl;
        cout << "1. Insertion Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Urutkan secara:" << endl;
            cout << "a. Ascending" << endl;
            cout << "b. Descending" << endl;
            cout << "Masukkan pilihan: ";
            char order;
            cin >> order;
            ascending = (order == 'a');

            cout << "Urutkan berdasarkan:" << endl;
            cout << "n. NIP" << endl;
            cout << "m. Nama" << endl;
            cout << "Masukkan pilihan: ";
            cin >> sortBy;

            if (sortBy == 'n') {
                if (choice == 1) {
                    sort(pegawai.begin(), pegawai.end(), sortByNIP);
                }
                else {
                    // Selection Sort
                    cout << "Metode Selection Sort tidak mendukung pengurutan berdasarkan NIP." << endl;
                    continue;
                }
            }
            else if (sortBy == 'm') {
                if (choice == 1) {
                    sort(pegawai.begin(), pegawai.end(), sortByNama);
                }
                else {
                    // Selection Sort
                    cout << "Metode Selection Sort tidak mendukung pengurutan berdasarkan Nama." << endl;
                    continue;
                }
            }
            else {
                cout << "Pilihan tidak valid." << endl;
                continue;
            }

            if (!ascending) {
                reverse(pegawai.begin(), pegawai.end());
            }

            printPegawai(pegawai);
        }
    } while (choice != 3);

    return 0;
}
```












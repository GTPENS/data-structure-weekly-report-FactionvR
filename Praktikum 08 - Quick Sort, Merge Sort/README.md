### Nama : Rangga Raisha Syaputra
### NRP : 5223600007
### Kelas : 11 GT-A
# Praktikum 07 : Quick Sort, Merge Sort

## Percobaan

Percobaan - 01

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10
#define MaxStack 10

using namespace std;

int Data[MAX];

void Tukar(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSortNonRekursif() {
    struct tump {
        int Kiri;
        int Kanan;
    } Tumpukan[MaxStack];
    int i, j, L, R, x, ujung = 1;
    Tumpukan[1].Kiri = 0;
    Tumpukan[1].Kanan = MAX - 1;
    while (ujung != 0) {
        L = Tumpukan[ujung].Kiri;
        R = Tumpukan[ujung].Kanan;
        ujung--;
        while (R > L) {
            i = L;
            j = R;
            x = Data[(L + R) / 2];
            while (i <= j) {
                while (Data[i] < x)
                    i++;
                while (x < Data[j])
                    j--;
                if (i <= j) {
                    Tukar(&Data[i], &Data[j]);
                    i++;
                    j--;
                }
            }
            if (L < i) {
                ujung++;
                Tumpukan[ujung].Kiri = i;
                Tumpukan[ujung].Kanan = R;
            }
            R = j;
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
    QuickSortNonRekursif();
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

// Prosedur menukar data
void Tukar(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur pengurutan metode Quick Sort
void QuickSortRekursif(int L, int R) {
    int i, j, x;
    x = Data[(L + R) / 2];
    i = L;
    j = R;
    while (i <= j) {
        while (Data[i] < x)
            i++;
        while (Data[j] > x)
            j--;
        if (i <= j) {
            Tukar(&Data[i], &Data[j]);
            i++;
            j--;
        }
    }
    if (L < j)
        QuickSortRekursif(L, j);
    if (i < R)
        QuickSortRekursif(i, R);
}

int main() {
    int i;
    srand(0);
    cout << "DATA SEBELUM TERURUT" << endl;
    // Membangkitkan bilangan acak
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    QuickSortRekursif(0, MAX - 1);
    cout << "DATA SETELAH TERURUT" << endl;
    // Data setelah terurut
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
#include <ctime>

using namespace std;

#define MAKS 10
#define MAKS_TUMPUKAN 10

struct Tumpukan {
    int kiri;
    int kanan;
};

void tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Implementasi pengurutan dengan metode Quick Sort Non-Rekursif
void quickSortNonRekursif(int arr[]) {
    Tumpukan tumpukan[MAKS_TUMPUKAN];
    int atas = 0;
    int l, r, i, j, x;

    tumpukan[atas].kiri = 0;
    tumpukan[atas].kanan = MAKS - 1;
    atas++;

    while (atas > 0) {
        atas--;
        l = tumpukan[atas].kiri;
        r = tumpukan[atas].kanan;

        while (r > l) {
            i = l;
            j = r;
            x = arr[(l + r) / 2];

            while (i <= j) {
                while (arr[i] < x) i++;
                while (arr[j] > x) j--;

                if (i <= j) {
                    tukar(&arr[i], &arr[j]);
                    i++;
                    j--;
                }
            }

            if (l < j) {
                atas++;
                tumpukan[atas].kiri = l;
                tumpukan[atas].kanan = j;
            }

            r = j;
        }

        // Tampilkan perubahan setiap iterasi
        cout << "Iterasi: ";
        for (int k = 0; k < MAKS; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

// Implementasi pengurutan dengan metode Quick Sort Rekursif
void quickSortRekursif(int arr[], int l, int r) {
    int i, j, x;

    x = arr[(l + r) / 2];
    i = l;
    j = r;

    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            tukar(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    // Tampilkan perubahan setiap iterasi
    cout << "Iterasi: ";
    for (int k = 0; k < MAKS; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    if (l < j)
        quickSortRekursif(arr, l, j);
    if (i < r)
        quickSortRekursif(arr, i, r);
}

// Implementasi pengurutan dengan metode Merge Sort
void merge(int arr[], int temp[], int kiri, int tengah, int kanan) {
    int i, j, k;
    i = kiri;
    j = tengah;
    k = kiri;

    while (i <= tengah - 1 && j <= kanan) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= tengah - 1)
        temp[k++] = arr[i++];

    while (j <= kanan)
        temp[k++] = arr[j++];

    for (i = kiri; i <= kanan; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int temp[], int kiri, int kanan) {
    int tengah;
    if (kiri < kanan) {
        tengah = (kiri + kanan) / 2;
        mergeSort(arr, temp, kiri, tengah);
        mergeSort(arr, temp, tengah + 1, kanan);

        // Tampilkan perubahan setiap iterasi
        cout << "Iterasi: ";
        for (int k = 0; k < MAKS; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;

        merge(arr, temp, kiri, tengah + 1, kanan);
    }
}

int main() {
    int arr[MAKS];
    int temp[MAKS];
    int pilihan;
    srand(time(NULL));

    cout << "Data sebelum terurut: ";
    for (int i = 0; i < MAKS; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    cout << "Pilih metode pengurutan:" << endl;
    cout << "1. Quick Sort Non-Rekursif" << endl;
    cout << "2. Quick Sort Rekursif" << endl;
    cout << "3. Merge Sort" << endl;
    cout << "Masukkan pilihan Anda (1-3): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            quickSortNonRekursif(arr);
            break;
        case 2:
            quickSortRekursif(arr, 0, MAKS - 1);
            break;
        case 3:
            mergeSort(arr, temp, 0, MAKS - 1);
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    cout << "Data setelah terurut: ";
    for (int i = 0; i < MAKS; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
```

Latihan - 02

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAKS 10
#define MAKS_TUMPUKAN 10

int perbandingan = 0; // Variabel untuk menyimpan jumlah perbandingan
int pergeseran = 0; // Variabel untuk menyimpan jumlah pergeseran

struct Tumpukan {
    int kiri;
    int kanan;
};

void tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    pergeseran++; // Menghitung jumlah pergeseran
}

// Implementasi pengurutan dengan metode Quick Sort Non-Rekursif
void quickSortNonRekursif(int arr[]) {
    Tumpukan tumpukan[MAKS_TUMPUKAN];
    int atas = 0;
    int l, r, i, j, x;

    tumpukan[atas].kiri = 0;
    tumpukan[atas].kanan = MAKS - 1;
    atas++;

    while (atas > 0) {
        atas--;
        l = tumpukan[atas].kiri;
        r = tumpukan[atas].kanan;

        while (r > l) {
            i = l;
            j = r;
            x = arr[(l + r) / 2];

            while (i <= j) {
                while (arr[i] < x) {
                    i++;
                    perbandingan++; // Menghitung jumlah perbandingan
                }
                while (arr[j] > x) {
                    j--;
                    perbandingan++; // Menghitung jumlah perbandingan
                }

                if (i <= j) {
                    tukar(&arr[i], &arr[j]);
                    i++;
                    j--;
                }
            }

            if (l < j) {
                atas++;
                tumpukan[atas].kiri = l;
                tumpukan[atas].kanan = j;
            }

            r = j;
        }
    }
}

// Implementasi pengurutan dengan metode Quick Sort Rekursif
void quickSortRekursif(int arr[], int l, int r) {
    int i, j, x;

    x = arr[(l + r) / 2];
    i = l;
    j = r;

    while (i <= j) {
        while (arr[i] < x) {
            i++;
            perbandingan++; // Menghitung jumlah perbandingan
        }
        while (arr[j] > x) {
            j--;
            perbandingan++; // Menghitung jumlah perbandingan
        }

        if (i <= j) {
            tukar(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (l < j)
        quickSortRekursif(arr, l, j);
    if (i < r)
        quickSortRekursif(arr, i, r);
}

// Implementasi pengurutan dengan metode Merge Sort
void merge(int arr[], int temp[], int kiri, int tengah, int kanan) {
    int i, j, k;
    i = kiri;
    j = tengah;
    k = kiri;

    while (i <= tengah - 1 && j <= kanan) {
        perbandingan++; // Menghitung jumlah perbandingan
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= tengah - 1) {
        temp[k++] = arr[i++];
        pergeseran++; // Menghitung jumlah pergeseran
    }

    while (j <= kanan) {
        temp[k++] = arr[j++];
        pergeseran++; // Menghitung jumlah pergeseran
    }

    for (i = kiri; i <= kanan; i++) {
        arr[i] = temp[i];
        pergeseran++; // Menghitung jumlah pergeseran
    }
}

void mergeSort(int arr[], int temp[], int kiri, int kanan) {
    int tengah;
    if (kiri < kanan) {
        tengah = (kiri + kanan) / 2;
        mergeSort(arr, temp, kiri, tengah);
        mergeSort(arr, temp, tengah + 1, kanan);
        merge(arr, temp, kiri, tengah + 1, kanan);
    }
}

int main() {
    int arr[MAKS];
    int temp[MAKS];
    int pilihan;
    srand(time(NULL));

    cout << "Data sebelum terurut: ";
    for (int i = 0; i < MAKS; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    cout << "Pilih metode pengurutan:" << endl;
    cout << "1. Quick Sort Non-Rekursif" << endl;
    cout << "2. Quick Sort Rekursif" << endl;
    cout << "3. Merge Sort" << endl;
    cout << "Masukkan pilihan Anda (1-3): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            quickSortNonRekursif(arr);
            break;
        case 2:
            quickSortRekursif(arr, 0, MAKS - 1);
            break;
        case 3:
            mergeSort(arr, temp, 0, MAKS - 1);
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    cout << "Data setelah terurut: ";
    for (int i = 0; i < MAKS; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Jumlah perbandingan: " << perbandingan << endl;
    cout << "Jumlah pergeseran: " << pergeseran << endl;

    return 0;
}
```

Latihan - 03

```cpp
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

struct Pegawai {
    string NIP;
    string Nama;
    string Alamat;
    char Golongan;
};

const int JUMLAH_PEGAWAI = 5;
Pegawai dataPegawai[JUMLAH_PEGAWAI] = {
    {"P003", "Sulistyo", "Pemalang", 'A'},
    {"P005", "Yusuf", "Surabaya", 'A'},
    {"P001", "Deddy", "Banyuwangi", 'A'},
    {"P004", "Maharaja", "Kediri", 'A'},
    {"P002", "Karjo", "Banjarmasin", 'A'}
};

void tukar(Pegawai& a, Pegawai& b) {
    Pegawai temp = a;
    a = b;
    b = temp;
}

void quickSortNIP(Pegawai arr[], int kiri, int kanan, bool naik) {
    int i = kiri, j = kanan;
    string pivot = arr[(kiri + kanan) / 2].NIP;

    while (i <= j) {
        while (naik ? arr[i].NIP < pivot : arr[i].NIP > pivot)
            i++;
        while (naik ? arr[j].NIP > pivot : arr[j].NIP < pivot)
            j--;

        if (i <= j) {
            tukar(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (kiri < j)
        quickSortNIP(arr, kiri, j, naik);
    if (i < kanan)
        quickSortNIP(arr, i, kanan, naik);
}

void quickSortNama(Pegawai arr[], int kiri, int kanan, bool naik) {
    int i = kiri, j = kanan;
    string pivot = arr[(kiri + kanan) / 2].Nama;

    while (i <= j) {
        while (naik ? arr[i].Nama < pivot : arr[i].Nama > pivot)
            i++;
        while (naik ? arr[j].Nama > pivot : arr[j].Nama < pivot)
            j--;

        if (i <= j) {
            tukar(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (kiri < j)
        quickSortNama(arr, kiri, j, naik);
    if (i < kanan)
        quickSortNama(arr, i, kanan, naik);
}

void gabung(Pegawai temp[], int kiri, int tengah, int kanan, bool naik, bool berdasarNIP) {
    int i = kiri, j = tengah + 1, k = kiri;

    while (i <= tengah && j <= kanan) {
        if (berdasarNIP) {
            if (naik ? temp[i].NIP < temp[j].NIP : temp[i].NIP > temp[j].NIP)
                dataPegawai[k++] = temp[i++];
            else
                dataPegawai[k++] = temp[j++];
        } else {
            if (naik ? temp[i].Nama < temp[j].Nama : temp[i].Nama > temp[j].Nama)
                dataPegawai[k++] = temp[i++];
            else
                dataPegawai[k++] = temp[j++];
        }
    }

    while (i <= tengah)
        dataPegawai[k++] = temp[i++];

    while (j <= kanan)
        dataPegawai[k++] = temp[j++];
}

void mergeSortNIP(Pegawai temp[], int kiri, int kanan, bool naik) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;
        mergeSortNIP(temp, kiri, tengah, naik);
        mergeSortNIP(temp, tengah + 1, kanan, naik);
        gabung(temp, kiri, tengah, kanan, naik, true);
    }
}

void mergeSortNama(Pegawai temp[], int kiri, int kanan, bool naik) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;
        mergeSortNama(temp, kiri, tengah, naik);
        mergeSortNama(temp, tengah + 1, kanan, naik);
        gabung(temp, kiri, tengah, kanan, naik, false);
    }
}

int main() {
    int pilihan, urutan, berdasar;
    bool naik;
    Pegawai temp[JUMLAH_PEGAWAI];

    cout << "Data Pegawai:" << endl;
    for (int i = 0; i < JUMLAH_PEGAWAI; i++) {
        cout << "NIP: " << dataPegawai[i].NIP << ", Nama: " << dataPegawai[i].Nama
             << ", Alamat: " << dataPegawai[i].Alamat << ", Golongan: " << dataPegawai[i].Golongan << endl;
    }

    cout << "\nPilih metode pengurutan:" << endl;
    cout << "1. Quick Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "Masukkan pilihan (1 atau 2): ";
    cin >> pilihan;

    if (pilihan != 1 && pilihan != 2) {
        cout << "Pilihan tidak valid!" << endl;
        return 0;
    }

    cout << "\nPilih urutan:" << endl;
    cout << "1. Naik" << endl;
    cout << "2. Turun" << endl;
    cout << "Masukkan pilihan (1 atau 2): ";
    cin >> urutan;
    naik = (urutan == 1);

    cout << "\nPilih kriteria pengurutan:" << endl;
    cout << "1. NIP" << endl;
    cout << "2. Nama" << endl;
    cout << "Masukkan pilihan (1 atau 2): ";
    cin >> berdasar;

    for (int i = 0; i < JUMLAH_PEGAWAI; i++)
        temp[i] = dataPegawai[i];

    if (berdasar == 1) {
        if (urutan == 1)
            quickSortNIP(dataPegawai, 0, JUMLAH_PEGAWAI - 1, naik);
        else
            mergeSortNIP(temp, 0, JUMLAH_PEGAWAI - 1, naik);
    } else if (berdasar == 2) {
        if (urutan == 1)
            quickSortNama(dataPegawai, 0, JUMLAH_PEGAWAI - 1, naik);
        else
            mergeSortNama(temp, 0, JUMLAH_PEGAWAI - 1, naik);
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return 0;
    }

    cout << "\nData Pegawai setelah diurutkan:" << endl;
    for (int i = 0; i < JUMLAH_PEGAWAI; i++) {
        cout << "NIP: " << dataPegawai[i].NIP << ", Nama: " << dataPegawai[i].Nama
             << ", Alamat: " << dataPegawai[i].Alamat << ", Golongan: " << dataPegawai[i].Golongan << endl;
    }

    return 0;
}
```












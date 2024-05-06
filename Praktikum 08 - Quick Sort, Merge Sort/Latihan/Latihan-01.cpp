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
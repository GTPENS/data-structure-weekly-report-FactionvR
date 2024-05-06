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

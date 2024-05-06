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
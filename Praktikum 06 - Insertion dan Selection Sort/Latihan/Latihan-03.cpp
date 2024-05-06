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

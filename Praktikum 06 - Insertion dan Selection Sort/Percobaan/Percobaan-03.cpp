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

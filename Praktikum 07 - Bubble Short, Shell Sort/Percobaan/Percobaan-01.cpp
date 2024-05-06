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

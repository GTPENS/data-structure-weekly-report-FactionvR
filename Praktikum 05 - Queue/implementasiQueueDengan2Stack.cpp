/*
                        ALGORITMA DAN STRUKTUR DATA

NAMA : RANGGA RAISHA SYAPUTRA
NRP  : 5223600007

                        IMPLEMENTASI QUEUE DENGAN 2 STACK
*/

#include <iostream>
#include <stack>
using namespace std;

class QueueDenganStack {
private:
    stack<int> stak1, stak2;

public:
    void enqueue(int nilai) { //Untuk menambahkan elemen ke dalam antrian.//
        stak1.push(nilai);
    }

    int dequeue() { //Untuk menghapus dan mengembalikan elemen dari antrian.//
        int nilai;
        if (stak2.empty()) {
            while (!stak1.empty()) {
                nilai = stak1.top();
                stak1.pop();
                stak2.push(nilai);
            }
        }
        
        //Jika stak2 masih tidak berisi elemen, maka semua elemen dari stak1 dipindahkan ke stak2 satu per satu.//
        if (stak2.empty()) {
            throw invalid_argument("QueueEmptyException");
        }
        nilai = stak2.top();
        stak2.pop();
        return nilai;
    }
};

int main() {
    QueueDenganStack que;
    que.enqueue(333);
    que.enqueue(33);
    que.enqueue(3);
    cout << que.dequeue() << endl; 
    que.enqueue(23);
    que.enqueue(567);
    que.enqueue(3455);
    cout << que.dequeue() << endl; 
    cout << que.dequeue() << endl;  
    return 0;
}
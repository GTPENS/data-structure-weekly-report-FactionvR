/*
                        ALGORITMA DAN STRUKTUR DATA

NAMA : RANGGA RAISHA SYAPUTRA
NRP  : 5223600007

                        MEMBUAT QUEUE DENGAN LINKED LIST
*/

#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int nilai;
        Node* next;
        Node(int v, Node* n) : nilai(v), next(n) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:
    int size() { return count; }
    bool empty() { return count == 0; }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nilai << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    //Metode ini mengembalikan nilai dari elemen pertama dalam antrian tanpa menghapusnya. Jika antrian kosong, akan dilemparkan exception 'invalid_argument'.//
    int peek() {
        if (empty()) {
            throw invalid_argument("QueueEmptyException");
        }
        return head->nilai;
    }
    
    //Menambahkan elemen baru dengan nilai ke dalam antrian.//
    void enqueue(int nilai) {
        Node* temp = new Node(nilai, nullptr);
        if (head == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        count++;
    }
    
    //Menghapus dan mengembalikan nilai dari elemen pertama dalam antrian.//
    int dequeue() {
        if (empty()) {
            throw invalid_argument("QueueEmptyException");
        }
        int nilai = head->nilai;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return nilai;
    }
};

int main() {
    Queue q;
    for (int i = 1; i <= 50; i++) {
        q.enqueue(i);
    }
    for (int i = 1; i <= 20; i++) {
        q.dequeue();
    }
    q.print();
    return 0;
}
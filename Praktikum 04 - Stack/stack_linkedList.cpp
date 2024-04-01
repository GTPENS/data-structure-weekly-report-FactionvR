/*
                        ALGORITMA DAN STRUKTUR DATA

NAMA : RANGGA RAISHA SYAPUTRA
NRP  : 5223600007

                        STACK LINKED LIST
*/

#include <iostream>
using namespace std;

class Node {
public:
    int nilai;
    Node* next;

    Node(int nil, Node* n = nullptr) {
        nilai = nil;
        next = n;
    }
};

class ListStack {
private:
    Node* head;
    int count;

public:
    ListStack() {
        head = nullptr;
        count = 0;
    }

    int size() {
        return count;
    }

    bool empty() {
        return count == 0;
    }

    int peek() {
        if (empty()) {
            throw out_of_range("Stack yang dimaksud kosong");
        }
        return head->nilai;
    }

    void push(int nilai) {
        head = new Node(nilai, head);
        count++;
    }

    int pop() {
        if (empty()) {
            throw out_of_range("Stack yang dimaksud kosong");
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
    ListStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Elemen atas: " << stack.peek() << endl;
    cout << "Ukuran stack: " << stack.size() << endl;

    stack.pop();
    cout << "Elemen atas setelah pop: " << stack.peek() << endl;

    return 0;
}
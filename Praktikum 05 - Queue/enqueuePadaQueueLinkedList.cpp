/*
                        ALGORITMA DAN STRUKTUR DATA

NAMA : RANGGA RAISHA SYAPUTRA
NRP  : 5223600007

                        ENQUEUE PADA QUEUE LINKED LIST
Kode program memuat implementasi metode `enqueue` untuk menambahkan elemen baru ke akhir Queue pada Linked List.

*/  

void Queue::enqueue(int nilai) {
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
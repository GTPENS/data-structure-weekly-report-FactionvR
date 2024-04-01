/*
                        ALGORITMA DAN STRUKTUR DATA

NAMA : RANGGA RAISHA SYAPUTRA
NRP  : 5223600007

                        DEQUEUE PADA QUEUE LINKED LIST
*/  

int Queue::dequeue() {
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
#include <iostream>
using namespace std;

#define MAX 5  // kapasitas maksimum antrean

struct Queue {
    int data[MAX];
    int head;
    int tail;
};

// Inisialisasi queue
void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q) {
    return (Q.tail == MAX - 1);
}

// Menambah data ke antrean
void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Antrean penuh!" << endl;
    } else {
        if (isEmpty(Q)) {
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.data[Q.tail] = x;
        cout << "Data " << x << " masuk antrean." << endl;
    }
}

// Menghapus data dari antrean (FIFO)
void dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Antrean kosong!" << endl;
    } else {
        cout << "Data " << Q.data[Q.head] << " keluar antrean." << endl;
        if (Q.head == Q.tail) {
            Q.head = Q.tail = -1; // antrean menjadi kosong
        } else {
            for (int i = Q.head; i < Q.tail; i++) {
                Q.data[i] = Q.data[i + 1];
            }
            Q.tail--;
        }
    }
}

// Menampilkan isi antrean
void printQueue(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Antrean kosong." << endl;
    } else {
        cout << "Isi antrean: ";
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.data[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Queue Q;
    createQueue(Q);

    enqueue(Q, 5);
    enqueue(Q, 2);
    enqueue(Q, 7);
    printQueue(Q);

    dequeue(Q);
    printQueue(Q);

    enqueue(Q, 4);
    enqueue(Q, 9);
    
    dequeue(Q);
    dequeue(Q);
    printQueue(Q);

    return 0;
}

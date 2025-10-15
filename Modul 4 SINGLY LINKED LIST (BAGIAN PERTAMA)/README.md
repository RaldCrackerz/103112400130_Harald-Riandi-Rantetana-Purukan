# <h1 align="center">Laporan Praktikum Modul X <br> Nama Modul</h1>
<p align="center"> Harald Riandi Rantetana Purukan - 103112400130 </p>

## Dasar Teori

Dasar teori dari percobaan ini adalah penerapan struktur data Singly Linked List, yaitu bentuk Linked List yang setiap elemennya (node) hanya memiliki satu pointer yang menunjuk ke node berikutnya. Struktur ini bersifat dinamis, artinya ukuran list dapat bertambah atau berkurang sesuai kebutuhan tanpa harus menentukan ukuran tetap seperti pada array. Setiap node terdiri dari dua komponen, yaitu data yang menyimpan nilai dan pointer yang menyimpan alamat node berikutnya. Implementasi program menggunakan pointer karena lebih fleksibel dan efisien dalam mengelola hubungan antar node dibandingkan array. Dalam praktikum ini, dilakukan operasi dasar ADT Linked List, meliputi insert, delete, update, dan display, yang memungkinkan penambahan, penghapusan, pengubahan, dan penelusuran data dalam list secara terstruktur dan efisien.

## Guided

### soal 1

```cpp
#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

// Pointer awal dan akhir
Node* head = nullptr;

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}


void insertBelakang(int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Data " << data << " berhasil ditambahkan di belakang.\n";
}

void insertSetelah(int target, int dataBaru) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Data " << target << " tidak ditemukan!\n";
    } else {
        Node* newNode = createNode(dataBaru);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Data " << dataBaru << " berhasil disisipkan setelah " << target << ".\n";
    }
}

// ========== DELETE FUNCTION ==========
void hapusNode(int data) {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // Jika data di node pertama
    if (temp != nullptr && temp->data == data) {
        head = temp->next;
        delete temp;
        cout << "Data " << data << " berhasil dihapus.\n";
        return;
    }

    // Cari node yang akan dihapus
    while (temp != nullptr && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // Jika data tidak ditemukan
    if (temp == nullptr) {
        cout << "Data " << data << " tidak ditemukan!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Data " << data << " berhasil dihapus.\n";
}

// ========== UPDATE FUNCTION ==========
void updateNode(int dataLama, int dataBaru) {
    Node* temp = head;
    while (temp != nullptr && temp->data != dataLama) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Data " << dataLama << " tidak ditemukan!\n";
    } else {
        temp->data = dataBaru;
        cout << "Data " << dataLama << " berhasil diupdate menjadi " << dataBaru << ".\n";
    }
}

// ========== DISPLAY FUNCTION ==========
void tampilkanList() {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head;
    cout << "Isi Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// ========== MAIN PROGRAM ==========
int main() {
    int pilihan, data, target, dataBaru;

    do {
        cout << "\n=== MENU SINGLE LINKED LIST ===\n";
        cout << "1. Insert Depan\n";
        cout << "2. Insert Belakang\n";
        cout << "3. Insert Setelah\n";
        cout << "4. Hapus Data\n";
        cout << "5. Update Data\n";
        cout << "6. Tampilkan List\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                createNode(data);
                break;
            case 2:
                cout << "Masukkan data: ";
                cin >> data;
                insertBelakang(data);
                break;
            case 3:
                cout << "Masukkan data target: ";
                cin >> target;
                cout << "Masukkan data baru: ";
                cin >> dataBaru;
                insertSetelah(target, dataBaru);
                break;
            case 4:
                cout << "Masukkan data yang ingin dihapus: ";
                cin >> data;
                hapusNode(data);
                break;
            case 5:
                cout << "Masukkan data lama: ";
                cin >> data;
                cout << "Masukkan data baru: ";
                cin >> dataBaru;
                updateNode(data, dataBaru);
                break;
            case 6:
                tampilkanList();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
```
> Output
> ![foto](output/guided11.png)

Program di atas adalah implementasi Single Linked List dalam C++ yang memungkinkan pengguna untuk menambah, menghapus, memperbarui, dan menampilkan data secara dinamis. Struktur Node menyimpan data dan pointer ke node berikutnya. Fungsi seperti insertBelakang() dan insertSetelah() digunakan untuk menambahkan data di posisi tertentu, hapusNode() untuk menghapus data, updateNode() untuk mengubah nilai node, dan tampilkanList() untuk menampilkan seluruh isi linked list. Program ini menggunakan menu interaktif agar pengguna dapat memilih operasi yang ingin dilakukan sampai memilih keluar dari program.

## Unguided

### Soal 1

Buatlah single linked list untuk Antrian yang menyimpan data pembeli( nama dan pesanan). program memiliki beberapa menu seperti tambah antrian,  layani antrian(hapus), dan tampilkan antrian. \*antrian pertama harus yang pertama dilayani

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string pesanan;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

Node* createNode(string nama, string pesanan) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->pesanan = pesanan;
    newNode->next = nullptr;
    return newNode;
}

void tambahAntrian(string nama, string pesanan) {
    Node* newNode = createNode(nama, pesanan);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Pembeli " << nama << " dengan pesanan " << pesanan << " telah masuk antrian.\n";
}

void layaniAntrian() {
    if (front == nullptr) {
        cout << "Antrian kosong!\n";
        return;
    }
    Node* temp = front;
    cout << "Melayani pembeli: " << front->nama << " (Pesanan: " << front->pesanan << ")\n";
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete temp;
}

void tampilkanAntrian() {
    if (front == nullptr) {
        cout << "Antrian kosong!\n";
        return;
    }
    Node* temp = front;
    cout << "\n=== Daftar Antrian Pembeli ===\n";
    while (temp != nullptr) {
        cout << "- " << temp->nama << " (" << temp->pesanan << ")\n";
        temp = temp->next;
    }
}

int main() {
    int pilihan;
    string nama, pesanan;

    do {
        cout << "\n=== MENU ANTRIAN PEMBELI ===\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Layani Antrian\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama pembeli: ";
                cin >> nama;
                cout << "Masukkan pesanan: ";
                cin >> pesanan;
                tambahAntrian(nama, pesanan);
                break;
            case 2:
                layaniAntrian();
                break;
            case 3:
                tampilkanAntrian();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}

```

> Output
> ![foto](output/unguidedl1.png)

Program ini menggunakan Singly Linked List untuk mengelola antrian pembeli dengan operasi:

Tambah Antrian → menambahkan pembeli baru ke bagian belakang (fungsi tambahAntrian()).

Layani Antrian → menghapus pembeli dari bagian depan (fungsi layaniAntrian()), karena yang datang lebih dulu dilayani lebih dulu (FIFO).

Tampilkan Antrian → menampilkan seluruh antrian pembeli beserta pesanannya.

Program menggunakan pointer front dan rear untuk melacak awal dan akhir antrian, serta pointer next di setiap node untuk menghubungkan antar data.

### Soal 2

Buatlah program kode untuk membalik (reverse) singly linked list (1-2-3 menjadi 3-2-1) 

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertBelakang(int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void tampilkanList() {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }
    Node* temp = head;
    cout << "Isi Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void reverseList() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    cout << "Linked list berhasil dibalik!\n";
}

int main() {
    int pilihan, data;
    do {
        cout << "\n=== MENU LINKED LIST ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan List\n";
        cout << "3. Balikkan List\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                insertBelakang(data);
                break;
            case 2:
                tampilkanList();
                break;
            case 3:
                reverseList();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
    return 0;
}

```

> Output
> ![foto](output/unguided2.png)

Program ini membalik urutan node pada Singly Linked List, misalnya dari 1 -> 2 -> 3 menjadi 3 -> 2 -> 1.
Logika utamanya menggunakan tiga pointer:

prev untuk menyimpan node sebelumnya,

curr untuk node yang sedang diproses,

next untuk menyimpan node berikutnya sebelum arah pointer diubah.
Proses dilakukan dengan menukar arah pointer next setiap node hingga semua node dibalik, lalu head diarahkan ke node terakhir (yang sebelumnya menjadi ekor).


## Referensi

1. Ma’arif, A. (2020). Dasar Pemrograman C++. UAD Press. Diakses dari https://eprints.uad.ac.id/32726/1/Dasar%20Pemrograman%20Bahasa%20C%2B%2B.pdf

2. (Penulis tidak tertulis). (tahun tidak tertulis). Algoritma & Pemrograman C++ [PDF]. Repository Unpkediri. Diakses dari https://repository.unpkediri.ac.id/2468/1/55201_0701107802.pdf

# <h1 align="center">Laporan Praktikum Modul X <br> Nama Modul</h1>
<p align="center"> Harald Riandi Rantetana Purukan - 103112400130 </p>

## Dasar Teori

Doubly Linked List adalah jenis linked list di mana setiap elemen (atau node) memiliki dua penunjuk (successor). Penunjuk pertama, yang disebut next, akan menunjuk pada elemen sesudahnya. Penunjuk kedua, yang disebut prev, akan menunjuk pada elemen yang mendahuluinya (sebelumnya). Struktur elemen pada Doubly Linked List, yang dideklarasikan dengan tipe struct elmlist pada contoh, terdiri dari tiga komponen utama: info (data elemen), next (penunjuk ke elemen berikutnya), dan prev (penunjuk ke elemen sebelumnya).


Doubly Linked List juga memiliki dua penunjuk utama pada daftar (list) itu sendiri, yaitu first yang menunjuk ke elemen pertama dalam daftar, dan last yang menunjuk ke elemen terakhir. Keunggulan utama dari Doubly Linked List dibandingkan dengan Singly Linked List adalah kemudahan dalam mengakses elemen secara maju maupun mundur karena adanya penunjuk prev. Operasi dasar seperti penyisipan (Insert) dan penghapusan (Delete) elemen dapat dilakukan di awal (First), akhir (Last), atau di tengah daftar (After/Before), dengan memanfaatkan penunjuk first, last, next, dan prev untuk mengubah kaitan antar elemen.

## Guided

### soal 1

```cpp
#include <iostream>
using namespace std;

//struktur node

struct Node {
    int data;
    Node*prev;
    Node*next;
};

//pointer global

Node*head = nullptr;
Node*tail = nullptr;

//fungsi insert didepan

void insertDepan(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    } else {
        tail = newNode; //jika list kosong, tail juga menunjuk ke newNode
    }
    head = newNode; 
    cout << "Data " << data << " berhasil ditambahkan di depan.\n";
}

//fungsi insert setelah data tertentu

void insertSetelah(int target, int data) {
    Node* current = head;
    while (current != nullptr && current->data != target) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Data " << target << " tidak ditemukan.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = current;
    newNode->next = current->next;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    } else {
        tail = newNode; //jika menambahkan di akhir, update tail
    }
    current->next = newNode;
    cout << "Data " << data << " berhasil ditambahkan setelah " << target << ".\n";
}

// Fungsi: Insert Belakang
void insertBelakang(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode; // jika list kosong, head juga menunjuk ke newNode
    }
    tail = newNode;
    cout << "Data " << data << " berhasil ditambahkan di belakang.\n";
}

//fungsi hapus depan
void hapusDepan() {
    if (head == nullptr) {
        cout << "List kosong, tidak ada yang dihapus.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr; //jika list menjadi kosong, update tail
    }

    cout << "Data " << temp->data << " berhasil dihapus dari depan.\n";
    delete temp;
}

//fungsi hapus belakang

void hapusBelakang() {
    if (tail == nullptr) {
        cout << "List kosong, tidak ada yang dihapus.\n";
        return;
    }

    Node* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr; //jika list menjadi kosong, update head
    }

    cout << "Data " << temp->data << " berhasil dihapus dari belakang.\n";
    delete temp;
}

void hapusData(int target) {
    Node* current = head;
    while (current != nullptr && current->data != target) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Data " << target << " tidak ditemukan.\n";
        return;
    }

    if (current == head) {
        hapusDepan();
    } else if (current == tail) {
        hapusBelakang();
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        cout << "Data " << current->data << " berhasil dihapus.\n";
        delete current;
    }
}

void updateData(int oldData, int newData) {
    Node* current = head;
    while (current != nullptr && current->data != oldData)
        current = current->next;

    if (current == nullptr) {
        cout << "Data " << oldData << " tidak ditemukan.\n";
        return;
    }

    current->data = newData;
    cout << "Data " << oldData << " diubah menjadi " << newData << ".\n";
}

void tampilDepan() {
    if (head == nullptr) {
        cout << "List kosong.\n";
        return;
    }

    cout << "Isi list (dari depan): ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

// ====================================
// Fungsi: Tampilkan dari belakang
// ====================================
void tampilBelakang() {
    if (tail == nullptr) {
        cout << "List kosong.\n";
        return;
    }

    cout << "Isi list (dari belakang): ";
    Node* current = tail;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << "\n";
}

// ====================================
// MAIN PROGRAM (MENU INTERAKTIF)
// ====================================
int main() {
    int pilihan, data, target, oldData, newData;

    do {
        cout << "\n===== MENU DOUBLE LINKED LIST =====\n";
        cout << "1. Insert Depan\n";
        cout << "2. Insert Belakang\n";
        cout << "3. Insert Setelah Data\n";
        cout << "4. Hapus Depan\n";
        cout << "5. Hapus Belakang\n";
        cout << "6. Hapus Data Tertentu\n";
        cout << "7. Update Data\n";
        cout << "8. Tampil dari Depan\n";
        cout << "9. Tampil dari Belakang\n";
        cout << "0. Keluar\n";
        cout << "===================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                insertDepan(data);
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
                cin >> data;
                insertSetelah(target, data);
                break;
            case 4:
                hapusDepan();
                break;
            case 5:
                hapusBelakang();
                break;
            case 6:
                cout << "Masukkan data yang ingin dihapus: ";
                cin >> target;
                hapusData(target);
                break;
            case 7:
                cout << "Masukkan data lama: ";
                cin >> oldData;
                cout << "Masukkan data baru: ";
                cin >> newData;
                updateData(oldData, newData);
                break;
            case 8:
                tampilDepan();
                break;
            case 9:
                tampilBelakang();
                break;
            case 0:
                cout << "👋 Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}
```
> Output
> ![foto](guided1.png)

insertDepan(int data) → Menambahkan node baru di awal (depan) list dan menjadikannya head baru.

insertSetelah(int target, int data) → Menyisipkan node baru setelah node yang memiliki nilai target.

insertBelakang(int data) → Menambahkan node baru di akhir (belakang) list dan menjadikannya tail baru.

hapusDepan() → Menghapus node pertama (head) dari list.

hapusBelakang() → Menghapus node terakhir (tail) dari list.

hapusData(int target) → Menghapus node yang memiliki nilai data tertentu (target).

updateData(int oldData, int newData) → Mengubah nilai data lama (oldData) menjadi data baru (newData).

tampilDepan() → Menampilkan semua data dari arah depan ke belakang.

tampilBelakang() → Menampilkan semua data dari arah belakang ke depan.

## Unguided

### Soal 1

Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”: 

Type infotype : kendaraan < 
    nopol : string 
    warna : string 
    thnBuat : integer 
> 
Type address : pointer to ElmList 
Type ElmList < 
    info : infotype 
    next :address 
    prev : address 
> 
 
Type List < 
    First : address 
    Last : address 
> 
procedure CreateList( input/output L : List ) 
function alokasi( x : infotype ) → address 
procedure dealokasi(input/output P : address ) 
procedure printInfo( input L : List ) 
procedure insertLast(input/output L : List,  
   input P : address ) 
Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil 
implementasi ADT pada file “main.cpp”. 

### Soal 2

Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru. 
fungsi findElm( L : List, x : infotype ) : address 

### Soal 3

apus elemen dengan nomor polisi D003 dengan procedure delete. - 
procedure deleteFirst( input/output L : List,  
P : address ) - - 
procedure deleteLast( input/output L : List,  
P : address ) 
procedure deleteAfter( input Prec : address,  
input/output P : address )

### Kode Soal 1, 2 & 3

### doublylist.h
```h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <iostream>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// ====== DEKLARASI FUNGSI DAN PROSEDUR ======
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Fungsi baru:
address findElm(List L, infotype x);

// Prosedur delete
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif

```

### doublylist.cpp
```cpp
#include <iostream>
using namespace std;

//struktur node

struct Node {
    int data;
    Node*prev;
    Node*next;
};

//pointer global

Node*head = nullptr;
Node*tail = nullptr;

//fungsi insert didepan

void insertDepan(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    } else {
        tail = newNode; //jika list kosong, tail juga menunjuk ke newNode
    }
    head = newNode; 
    cout << "Data " << data << " berhasil ditambahkan di depan.\n";
}

//fungsi insert setelah data tertentu

void insertSetelah(int target, int data) {
    Node* current = head;
    while (current != nullptr && current->data != target) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Data " << target << " tidak ditemukan.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = current;
    newNode->next = current->next;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    } else {
        tail = newNode; //jika menambahkan di akhir, update tail
    }
    current->next = newNode;
    cout << "Data " << data << " berhasil ditambahkan setelah " << target << ".\n";
}

// Fungsi: Insert Belakang
void insertBelakang(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode; // jika list kosong, head juga menunjuk ke newNode
    }
    tail = newNode;
    cout << "Data " << data << " berhasil ditambahkan di belakang.\n";
}

//fungsi hapus depan
void hapusDepan() {
    if (head == nullptr) {
        cout << "List kosong, tidak ada yang dihapus.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr; //jika list menjadi kosong, update tail
    }

    cout << "Data " << temp->data << " berhasil dihapus dari depan.\n";
    delete temp;
}

//fungsi hapus belakang

void hapusBelakang() {
    if (tail == nullptr) {
        cout << "List kosong, tidak ada yang dihapus.\n";
        return;
    }

    Node* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr; //jika list menjadi kosong, update head
    }

    cout << "Data " << temp->data << " berhasil dihapus dari belakang.\n";
    delete temp;
}

void hapusData(int target) {
    Node* current = head;
    while (current != nullptr && current->data != target) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Data " << target << " tidak ditemukan.\n";
        return;
    }

    if (current == head) {
        hapusDepan();
    } else if (current == tail) {
        hapusBelakang();
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        cout << "Data " << current->data << " berhasil dihapus.\n";
        delete current;
    }
}

void updateData(int oldData, int newData) {
    Node* current = head;
    while (current != nullptr && current->data != oldData)
        current = current->next;

    if (current == nullptr) {
        cout << "Data " << oldData << " tidak ditemukan.\n";
        return;
    }

    current->data = newData;
    cout << "Data " << oldData << " diubah menjadi " << newData << ".\n";
}

void tampilDepan() {
    if (head == nullptr) {
        cout << "List kosong.\n";
        return;
    }

    cout << "Isi list (dari depan): ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

// ====================================
// Fungsi: Tampilkan dari belakang
// ====================================
void tampilBelakang() {
    if (tail == nullptr) {
        cout << "List kosong.\n";
        return;
    }

    cout << "Isi list (dari belakang): ";
    Node* current = tail;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << "\n";
}

// ====================================
// MAIN PROGRAM (MENU INTERAKTIF)
// ====================================
int main() {
    int pilihan, data, target, oldData, newData;

    do {
        cout << "\n===== MENU DOUBLE LINKED LIST =====\n";
        cout << "1. Insert Depan\n";
        cout << "2. Insert Belakang\n";
        cout << "3. Insert Setelah Data\n";
        cout << "4. Hapus Depan\n";
        cout << "5. Hapus Belakang\n";
        cout << "6. Hapus Data Tertentu\n";
        cout << "7. Update Data\n";
        cout << "8. Tampil dari Depan\n";
        cout << "9. Tampil dari Belakang\n";
        cout << "0. Keluar\n";
        cout << "===================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                insertDepan(data);
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
                cin >> data;
                insertSetelah(target, data);
                break;
            case 4:
                hapusDepan();
                break;
            case 5:
                hapusBelakang();
                break;
            case 6:
                cout << "Masukkan data yang ingin dihapus: ";
                cin >> target;
                hapusData(target);
                break;
            case 7:
                cout << "Masukkan data lama: ";
                cin >> oldData;
                cout << "Masukkan data baru: ";
                cin >> newData;
                updateData(oldData, newData);
                break;
            case 8:
                tampilDepan();
                break;
            case 9:
                tampilBelakang();
                break;
            case 0:
                cout << "👋 Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}
```

### main.cpp
```cpp
#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);
    infotype x;
    char lagi;

    do {
        cout << "Masukkan nomor polisi: ";
        cin >> x.nopol;
        if (findElm(L, x) != NULL) {
            cout << "Nomor polisi sudah terdaftar\n";
        } else {
            cout << "Masukkan warna kendaraan: ";
            cin >> x.warna;
            cout << "Masukkan tahun kendaraan: ";
            cin >> x.thnBuat;

            address P = alokasi(x);
            insertLast(L, P);
        }

        cout << "\nTambah data lagi? (y/n): ";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');

    // --- Hapus data berdasarkan nomor polisi ---
    string hapusNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    infotype hapusData;
    hapusData.nopol = hapusNopol;
    address PHapus = findElm(L, hapusData);

    if (PHapus != NULL) {
        if (PHapus == L.First) {
            deleteFirst(L, PHapus);
        } else if (PHapus == L.Last) {
            deleteLast(L, PHapus);
        } else {
            deleteAfter(PHapus->prev, PHapus);
        }
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus.\n";
    } else {
        cout << "Data dengan nomor polisi " << hapusNopol << " tidak ditemukan.\n";
    }

    // --- Cetak data list ---
    cout << "\nDATA LIST 1\n";
    printInfo(L);

    // --- Cari data berdasarkan nomor polisi ---
    string cariNopol;
    cout << "\nMasukkan Nomor Polisi yang dicari : ";
    cin >> cariNopol;

    infotype cariData;
    cariData.nopol = cariNopol;
    address PCari = findElm(L, cariData);

    if (PCari != NULL) {
        cout << "\nNomor Polisi : " << PCari->info.nopol << endl;
        cout << "Warna : " << PCari->info.warna << endl;
        cout << "Tahun : " << PCari->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cariNopol << " tidak ditemukan.\n";
    }

    return 0;
}
```

> Output
> ![foto](unguided1.png)
Terminal menampilkan proses input dan pengelolaan data kendaraan menggunakan struktur Doubly Linked List dalam program C++. Program berhasil menerima input data untuk dua kendaraan: R01 (Kuning, Tahun 25) dan R02 (Merah, Tahun 96). 

Program menampilkan DATA LIST 1 yang menunjukkan data dua kendaraan yang berhasil dimasukkan, yaitu R01 dan R02, membuktikan bahwa proses penambahan data awal telah selesai

> Output
> ![foto](unguided2.png)

Setelah data kendaraan (yang mencakup R01 dan R02 dari sesi sebelumnya) dimasukkan, pengguna memilih untuk menghapus nomor polisi R01. Program berhasil mengeksekusi perintah tersebut dan memberikan konfirmasi "Data dengan nomor polisi R01 berhasil dihapus." Sebagai hasilnya, DATA LIST 1 yang tersisa hanya menampilkan satu kendaraan, yaitu R02 (Warna Kuning, Tahun 23). Hal ini menunjukkan bahwa fungsi penghapusan pada Doubly Linked List telah sukses.

> Output
> ![foto](unguided3.png)

Pengguna memasukkan perintah untuk mencari nomor polisi: R02. Program berhasil menemukan dan menampilkan detail kendaraan tersebut, yaitu: Nomor Polisi R02, Warna Kuning, dan Tahun 23. Hasil ini konsisten dengan hasil pada terminal sebelumnya (gambar kedua), di mana R02 adalah satu-satunya data yang tersisa setelah R01 dihapus. Operasi ini mengonfirmasi bahwa fungsi pencarian (findList atau fungsi lain yang relevan) Anda berfungsi dengan baik dalam menemukan dan mengambil data dari list.

## Referensi

1. Ma’arif, A. (2020). Dasar Pemrograman C++. UAD Press. Diakses dari https://eprints.uad.ac.id/32726/1/Dasar%20Pemrograman%20Bahasa%20C%2B%2B.pdf

2. (Penulis tidak tertulis). (tahun tidak tertulis). Algoritma & Pemrograman C++ [PDF]. Repository Unpkediri. Diakses dari https://repository.unpkediri.ac.id/2468/1/55201_0701107802.pdf

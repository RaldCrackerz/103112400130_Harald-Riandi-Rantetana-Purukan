#include "Doublylist.h"

// Membuat list kosong
void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

// Alokasi node baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

// Dealokasi node
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Menampilkan semua data di list
void printInfo(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna : " << P->info.warna << endl;
        cout << "Tahun : " << P->info.thnBuat << endl;
        cout << endl;
        P = P->next;
    }
}

// Menambahkan elemen di akhir list
void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

// Mencari elemen berdasarkan nopol
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == x.nopol)
            return P;
        P = P->next;
    }
    return NULL;
}

// Menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        P = L.First;
        if (L.First == L.Last) { // hanya satu elemen
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.First = P->next;
            L.First->prev = NULL;
            P->next = NULL;
        }
    }
}

// Menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.Last != NULL) {
        P = L.Last;
        if (L.First == L.Last) { // hanya satu elemen
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.Last = P->prev;
            L.Last->next = NULL;
            P->prev = NULL;
        }
    }
}

// Menghapus elemen setelah Prec
void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL)
            P->next->prev = Prec;
        P->next = NULL;
        P->prev = NULL;
    }
}

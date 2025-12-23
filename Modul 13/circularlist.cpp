#include "circularlist.h"

void createList(List &L) {
    first(L) = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    info(P) = x;
    next(P) = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    if (first(L) == Nil) {
        first(L) = P;
        next(P) = P; // Circular: menunjuk diri sendiri
    } else {
        address last = first(L);
        // Mencari elemen terakhir (yang menunjuk ke First)
        while (next(last) != first(L)) {
            last = next(last);
        }
        next(P) = first(L);
        next(last) = P;
        first(L) = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != Nil) {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertLast(List &L, address P) {
    if (first(L) == Nil) {
        insertFirst(L, P);
    } else {
        address last = first(L);
        while (next(last) != first(L)) {
            last = next(last);
        }
        next(last) = P;
        next(P) = first(L);
    }
}

void deleteFirst(List &L, address &P) {
    P = first(L);
    if (first(L) != Nil) {
        if (next(first(L)) == first(L)) { // Satu elemen
            first(L) = Nil;
        } else {
            address last = first(L);
            while (next(last) != first(L)) {
                last = next(last);
            }
            first(L) = next(first(L));
            next(last) = first(L);
        }
        next(P) = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && next(Prec) != first(L)) { // Tidak menghapus First via deleteAfter biasa
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = Nil;
    } else if (Prec != Nil && next(Prec) == first(L)) {
        // Jika elemen yang akan dihapus adalah elemen yang kebetulan First (kasus khusus di circular)
        deleteFirst(L, P);
    }
}

void deleteLast(List &L, address &P) {
    if (first(L) != Nil) {
        address last = first(L);
        address precLast = Nil;
        
        // Loop sampai elemen terakhir
        while (next(last) != first(L)) {
            precLast = last;
            last = next(last);
        }
        
        P = last;
        if (precLast == Nil) { // Hanya 1 elemen
            first(L) = Nil;
        } else {
            next(precLast) = first(L);
        }
        next(P) = Nil;
    }
}

address findElm(List L, infotype x) {
    if (first(L) == Nil) return Nil;
    
    address P = first(L);
    do {
        if (info(P).nim == x.nim) {
            return P;
        }
        P = next(P);
    } while (P != first(L));
    
    return Nil;
}

void printInfo(List L) {
    if (first(L) == Nil) {
        cout << "List Kosong" << endl;
    } else {
        address P = first(L);
        do {
            cout << "Nama : " << info(P).nama << endl;
            cout << "NIM  : " << info(P).nim << endl;
            cout << "L/P  : " << info(P).jenis_kelamin << endl;
            cout << "IPK  : " << info(P).ipk << endl;
            cout << endl;
            P = next(P);
        } while (P != first(L));
    }
}
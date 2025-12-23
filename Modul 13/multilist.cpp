#include "multilist.h"

/********* pengecekan apakah list kosong ***********/
boolean ListEmpty(listinduk L) {
    return first(L) == Nil;
}

boolean ListEmptyAnak(listanak L) {
    return first(L) == Nil;
}

/********* pembuatan list kosong *********/
void CreateList(listinduk &L) {
    first(L) = Nil;
}

void CreateListAnak(listanak &L) {
    first(L) = Nil;
}

/********* manajemen memori *********/
address alokasi(infotypeinduk P) {
    address newNode = new elemeninduk;
    if (newNode != Nil) {
        info(newNode) = P;
        next(newNode) = Nil;
        CreateListAnak(child(newNode));
    }
    return newNode;
}

address_anak alokasiAnak(infotypeanak P) {
    address_anak newNode = new elemenanak;
    if (newNode != Nil) {
        info(newNode) = P;
        next(newNode) = Nil;
    }
    return newNode;
}

void dealokasi(address P) {
    delete P;
}

void dealokasiAnak(address_anak P) {
    delete P;
}

/********* pencarian sebuah elemen list *********/
address findElm(listinduk L, infotypeinduk X) {
    address P = first(L);
    while (P != Nil && info(P) != X) {
        P = next(P);
    }
    return P;
}

address_anak findElmAnak(listanak Lanak, infotypeanak X) {
    address_anak P = first(Lanak);
    while (P != Nil && info(P) != X) {
        P = next(P);
    }
    return P;
}

boolean fFindElm(listinduk L, address P) {
    address temp = first(L);
    while (temp != Nil) {
        if (temp == P) {
            return true;
        }
        temp = next(temp);
    }
    return false;
}

boolean fFindElmanak(listanak Lanak, address_anak P) {
    address_anak temp = first(Lanak);
    while (temp != Nil) {
        if (temp == P) {
            return true;
        }
        temp = next(temp);
    }
    return false;
}

address findBefore(listinduk L, address P) {
    address temp = first(L);
    if (temp == P) {
        return Nil;
    }
    while (temp != Nil && next(temp) != P) {
        temp = next(temp);
    }
    return temp;
}

address_anak findBeforeAnak(listanak Lanak, infotypeanak X, address_anak P) {
    address_anak temp = first(Lanak);
    if (temp == P) {
        return Nil;
    }
    while (temp != Nil && next(temp) != P) {
        temp = next(temp);
    }
    return temp;
}

/********* penambahan elemen **********/
void insertFirst(listinduk &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void insertAfter(listinduk &L, address P, address Prec) {
    next(P) = next(Prec);
    next(Prec) = P;
}

void insertLast(listinduk &L, address P) {
    if (ListEmpty(L)) {
        insertFirst(L, P);
    } else {
        address temp = first(L);
        while (next(temp) != Nil) {
            temp = next(temp);
        }
        next(temp) = P;
    }
}

void insertFirstAnak(listanak &L, address_anak P) {
    next(P) = first(L);
    first(L) = P;
}

void insertAfterAnak(listanak &L, address_anak P, address_anak Prec) {
    next(P) = next(Prec);
    next(Prec) = P;
}

void insertLastAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        insertFirstAnak(L, P);
    } else {
        address_anak temp = first(L);
        while (next(temp) != Nil) {
            temp = next(temp);
        }
        next(temp) = P;
    }
}

/********* penghapusan sebuah elemen *********/
void delFirst(listinduk &L, address &P) {
    P = first(L);
    if (P != Nil) {
        first(L) = next(P);
        next(P) = Nil;
    }
}

void delLast(listinduk &L, address &P) {
    if (!ListEmpty(L)) {
        if (next(first(L)) == Nil) {
            delFirst(L, P);
        } else {
            address temp = first(L);
            while (next(next(temp)) != Nil) {
                temp = next(temp);
            }
            P = next(temp);
            next(temp) = Nil;
        }
    }
}

void delAfter(listinduk &L, address &P, address Prec) {
    P = next(Prec);
    if (P != Nil) {
        next(Prec) = next(P);
        next(P) = Nil;
    }
}

void delP(listinduk &L, infotypeinduk X) {
    address P = findElm(L, X);
    if (P != Nil) {
        if (P == first(L)) {
            address temp;
            delFirst(L, temp);
            dealokasi(temp);
        } else {
            address Prec = findBefore(L, P);
            address temp;
            delAfter(L, temp, Prec);
            dealokasi(temp);
        }
    }
}

void delFirstAnak(listanak &L, address_anak &P) {
    P = first(L);
    if (P != Nil) {
        first(L) = next(P);
        next(P) = Nil;
    }
}

void delLastAnak(listanak &L, address_anak &P) {
    if (!ListEmptyAnak(L)) {
        if (next(first(L)) == Nil) {
            delFirstAnak(L, P);
        } else {
            address_anak temp = first(L);
            while (next(next(temp)) != Nil) {
                temp = next(temp);
            }
            P = next(temp);
            next(temp) = Nil;
        }
    }
}

void delAfterAnak(listanak &L, address_anak &P, address_anak Prec) {
    P = next(Prec);
    if (P != Nil) {
        next(Prec) = next(P);
        next(P) = Nil;
    }
}

void delPAnak(listanak &L, infotypeanak X) {
    address_anak P = findElmAnak(L, X);
    if (P != Nil) {
        if (P == first(L)) {
            address_anak temp;
            delFirstAnak(L, temp);
            dealokasiAnak(temp);
        } else {
            address_anak Prec = findBeforeAnak(L, X, P);
            address_anak temp;
            delAfterAnak(L, temp, Prec);
            dealokasiAnak(temp);
        }
    }
}

/********** proses semua elemen list *********/
void printInfo(listinduk L) {
    if (ListEmpty(L)) {
        cout << "List kosong" << endl;
    } else {
        address P = first(L);
        while (P != Nil) {
            cout << info(P);
            if (!ListEmptyAnak(child(P))) {
                cout << " -> ";
                printInfoAnak(child(P));
            }
            cout << endl;
            P = next(P);
        }
    }
}

int nbList(listinduk L) {
    int count = 0;
    address P = first(L);
    while (P != Nil) {
        count++;
        P = next(P);
    }
    return count;
}

void printInfoAnak(listanak Lanak) {
    address_anak P = first(Lanak);
    while (P != Nil) {
        cout << info(P);
        if (next(P) != Nil) {
            cout << ", ";
        }
        P = next(P);
    }
}

int nbListAnak(listanak Lanak) {
    int count = 0;
    address_anak P = first(Lanak);
    while (P != Nil) {
        count++;
        P = next(P);
    }
    return count;
}

/********** proses terhadap list **********/
void delAll(listinduk &L) {
    address P;
    while (!ListEmpty(L)) {
        delFirst(L, P);
        // Hapus semua child
        address_anak Panak;
        while (!ListEmptyAnak(child(P))) {
            delFirstAnak(child(P), Panak);
            dealokasiAnak(Panak);
        }
        dealokasi(P);
    }
}
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
#include <string>
using namespace std;

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define child(P) (P)->child

typedef bool boolean;
typedef string infotypeinduk;
typedef string infotypeanak;

// Struktur untuk list anak
struct elemenanak {
    infotypeanak info;
    elemenanak* next;
};
typedef elemenanak* address_anak;

struct listanak {
    address_anak first;
};

// Struktur untuk list induk
struct elemeninduk {
    infotypeinduk info;
    listanak child;
    elemeninduk* next;
};
typedef elemeninduk* address;

struct listinduk {
    address first;
};

typedef listinduk list;

/********* pengecekan apakah list kosong ***********/
boolean ListEmpty(listinduk L);
boolean ListEmptyAnak(listanak L);

/********* pembuatan list kosong *********/
void CreateList(listinduk &L);
void CreateListAnak(listanak &L);

/********* manajemen memori *********/
address alokasi(infotypeinduk P);
address_anak alokasiAnak(infotypeanak P);
void dealokasi(address P);
void dealokasiAnak(address_anak P);

/********* pencarian sebuah elemen list *********/
address findElm(listinduk L, infotypeinduk X);
address_anak findElmAnak(listanak Lanak, infotypeanak X);
boolean fFindElm(listinduk L, address P);
boolean fFindElmanak(listanak Lanak, address_anak P);
address findBefore(listinduk L, address P);
address_anak findBeforeAnak(listanak Lanak, infotypeanak X, address_anak P);

/********* penambahan elemen **********/
void insertFirst(listinduk &L, address P);
void insertAfter(listinduk &L, address P, address Prec);
void insertLast(listinduk &L, address P);
void insertFirstAnak(listanak &L, address_anak P);
void insertAfterAnak(listanak &L, address_anak P, address_anak Prec);
void insertLastAnak(listanak &L, address_anak P);

/********* penghapusan sebuah elemen *********/
void delFirst(listinduk &L, address &P);
void delLast(listinduk &L, address &P);
void delAfter(listinduk &L, address &P, address Prec);
void delP(listinduk &L, infotypeinduk X);
void delFirstAnak(listanak &L, address_anak &P);
void delLastAnak(listanak &L, address_anak &P);
void delAfterAnak(listanak &L, address_anak &P, address_anak Prec);
void delPAnak(listanak &L, infotypeanak X);

/********** proses semua elemen list *********/
void printInfo(listinduk L);
int nbList(listinduk L);
void printInfoAnak(listanak Lanak);
int nbListAnak(listanak Lanak);

/********** proses terhadap list **********/
void delAll(listinduk &L);

#endif
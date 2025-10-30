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
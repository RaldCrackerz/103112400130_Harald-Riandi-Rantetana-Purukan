#include "multilist.h"

int main() {
    listinduk L;
    address P;
    address_anak Panak;
    
    cout << "========================================" << endl;
    cout << "   PROGRAM MULTI LINKED LIST" << endl;
    cout << "========================================" << endl;
    
    // 1. Membuat list kosong
    cout << "\n1. Membuat list kosong..." << endl;
    CreateList(L);
    cout << "   Status list: " << (ListEmpty(L) ? "KOSONG" : "TIDAK KOSONG") << endl;
    
    // 2. Insert parent nodes
    cout << "\n2. Menambahkan parent nodes..." << endl;
    P = alokasi("Fakultas Teknik");
    insertFirst(L, P);
    cout << "   - Ditambahkan: Fakultas Teknik" << endl;
    
    P = alokasi("Fakultas Ekonomi");
    insertLast(L, P);
    cout << "   - Ditambahkan: Fakultas Ekonomi" << endl;
    
    P = alokasi("Fakultas Kedokteran");
    insertLast(L, P);
    cout << "   - Ditambahkan: Fakultas Kedokteran" << endl;
    
    cout << "\n   Jumlah parent: " << nbList(L) << endl;
    cout << "   Isi list:" << endl;
    printInfo(L);
    
    // 3. Insert child nodes untuk Fakultas Teknik
    cout << "\n3. Menambahkan child nodes untuk Fakultas Teknik..." << endl;
    address parentTeknik = findElm(L, "Fakultas Teknik");
    if (parentTeknik != Nil) {
        Panak = alokasiAnak("Teknik Informatika");
        insertFirstAnak(child(parentTeknik), Panak);
        cout << "   - Ditambahkan: Teknik Informatika" << endl;
        
        Panak = alokasiAnak("Teknik Elektro");
        insertLastAnak(child(parentTeknik), Panak);
        cout << "   - Ditambahkan: Teknik Elektro" << endl;
        
        Panak = alokasiAnak("Teknik Sipil");
        insertLastAnak(child(parentTeknik), Panak);
        cout << "   - Ditambahkan: Teknik Sipil" << endl;
    }
    
    // 4. Insert child nodes untuk Fakultas Ekonomi
    cout << "\n4. Menambahkan child nodes untuk Fakultas Ekonomi..." << endl;
    address parentEkonomi = findElm(L, "Fakultas Ekonomi");
    if (parentEkonomi != Nil) {
        Panak = alokasiAnak("Manajemen");
        insertFirstAnak(child(parentEkonomi), Panak);
        cout << "   - Ditambahkan: Manajemen" << endl;
        
        Panak = alokasiAnak("Akuntansi");
        insertLastAnak(child(parentEkonomi), Panak);
        cout << "   - Ditambahkan: Akuntansi" << endl;
    }
    
    // 5. Insert child nodes untuk Fakultas Kedokteran
    cout << "\n5. Menambahkan child nodes untuk Fakultas Kedokteran..." << endl;
    address parentKedokteran = findElm(L, "Fakultas Kedokteran");
    if (parentKedokteran != Nil) {
        Panak = alokasiAnak("Pendidikan Dokter");
        insertFirstAnak(child(parentKedokteran), Panak);
        cout << "   - Ditambahkan: Pendidikan Dokter" << endl;
        
        Panak = alokasiAnak("Keperawatan");
        insertLastAnak(child(parentKedokteran), Panak);
        cout << "   - Ditambahkan: Keperawatan" << endl;
    }
    
    // 6. Tampilkan semua data
    cout << "\n6. Menampilkan seluruh struktur list:" << endl;
    cout << "========================================" << endl;
    printInfo(L);
    
    // 7. Pencarian elemen
    cout << "\n7. Mencari elemen..." << endl;
    address searchParent = findElm(L, "Fakultas Ekonomi");
    if (searchParent != Nil) {
        cout << "   - Parent 'Fakultas Ekonomi' DITEMUKAN" << endl;
        cout << "     Jumlah child: " << nbListAnak(child(searchParent)) << endl;
    }
    
    address_anak searchChild = findElmAnak(child(parentTeknik), "Teknik Informatika");
    if (searchChild != Nil) {
        cout << "   - Child 'Teknik Informatika' DITEMUKAN di Fakultas Teknik" << endl;
    }
    
    // 8. Hapus child tertentu
    cout << "\n8. Menghapus child 'Teknik Elektro' dari Fakultas Teknik..." << endl;
    delPAnak(child(parentTeknik), "Teknik Elektro");
    cout << "   Struktur setelah penghapusan:" << endl;
    printInfo(L);
    
    // 9. Hapus parent tertentu
    cout << "\n9. Menghapus parent 'Fakultas Kedokteran'..." << endl;
    // Hapus semua child dulu
    while (!ListEmptyAnak(child(parentKedokteran))) {
        delFirstAnak(child(parentKedokteran), Panak);
        dealokasiAnak(Panak);
    }
    delP(L, "Fakultas Kedokteran");
    cout << "   Struktur setelah penghapusan:" << endl;
    printInfo(L);
    
    // 10. Statistik akhir
    cout << "\n10. Statistik akhir:" << endl;
    cout << "    Total parent: " << nbList(L) << endl;
    address Ptemp = first(L);
    while (Ptemp != Nil) {
        cout << "    - " << info(Ptemp) << ": " 
             << nbListAnak(child(Ptemp)) << " child" << endl;
        Ptemp = next(Ptemp);
    }
    
    // 11. Hapus semua elemen
    cout << "\n11. Menghapus semua elemen..." << endl;
    delAll(L);
    cout << "    Status list: " << (ListEmpty(L) ? "KOSONG" : "TIDAK KOSONG") << endl;
    
    cout << "\n========================================" << endl;
    cout << "   PROGRAM SELESAI" << endl;
    cout << "========================================" << endl;
    
    return 0;
}
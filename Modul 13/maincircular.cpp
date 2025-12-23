#include <iostream>
#include "circularlist.h"

using namespace std;

// Fungsi helper sesuai permintaan soal
address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    address P;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    P = alokasi(x);
    return P;
}

int main() {
    List L;
    address P1 = Nil;
    address P2 = Nil;
    infotype x;

    createList(L);
    
    cout << "coba insert first, last, dan after" << endl;
    
    // 1. Insert Danu (04)
    P1 = createData("Danu", "04", 'l', 4.0);
    insertFirst(L, P1);
    
    // 2. Insert Fahmi (06) -> [Danu, Fahmi]
    P1 = createData("Fahmi", "06", 'l', 3.45);
    insertLast(L, P1);
    
    // 3. Insert Bobi (02) -> [Bobi, Danu, Fahmi]
    P1 = createData("Bobi", "02", 'l', 3.71);
    insertFirst(L, P1);
    
    // 4. Insert Ali (01) -> [Ali, Bobi, Danu, Fahmi]
    P1 = createData("Ali", "01", 'l', 3.3);
    insertFirst(L, P1);
    
    // 5. Insert Gita (07) -> [Ali, Bobi, Danu, Fahmi, Gita]
    P1 = createData("Gita", "07", 'p', 3.75);
    insertLast(L, P1);
    
    // 6. Insert Cindi (03). 
    // Agar urut seperti gambar, Cindi harus setelah Bobi (02).
    // Di soal tertulis find "07", tapi diganti "02" agar sesuai gambar output.
    x.nim = "02"; // CORRECTED from "07" to "02" to match image output
    P1 = findElm(L, x);
    P2 = createData("Cindi", "03", 'p', 3.5);
    if (P1 != Nil) insertAfter(L, P1, P2);
    
    // 7. Insert Hilmi (08).
    // Agar urut seperti gambar, Hilmi harus setelah Gita (07).
    // Di soal tertulis find "02", tapi diganti "07" agar sesuai gambar output.
    x.nim = "07"; // CORRECTED from "02" to "07" to match image output
    P1 = findElm(L, x);
    P2 = createData("Hilmi", "08", 'l', 3.3); // 'l' asumsi laki-laki (di gambar '1' atau 'l')
    if (P1 != Nil) insertAfter(L, P1, P2);
    
    // 8. Insert Eli (05).
    // Eli setelah Danu (04). Ini sudah benar sesuai soal.
    x.nim = "04"; 
    P1 = findElm(L, x);
    P2 = createData("Eli", "05", 'p', 3.4);
    if (P1 != Nil) insertAfter(L, P1, P2);
    
    printInfo(L);
    
    return 0;
}
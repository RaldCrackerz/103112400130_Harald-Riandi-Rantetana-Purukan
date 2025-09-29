#include <iostream>
using namespace std;

// Array untuk menyimpan kata-kata angka
string satuan[] = {"", "Satu", "Dua", "Tiga", "Empat", "Lima", 
                   "Enam", "Tujuh", "Delapan", "Sembilan"};
string belasan[] = {"Sepuluh", "Sebelas", "Dua Belas", "Tiga Belas", "Empat Belas",
                    "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas"};
string puluhan[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", "Lima Puluh",
                    "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};

// Fungsi untuk mengubah angka ke tulisan
string angkaToTulisan(int n) {
    if (n == 0) return "Nol";         // Kasus khusus
    if (n == 100) return "Seratus";   // Kasus khusus

    if (n < 10) {
        return satuan[n];             // 1–9
    } 
    else if (n < 20) {
        return belasan[n - 10];       // 10–19
    } 
    else {
        int p = n / 10;               // Ambil puluhan
        int s = n % 10;               // Ambil satuan
        if (s == 0) return puluhan[p]; 
        else return puluhan[p] + " " + satuan[s]; // Gabungan
    }
}

int main() {
    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan!" << endl;
    } else {
        cout << angka << " : " << angkaToTulisan(angka) << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

// Prosedur untuk mengkuadratkan nilai dengan call by reference
void kuadratkan(int &x) {
    x = x * x; // Nilai asli diubah menjadi kuadratnya
}

int main() {
    int angka = 5;

    cout << "Nilai awal: " << angka << endl;

    // Memanggil prosedur dengan referensi
    kuadratkan(angka);

    cout << "Nilai setelah dikuadratkan: " << angka << endl;

    return 0;
}

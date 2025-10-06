#include <iostream>
using namespace std;

int main() {
    // Inisialisasi matriks awal 3x3
    int matriks[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Menyimpan hasil transpose
    int transpose[3][3];

    // Melakukan transpose (baris jadi kolom, kolom jadi baris)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            transpose[j][i] = matriks[i][j];
        }
    }

    // Menampilkan matriks awal
    cout << "Matriks Awal:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    // Menampilkan hasil transpose
    cout << "\nMatriks Hasil Transpose:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

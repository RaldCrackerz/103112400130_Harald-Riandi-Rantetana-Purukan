#include <iostream>
using namespace std;

// Fungsi untuk menampilkan isi array 2D 3x3
void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk menukar isi dua array 2D pada posisi tertentu
void tukarElemen(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

// Fungsi untuk menukar nilai yang ditunjuk oleh dua pointer integer
void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int *p1, *p2;
    p1 = &A[0][0]; // pointer menunjuk elemen pertama A
    p2 = &B[0][0]; // pointer menunjuk elemen pertama B

    cout << "Array A awal:\n";
    tampilArray(A);

    cout << "\nArray B awal:\n";
    tampilArray(B);

    // Tukar isi array di posisi tertentu, misal posisi [1][2]
    tukarElemen(A, B, 1, 2);

    cout << "\nSetelah tukar posisi [1][2]:\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "Array B:\n";
    tampilArray(B);

    // Tukar nilai yang ditunjuk pointer
    cout << "\nSebelum tukar pointer: *p1 = " << *p1 << ", *p2 = " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "Sesudah tukar pointer: *p1 = " << *p1 << ", *p2 = " << *p2 << endl;

    return 0;
}


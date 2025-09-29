#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan nilai n: ";
    cin >> n;
    cout << "output :" << endl;
    for (int i = 0; i <= n; i++) {
        
        for (int s = 0; s < i; s++) {
            cout << "  ";
        }

        for (int j = n - i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "*";

        // cetak menaik
        for (int k = 1; k <= n - i; k++) {
            cout << " " << k;
        }

        cout << endl;
    }

    return 0;
}

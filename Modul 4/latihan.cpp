#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan data buku
struct Book {
    string isbn;
    string title;
    string author;
    Book* next;
};

class BookList {
private:
    Book* head;

public:
    BookList() {
        head = NULL;
    }

    // Fungsi untuk menambah buku baru (di akhir list)
    void addBook(string isbn, string title, string author) {
        Book* newBook = new Book();
        newBook->isbn = isbn;
        newBook->title = title;
        newBook->author = author;
        newBook->next = NULL;

        if (head == NULL) {
            head = newBook;
        } else {
            Book* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newBook;
        }
        cout << "Buku berhasil ditambahkan!\n";
    }

    // Fungsi untuk menghapus buku berdasarkan ISBN
    void deleteBook(string isbn) {
        if (head == NULL) {
            cout << "List buku kosong!\n";
            return;
        }

        Book* temp = head;
        Book* prev = NULL;

        // Jika buku yang dihapus ada di head
        if (temp != NULL && temp->isbn == isbn) {
            head = temp->next;
            delete temp;
            cout << "Buku berhasil dihapus!\n";
            return;
        }

        // Mencari buku yang akan dihapus
        while (temp != NULL && temp->isbn != isbn) {
            prev = temp;
            temp = temp->next;
        }

        // Jika ISBN tidak ditemukan
        if (temp == NULL) {
            cout << "Buku dengan ISBN " << isbn << " tidak ditemukan!\n";
            return;
        }

        // Menghapus buku
        prev->next = temp->next;
        delete temp;
        cout << "Buku berhasil dihapus!\n";
    }

    // Fungsi untuk memperbarui data buku
    void updateBook(string isbn, string newTitle, string newAuthor) {
        Book* temp = head;
        while (temp != NULL) {
            if (temp->isbn == isbn) {
                temp->title = newTitle;
                temp->author = newAuthor;
                cout << "Data buku berhasil diperbarui!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Buku dengan ISBN " << isbn << " tidak ditemukan!\n";
    }

    // Fungsi untuk menampilkan semua buku
    void displayBooks() {
        if (head == NULL) {
            cout << "List buku kosong!\n";
            return;
        }

        Book* temp = head;
        cout << "\nDaftar Buku:\n";
        while (temp != NULL) {
            cout << "ISBN: " << temp->isbn << endl;
            cout << "Judul: " << temp->title << endl;
            cout << "Penulis: " << temp->author << endl;
            cout << "------------------------\n";
            temp = temp->next;
        }
    }
};

int main() {
    BookList library;
    int choice;
    string isbn, title, author;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Hapus Buku\n";
        cout << "3. Update Buku\n";
        cout << "4. Tampilkan Semua Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Masukkan ISBN: ";
                getline(cin, isbn);
                cout << "Masukkan Judul: ";
                getline(cin, title);
                cout << "Masukkan Penulis: ";
                getline(cin, author);
                library.addBook(isbn, title, author);
                break;

            case 2:
                cout << "Masukkan ISBN buku yang akan dihapus: ";
                getline(cin, isbn);
                library.deleteBook(isbn);
                break;

            case 3:
                cout << "Masukkan ISBN buku yang akan diupdate: ";
                getline(cin, isbn);
                cout << "Masukkan Judul baru: ";
                getline(cin, title);
                cout << "Masukkan Penulis baru: ";
                getline(cin, author);
                library.updateBook(isbn, title, author);
                break;

            case 4:
                library.displayBooks();
                break;

            case 5:
                cout << "Program selesai!\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 5);

    return 0;
}
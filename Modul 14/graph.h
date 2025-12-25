#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue> // Diperlukan untuk antrian BFS
using namespace std;

// --- Definisi Tipe Data ---
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;        // 0 = belum, 1 = sudah
    adrEdge firstEdge;  // Pointer ke edge pertama (tetangga)
    adrNode next;       // Pointer ke node berikutnya dalam daftar node
};

struct ElmEdge {
    adrNode node;       // Node tujuan yang ditunjuk oleh edge ini
    adrEdge next;       // Pointer ke edge berikutnya
};

struct Graph {
    adrNode first;      // Pointer ke node pertama dalam graph
};

// --- Prototipe Prosedur & Fungsi ---

// Membuat graph kosong
void createGraph(Graph &G);

// Menambahkan Node baru ke dalam Graph
void insertNode(Graph &G, infoGraph X);

// Menghubungkan dua Node (Undirected: A ke B dan B ke A)
void connectNode(adrNode N1, adrNode N2);

// Mencetak isi Graph (Adjacency List)
void printInfoGraph(Graph G);

// Fungsi bantuan: Mencari alamat Node berdasarkan infonya (char)
adrNode findNode(Graph G, infoGraph X);

// --- Penelusuran (Traversal) ---

// Menampilkan hasil penelusuran Depth First Search
void PrintDFS(Graph G, adrNode N);

// Menampilkan hasil penelusuran Breadth First Search
void PrintBFS(Graph G, adrNode N);

#endif
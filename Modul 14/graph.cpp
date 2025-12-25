#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

void insertNode(Graph &G, infoGraph X) {
    // Alokasi Node Baru
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;

    // Insert Last (Agar urutan node A, B, C.. terjaga saat diprint)
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

// UPDATE: Menggunakan Insert Last agar urutan tetangga sesuai input (A -> B dulu, baru C)
void connectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        
        // 1. Sambungkan N1 ke N2 (Insert Last di list edge N1)
        adrEdge E1 = new ElmEdge;
        E1->node = N2;
        E1->next = NULL;
        
        if (N1->firstEdge == NULL) {
            N1->firstEdge = E1;
        } else {
            adrEdge t = N1->firstEdge;
            while (t->next != NULL) {
                t = t->next;
            }
            t->next = E1;
        }

        // 2. Sambungkan N2 ke N1 (Insert Last di list edge N2)
        adrEdge E2 = new ElmEdge;
        E2->node = N1;
        E2->next = NULL;

        if (N2->firstEdge == NULL) {
            N2->firstEdge = E2;
        } else {
            adrEdge t = N2->firstEdge;
            while (t->next != NULL) {
                t = t->next;
            }
            t->next = E2;
        }
    }
}

void printInfoGraph(Graph G) {
    adrNode P = G.first;
    if (P == NULL) {
        cout << "Graph kosong." << endl;
        return;
    }

    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

// --- Helper untuk mereset status visited ---
void resetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

// --- Helper Rekursif untuk DFS ---
void dfsRecursive(adrNode N) {
    if (N == NULL) return;

    // 1. Tandai visited dan cetak
    N->visited = 1;
    cout << N->info << " ";

    // 2. Kunjungi semua tetangga
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        // Jika tetangga belum dikunjungi, lakukan DFS ke sana
        if (E->node->visited == 0) {
            dfsRecursive(E->node);
        }
        E = E->next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    resetVisited(G); // Pastikan status bersih sebelum mulai
    if (N != NULL) {
        cout << "DFS Traversal: ";
        dfsRecursive(N);
        cout << endl;
    }
}

void PrintBFS(Graph G, adrNode N) {
    resetVisited(G); // Pastikan status bersih sebelum mulai
    if (N == NULL) return;

    cout << "BFS Traversal: ";
    
    // Siapkan Queue
    queue<adrNode> Q;
    
    // Masukkan node awal
    Q.push(N);
    N->visited = 1;

    while (!Q.empty()) {
        // Ambil node dari antrian
        adrNode current = Q.front();
        Q.pop();
        
        cout << current->info << " ";

        // Cek semua tetangga
        adrEdge E = current->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1; // Tandai saat masuk antrian
                Q.push(E->node);
            }
            E = E->next;
        }
    }
    cout << endl;
}
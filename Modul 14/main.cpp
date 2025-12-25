#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    adrNode A = findNode(G, 'A');
    adrNode B = findNode(G, 'B');
    adrNode C = findNode(G, 'C');
    adrNode D = findNode(G, 'D');
    adrNode E = findNode(G, 'E');
    adrNode F = findNode(G, 'F');
    adrNode G_node = findNode(G, 'G');
    adrNode H = findNode(G, 'H');

    connectNode(A, B);
    connectNode(A, C); 

    connectNode(B, D);
    connectNode(B, E);

    connectNode(C, F);
    connectNode(C, G_node);

    connectNode(D, H);
    connectNode(E, H);
    connectNode(F, H);
    connectNode(G_node, H);

    cout << "=== Adjacency List (Sekarang urut abjad) ===" << endl;
    printInfoGraph(G);
    cout << endl;

    cout << "=== BFS (Breadth First Search) ===" << endl;
    PrintBFS(G, A); 

    cout << "=== DFS (Depth First Search) ===" << endl;
    PrintDFS(G, A);

    return 0;
}